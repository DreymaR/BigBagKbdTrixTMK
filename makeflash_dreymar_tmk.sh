#!/bin/bash

## =======================================================================
## ===     MakeFlash_TMK.sh for DreymaR's Hasu TMK modifications       ===
## ===            by Øystein Bech "DreymaR" Gadmar, 2016-              ===
## =======================================================================

HeadStr="DreymaR's Big Bag Of Tricks for TMK controllers (by GadOE, 2018-01)"
DescStr=\
"Shell script to make a .hex file for a USB-USB converter device\n"\
"  or other TMK-compatible keyboard translator microcontroller\n"\
"  using GeekHack user Hasu's TMK keyboard controller toolkit,\n"\
"  and optionally flashing it onto the chip using DFU-programmer.\n"\
"  With -a it installs the required AVR tools for Linux.\n"\
"  With -g it installs Git, then the TMK code (~120 Mb) from GitHub.\n"
#"\e[1m  NB: Make sure those two are done before compiling! ;-)\e[0m\n"
FootStr="Happy TMK hacking! ~ Øystein Bech 'DreymaR' Gadmar"

##-------------- init ------------------------------------------

# MyDATE=`date +"%Y-%m-%d_%H-%M"`
MyNAME=$(basename "$0")
MyDIR_=$(dirname "$0")
MyPATH="$( cd "${MyDIR_}" ; pwd -P )" # An elaborate but robust way of finding a full path
MyHOME="$( cd "${MyDIR_}"/.. ; pwd -P )" # The script's mother directory (in case of symlinks)
TMKDir='tmk_keyboard'             # (--) The name of the TMK root dir
#DreDir="dreymar_tmk"              # (--) The directory with DreymaR's TMK files
MyMaps="${MyPATH}/_myunimaps"     # (--) The subdirectory with DreymaR's Unimap keymap files
MyHxBk="${MyPATH}/_myhexfiles"    # (--) Optional directory for .hex file backup
MkeDir='converter/usb_usb'        # (-d) The default directory from which to run makefile
MkeFil='Makefile.unimap'          # (-m) Makefile name; Target (see below) is found in it
BldHex='yes'                      # (-b) Build a new .hex file? (On by default)
RunDFU='no'                       # (-f) Flash to device using DFU?
MClean='no'                       # (-c) Just make clean (to remove all generated files), then quit?
InsAVR='no'                       # (-a) Install required AVR tools, then quit?
InsTMK='no'                       # (-g) Install TMK_keyboard from GitHub, then quit?
MyChipDef='atmega32u4'            # (-n) Device name (for DFU-programmer only; may be detected instead)
TargetDef='tmk_makeflash'         # (-t) Name of resulting .hex file (may be detected in a Makefile)
ConsEnabl='no'                    # (--) Value of CONSOLE_ENABLE ('no' saves memory; 'yes' for debug)
KeyMap='dreymar'                  # (--) Layout file to use, "keymap_${KeyMap}.c"
## NOTE: '# (-a)' means that the value can be set by option argument '-a <value>'
## NOTE: To use the keymap.c file with this script, copy/rename it to, e.g., keymap_all.c first

HelpStr="\e[1mUsage: bash ${MyNAME} [optional args] <keymap file>\e[0m\n"\
"       Runs from within the tmk_keyboard dir or a dir beside it.\n"\
"==============================================================\n"\
"[-#] Functionality                   - 'default'  \n"\
"==============================================================\n"\
"[-d] <directory for build/flash>     - '${MkeDir}'\n"\
"[-m] <Makefile name>                 - '${MkeFil}'\n"\
"[-b] Build .hex file using make?     - '${BldHex}'\n"\
"[-f] Flash to device using DFU?      - '${RunDFU}'\n"\
"[-c] Cleanup only (no build/flash)?  - '${MClean}'\n"\
"[-a] Install AVR Tools?              - '${InsAVR}'\n"\
"[-g] Install TMK from GitHub?        - '${InsTMK}'\n"\
"[--] (default keymap filename)       - '${KeyMap}'\n"\
"\n"\
"Requires: - Atmel AVR Toolchain (gcc-avr avr-libc) for compiler,\n"\
"          - dfu-programmer for flashing (or use, e.g., FLIP on Windows)\n"\
"          - USB-USB device in bootloader mode, properly mounted\n"
## NOTE: dfu-util & gcc-arm-none-eabi are not needed here; only for flashing ARM processors
#"[-n] <chip device name>              - '${MyChip}'\n"\
#"[-t] <.hex filename>                 - '${Target}'\n"\

##-------------- functions and line parser ---------------------

MyMsg()    ## Formatted output: last arg is printf 'style[;fgcolor[;bgcolor]]'
{
    ## Style: 0-Off, 1-Bold, 4-Underscore, 5-Blink, 7-Reverse, 8-Concealed
    ## Color: (3#/4# FG/BG): 0-Black, 1-Red, 2-Green, 3-Yellow, 4-Blue, 5-Magenta, 6-Cyan, 7-White
    printf "\n\e[${3:-1;32;40}m@@@ $1 @@@\e[0m\n$2"    # default: Bold green on black
}

PrintHelpAndExit()
{
    MyMsg "${HeadStr}" "\n"
    printf "${DescStr}\n"
    printf "${HelpStr}"
    MyMsg "${FootStr}" "\n"
    exit $1
}

MyEcho()
{
    printf "$1\n"
    [ -z "$2" ] || printf "$1\n" >> "$2"
}

MyPoint()
{
    MyEcho "\e[1;32m¤ \e[0m$@"    # Bold green
}

MyWarning()
{
    MyMsg "WARNING: ${@:-'Beware of nargles!'}" "\n" '1;36;44'    # Bold cyan on blue
#~    exit 1
}

MyError()
{
    MyMsg "$MyNAME - ERROR: ${@:-'Undefined error'}" "\n" '1;37;41'    # Bold white on red
    exit 1
}

MyCD()
{
    OldDir=`pwd` # May also use 'cd -' or cd $OLDPWD to get back! Or pushd/popd.
    NewDir=${1:-`pwd`}
    cd ${NewDir} \
        && MyPoint "Changed dir to '${NewDir}'" || MyError "Change to '${NewDir}' failed"
}

MyYesNo() {
    ## Call with a prompt string or use a default. Formatted output (bold green/cyan text).
    printf "\e[1;32m¤ \e[1;36m${1:-Are you sure?} [y/N] \e[0m" >&2
#    read -r -p "${1:-Are you sure?}" yesnoresponse
    read -r yesnoresponse
    case "$yesnoresponse" in
        [yY][eE][sS]|[yY])      true    ;;
        *)                      false   ;;
    esac
}

MyFindValue() {
    ## Find an assigned value in a set of files, if any
    ## (at the end of the first found line starting with '<$1>')
    local Detected
    for file in ${2}; do
        Detected=$(less "${file}" | awk "/^${1}/ "'{gsub(/\r$/,""); print $NF}' 2>&1)
        #echo "Detected: '$Detected'" >&2
        [ -n "${Detected}" ] && break
    done
    echo "${Detected}"
}

# if [ "$#" == 0 ]; then PrintHelpAndExit 2; fi # No args
while getopts "d:m:n:t:bfcagh?" cmdarg; do
    case $cmdarg in
        d)      MkeDir="$OPTARG"        ;;
        m)      MkeFil="$OPTARG"        ;;
        n)      MyChip="$OPTARG"        ;;
        t)      Target="$OPTARG"        ;;
        b)      BldHex='no'             ;;
        f)      RunDFU='yes'            ;;
        c)      MClean='yes'            ;;
        a)      InsAVR='yes'            ;;
        g)      InsTMK='yes'            ;;
        h|\?)   PrintHelpAndExit 0      ;;
        :)      PrintHelpAndExit 1      ;;
    esac
done
LastArg=${@:$OPTIND:1} # Get the remaining (positional) arg
KeyMap=${LastArg:=$KeyMap} # If LastArg is non-empty, use it

##-------------- main ------------------------------------------
# [[ $() ]] && MyWarning "True" || MyWarning "False"    # Debug
# MyError "DEBUG! Value: '${MyPATH}'. "                 # Debug

MyMsg "$HeadStr"

## Install needed tools (AVR and DFU-programmer)
if [ ${InsAVR} == 'yes' ]; then
    MyPoint "Installing AVR tools, make and dfu-programmer:"
    for item in "avr-libc binutils-avr gcc-avr make dfu-programmer"; do
        sudo apt-get install $item \
            && MyPoint "Installed: $item" || MyError "Installing $item failed"
    done
    exit 0
fi

## NOTE: The makeflash script should be placed either within the main tmk_keyboard dir,
##       or in a dir located within or beside the main tmk dir.
##       The _myhexfiles and _myunimaps dirs should be beside the script.

cd "${MyPATH}"    # Start out in the script's dir no matter where it's run from
if [ -d "${MyHOME}/../${TMKDir}" ]; then # The script may be in a dir within the TMK dir
    TMKDir="$( dirname "${MyHOME}" )/${TMKDir}"
#elif [ -d "${MyHOME}/${TMKDir}" ]; then # The script may be directly within the TMK dir
#    TMKDir="${MyHOME}/${TMKDir}" # it's unsafe to use MyPATH because of symlinks?
else # Place or find the TMK dir one level above the script's dir
    TMKDir="${MyHOME}/${TMKDir}"
fi

## Install Git, TMK and DreymaR's TMK files (or just update these)
if [ ${InsTMK} == 'yes' ]; then
    if $(hash 'git' 2>/dev/null); then
        MyPoint "The git command is already present."
    else
        MyPoint "Installing Git:"
        sudo apt-get install 'git' || MyError "Installing Git failed"
    fi
    if [ -w "${TMKDir}" ]; then
        MyPoint "TMK install found. Now updating TMK:"
        MyCD "${TMKDir}"
#        git submodule update --remote
        git pull \
                && MyPoint "TMK update done" || MyError "TMK update failed"
    else
        MyPoint "Installing TMK in '${TMKDir}':"
        if $(MyYesNo 'This install is ~120 Mb or more - are you sure?'); then
            MyCD "${MyHOME}"
            git clone git://github.com/tmk/tmk_keyboard.git || MyError "TMK cloning failed"
            MyCD "${TMKDir}"
            git submodule init
            git submodule update \
                && MyPoint "TMK initialized" || MyError "TMK initialization failed"
        else
            MyPoint "TMK install deferred"
        fi
    fi
## NOTE: I used to copy my files into the TMK dir; this is no longer the default but still works.
#    MyPoint "Copying DreymaR's files to local TMK subdirs:"
#    if [ -d "${DreDir}" ]; then
#        cp -rL "${DreDir}"/* "${TMKDir}" || MyError "DreymaR file copy failed"
#    elif [ -d "../${DreDir}" ]; then
#        cp -rL "../${DreDir}"/* "${TMKDir}" || MyError "DreymaR file copy failed"
#    else
#        MyWarning "DreymaR's dir '${DreDir}' not found"
#    fi
    exit 0
fi

MyCD "${TMKDir}/${MkeDir%/}"

MyCleaner()
{
    #MyLog=''; LogTo='/dev/stdout'; MyLogTxt=''
    #MyLog='make_clean_log.txt'; LogTo="${MyLog}"; MyLogTxt=" Output in '${MyLog}'"
    MyPoint "Running ${MkeFil} clean to remove build files:" >&2
    MyWarning "This may take a little while! ;-)" >&2
    rm make_*_log.txt &>/dev/null
    make -f ${MkeFil} clean >/dev/null \
        && MyPoint "Make clean done." >&2 || MyError "Make clean failed" >&2
}

if [ ${MClean} == 'yes' ]; then
    MyCleaner
    exit 0
fi

## Sometimes the makefile includes a second makefile; if so, find this.
## Then, try to find the Target (TARGET) and MyChip (MCU) values in these makefiles, unless set manually.
Makefiles="${MkeFil} `MyFindValue 'include ' "${MkeFil}"`"
MyPoint "Makefile(s) used: '${Makefiles}'"
if [ -z "${Target}" ]; then
    FindIt=`MyFindValue 'TARGET [\?]?=' "${Makefiles}"` ; Target=${FindIt:-$TargetDef}
fi
#MyPoint "Target file name: ${Target}.hex"
if [ -z "${MyChip}" ]; then
    FindIt=`MyFindValue 'MCU [\?]?=' "${Makefiles}"`     ; MyChip=${FindIt:-$MyChipDef}
fi
MyPoint "Chip name used: ${MyChip}"
#MyError "DEBUG! FindIt='${FindIt}', Target='${Target}'"

## Build .hex file using make. If using unimap, create links to common files as necessary.
## Also cleanup before build and, if .hex file is backed up, ask to cleanup after build.
## NOTE: Sending TARGET_DIR=". ${MyMaps}" to see unimap files didn't work for me.
if [ ${BldHex} == 'yes' ]; then
    ## If using Unimap, the files may be in my unimap folder (common for all architectures)
    if [[ "${Target}" =~ 'unimap' ]]; then  # Using Unimap
        if [ -f "unimap_${KeyMap}.c" ] && [ -f "unimap_${KeyMap}.h" ]; then
            MyPoint "Unimap files or links 'unimap_${KeyMap}(.c/.h)' found locally."
        elif [ -d "${MyMaps}" ]; then
                MyPoint "Unimap folder '${MyMaps}' found, but no local files/links."
                if $(MyYesNo 'Do you wish to link to these unimap files?'); then
                    ln -s "${MyMaps}"/* .
                else
                    MyError "Cannot build without unimap source files"
                fi
        else
            MyError "No unimap folder nor source files found"
        fi
    fi
    if $(MyYesNo 'Do you wish to output to stdout instead of a log file?'); then
        MyLog=''; LogTo='/dev/stdout'; MyLogTxt=''
    else
        MyLog='make_build_log.txt'; LogTo="${MyLog}"
        MyLogTxt=" Output in '${MyLog}'; showing the last lines below:"
        #MyLog=''; LogTo='/dev/null'; MyLogTxt=''
    fi
    [ -d "obj_${Target}" ] && MyCleaner \
        || MyPoint "Cleanup not needed (found no 'obj_${Target}' dir)"
    MyPoint "Running 'make KEYMAP=${KeyMap} CONSOLE_ENABLE=${ConsEnabl}' to create '${Target}.hex':"
    MyWarning "This may take a while!"
    make -f ${MkeFil} KEYMAP=$KeyMap  CONSOLE_ENABLE=$ConsEnabl >${LogTo} \
        && MyPoint "Make KEYMAP=${KeyMap} done.${MyLogTxt}" || MyError "Make failed"
    [ -n "${MyLog}" ] && tail --lines=7 "${MyLog}" | head --lines=5
    MyPoint "Looking for backup dir '${MyHxBk}'..."
    if [ -w "${MyHxBk}" ]; then
        cp "${Target}.hex" "${MyHxBk}" \
            && MyPoint "Backup of '${Target}.hex' successful" \
            || MyWarning "Backup of '${Target}.hex' failed"
        if $(MyYesNo 'Do you wish to keep the build files (required if no backup)?'); then
            MyPoint "Cleanup deferred"
        else
            MyCleaner
        fi
    else
        MyPoint "Writeable backup folder not found, hence no .hex copy"
    fi
fi

## Flash .hex file to device (must be set in bootloader mode!) using DFU-programmer
if [ ${RunDFU} == 'yes' ]; then
    MyPoint "Flashing device with DFU-programmer:"
    ## The simplest way to flash is 'sudo make dfu'. I use the long way to avoid sudo make:
    # sudo make -f ${MkeFil} KEYMAP=$KeyMap dfu
    ## Check whether dfu-programmer can access the USB device - if it can't, try it w/ sudo:
    [ "`dfu-programmer $MyChip get bootloader-version 2>/dev/null`" ] \
        && DoSudo='' || DoSudo='sudo'
    ## The dfu-programmer command has slightly different syntax depending on version:
    [[ `dfu-programmer --version 2>&1 | awk '{print $2}'` > '0.7' ]] \
        && UseForce='--force' || UseForce=''
    $DoSudo dfu-programmer $MyChip erase $UseForce    || MyError "$MyChip init/erase failed"
    $DoSudo dfu-programmer $MyChip flash "${Target}.hex"    || MyError "$MyChip flashing failed"
    $DoSudo dfu-programmer $MyChip reset \
        && MyPoint "DFU flashing ${MyChip} done" || MyError "${MyChip} reset failed"
fi

#MyCD "${OldDir}"
MyMsg "${MyNAME} finished!"
exit 0

##-------------- misc ------------------------------------------

## NOTE: To avoid sudo make for flashing the USB-2-USB, put this into /etc/udev/rules.d/50-atmel-dfu.rules:
#~ # Atmel ATMega32U4
#~ SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff4", MODE:="0666"

## Below is sample preprocessor code for selecting code snippets. Useful for, e.g., keymap files.
## NOTE: This is for C/C++, not shell script!

#define WHICHONE 1
#define WHICHSUB 2
#if WHICHONE == 0
    # code option 0
#elif WHICHONE == 1
# if WHICHSUB == 1
    # code option 1-1
# if WHICHSUB == 2
    # code option 1-2
# else
    # code option 1 default
# endif
#endif /* if WHICHONE */

#define DOTHIS
#ifdef DOTHIS
    # code
#else
    # other code
#endif /* ifdef DOTHIS */

#ifndef DONETHIS
#define DONETHIS
    # code
#endif /* ifndef DONETHIS */

#!/bin/bash

# Usage:
#
# -o:   Deletes the config at '~/.config/dwm' if exists and copies my 
#       config to that route. It makes a backup.
# 
# -r:   Only makes a cp -r src/* '~/.config/dwm/'. This command does not
#       make any backup.
#
# -i:   Checks if '~/.config/dwm' exists. Only copies my config to that
#       path if the mentioned path dont exists. If everything is fine, 
#       compiles and installs dwm.
#       
# -h:   Shows this message.                                                     by: @dpv927
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Define some output colors
reset='\033[0m'
red='\033[1;31m'
green='\033[1;32m'
yellow='\033[1;33m'

# Define dwm working directory
CONFIG_DIR="${HOME}/.config"
DWM_DIR="${CONFIG}/dwm"

function perror() {
    printf "${red}Error:${reset} %s\n" "${1}"
}
function pwarning() {
    printf "${yellow}Warning:${reset} %s\n" "${1}"
}
function pinfo() {
    printf "${green}Info:${reset} %s\n" "${1}"
}
function buildconfig() {
    cd ${DWM_DIR}
    pinfo "Compiling and installing dwm..."
    make clean install || perror "Something went wrong" && exit 1

    # Dwm was successfully installed
    pinfo "Dwm has been installed"
}

# Check if args > 0
if [ $# -eq 0 ]; then
  perror "At least one argument is required"
  exit 1
fi

# Define the args flags
override="-o"
rewrite="-r"
install="-i"
help="-h"
# End of args

if [ ${1} == "${override}" ]; then

    # Make a backup if neccesary
    if [ -d "${DWM_DIR}" ]; then
        # Create a backup folder if ~/.config/dwm already exists
        pwarning "The directory ${DWM_DIR} already exists...Creating a backup."
        BACKUP_DIR="${CONFIG_DIR}/dwm.backup-$(date +%Y.%m.%d-%H%M)"

        # Try to make the backup dir and notify the user if the
        # process failed
        mv ${DWM_DIR} ${BACKUP_DIR} || perror "Something went wrong" && exit 1
        pinfo "Successfully created a backup at ${BACKUP_DIR}."
    else
        # There is no dwm config directory
        pwarning "The directory ${DWM_DIR} dont exists...Creating ${DWM_DIR}"
        mkdir -p ${DWM_DIR}
    fi

    # Now we want to copy all the config from src/ to ~/.config/dwm
    pinfo "Copiying all the files from ./src/ to ${DWM_DIR}"
    cp -r src/* ${DWM_DIR} || perror "Something went wrong" && exit 1

    # Everying looks fine.
    pinfo "The script has finished...exiting"

elif [ ${1} == "${rewrite}" ]; then

    if ! [ -d "${DWM_DIR}" ]; then
        # There is no dwm config directory
        pwarning "The directory ${DWM_DIR} dont exists...Creating ${DWM_DIR}"
        mkdir -p ${DWM_DIR}
    fi

    # Copy all the files without hesitation
    pinfo "Rewriting the config at ${DWM_DIR}"
    cp -r src/* ${DWM_DIR} || perror "somnething went wrong" || exit 1

    # Everying looks fine.
    pinfo "The script has finished...exiting"

elif [ ${1} == "${install}" ]; then

    if ! [ -d "${DWM_DIR}" ]; then
        # Cannot install if ~/.config/dwm exists
        perror "The directory ${DWM_DIR} already exists...Exiting"
        exit 1
    else
        pinfo "Creating the directory ${DWM_DIR}"
        mkdir -p ${DWM_DIR}
    fi

    # Copy all the files
    pinfo "Installing the config at ${DWM_DIR}"
    cp -r src/* ${DWM_DIR} || perror "somnething went wrong" || exit 1

    # Build all
    buildconfig

elif [ ${1} == ${help} ]; then
    # just print the help file
    cat usage.txt || perror "The help file has been deleted"
else
    perror "Unrecognized option '${1}'"
fi
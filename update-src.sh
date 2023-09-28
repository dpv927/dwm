#!/bin/bash

# This script is not designed for an external user to use,
# but for the repository developers.
#
# The utility of this script is to update the contents of the 
# src/ folder in the current directory, so that commits can be
# made later.
#                                                     by: @dpv927
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Get the script path
spath="$(readlink -f "$0")"
sdir="$(dirname "$spath")"

# Define dwm working directories
DWM_DIR="${HOME}/.config/dwm"
GIT_DIR="${sdir}/src"

# Update repo files
rm -rf "${GIT_DIR}/*"
cp -r "${DWM_DIR}/*" "${GIT_DIR}/"

# Show changes
git status

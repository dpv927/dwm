#!/bin/bash

# Define dwm working directories
DWM_DIR="${HOME}/.config/dwm"
GIT_DIR="$(pwd)"

# Update repo files
rm -rf "${GIT_DIR}/dwm"
cp -r "${DWM_DIR}" "${GIT_DIR}"

# Show changes
git status
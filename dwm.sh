#!/bin/bash

# Define dwm working directories
DWM_DIR="${HOME}/.config/dwm"
GIT_DIR="$(pwd)"

# Update repo files
cp -r "${DWM_DIR}" "${GIT_DIR}"

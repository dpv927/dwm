#!/bin/bash
# by @dpv927

DWM_DIR="${HOME}/.config/dwm";
WALLPAPER_DIR="${DWM_DIR}/resources"
CONFIG_DIR="${DWM_DIR}/config"
SCRIPTS_DIR="${DWM_DIR}/scripts"

# Restore wallpaper
feh --no-fehbg --bg-fill "${WALLPAPER_DIR}/wallpaper.png"

# Load X settings
killall xsettingsd
xsettingsd --config="${CONFIG_DIR}/xsettingsd" &
xrdb -merge ~/.Xresources

# Start dwm bar utils
sh "${SCRIPTS_DIR}/bar.sh" &

# Start picom compositor
picom &

# Start dwm
while type dwm >/dev/null; do
    dwm && continue || break;
done

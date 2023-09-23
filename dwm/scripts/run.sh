#!/bin/bash
# by @dpv927

# Kill applications if already running
killall -9 xsettingsd

# Restore wallpapper
feh --no-fehbg --bg-fill "$HOME/Pictures/dwm_layers.png"

# Load X settings
xsettingsd --config="$HOME/.config/dwm/config/xsettingsd" &
xrdb -merge ~/.Xresources

# Start dwm bar utils
sh "$HOME/.config/dwm/scripts/dwm-bar/dwm_bar.sh" &

# Start dwm
while type dwm >/dev/null; do dwm && continue || break; done

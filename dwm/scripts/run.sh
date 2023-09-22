#!/bin/bash
# by @dpv927

# Kill applications if already running
killall -9 xsettingsd

# Restore wallpapper
feh --no-fehbg --bg-fill "$HOME/Pictures/XeroCatppuccin4K.png"

# Load X settings
xsettingsd --config="$HOME/.config/dwm/config/xsettingsd" &
xrdb -merge ~/.Xresources

# Start dwm
dwm

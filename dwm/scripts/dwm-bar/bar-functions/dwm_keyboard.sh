#!/bin/sh

# A dwm_bar function that displays the current keyboard layout
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: xorg-setxkbmap

dwm_keyboard () {
    printf "%s" "$SEP1"
    printf " %s" "$(setxkbmap -query | awk '/layout/{print $2}')"
    printf "%s\n" "$SEP2"
}

dwm_keyboard

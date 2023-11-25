#!/bin/bash

# Variables declaration
IFACE=$(route | grep 'default' | head -n1 | awk '{print $8}')
SCRIPT_DIR=".config/dwm/scripts"
SEP="   "
SEP2=" "
# End of variables

# Color variables declaration
black="#101318"
red="#e06b74"
green="#74ba81"
yellow="#efca84"
magenta="#c58af0"
reset="#c6d0f5"
# End of color variables

function get_hour() {
    # Prints the current hour and minutes
    printf "%s^c${red}^󰥔 ^c${reset}^ %s\n" "${SEP}" "$(date "+%T")"
}

function get_keyboard() {
    # Prints keyboard layout
    printf "^c${magenta}^󰌌 ^c${reset}^%s\n" "$(setxkbmap -query | awk '/layout/{print $2}')"
}

function get_netstate() {
    # Prints the current state of the used net interface
    # Modes: up - down
    printf "%s" "${SEP}"
    case "$(cat /sys/class/net/${IFACE}/operstate 2>/dev/null)" in
	up) printf "^c${green}^󱊪 ^c${reset}^ ${IFACE}: up\n" ;;
	down) printf "^c${red}^󰌙 ^c${reset}^ ${IFACE}: down\n" ;;
	esac
}

function get_cpusage() {
	local CPU=$(top -bn1 | grep 'Cpu' | awk '{print $2}')%
  printf "%s^c${magenta}^󰍛 ^c${reset}^ %s\n" "${SEP}" "${CPU}"
}

function get_ramusage() {
  local free_out=$(free -h | grep 'Mem')
  local MEMUSED=$(echo ${free_out} | awk '{print $3}')
	local MEMTOT=$(echo ${free_out} | awk '{print $2}')
  local MEMPER=$(python ${SCRIPT_DIR}/div.py $MEMUSED $MEMTOT)%

  printf "%s^c${green}^ ^c${reset}^ %s (%s)\n" "${SEP}" "${MEMUSED}" "${MEMPER}"
}

function get_kernel() {
    # Prints the current version of the system kernel
    printf "%s^c${yellow}^ ^c${reset}^%s\n" "${SEP}" "$(uname -a | cut -d ' ' -f3)"
}

function get_netraffic() {
    local output=$(python ${SCRIPT_DIR}/net.py)
    printf "%s%s\n" "${SEP}" "${output}"
}

function get_battery () {
    local bat=$(cat /sys/class/power_supply/BAT0/capacity)%
    printf "%s^c$magenta^ ^c$reset^%s\n" "${SEP}" "${bat}"
}

while true
do
    upperbar=""
    upperbar="$upperbar$(get_keyboard)"
    upperbar="$upperbar$(get_netstate)"    
    upperbar="$upperbar$(get_netraffic)"
    upperbar="$upperbar$(get_ramusage)"
    upperbar="$upperbar$(get_cpusage)"
    upperbar="$upperbar$(get_kernel)"
    upperbar="$upperbar$(get_hour)"
    upperbar="$upperbar${SEP2}"
    xsetroot -name "$upperbar"
    sleep 1
done

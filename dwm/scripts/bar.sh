#!/bin/bash

# Variables declaration
IFACE=$(route | grep 'default' | head -n1 | awk '{print $8}')
SCRIPT_DIR=".config/dwm/scripts"
SEP=" | "
# End of vriables

function get_hour() {
    # Prints the current hour and minutes
    printf "%s %s\n" "${SEP}" "$(date "+%T")"
}

function get_keyboard() {
    # Prints keyboard layout
    printf "%s %s\n" "${SEP}" "$(setxkbmap -query | awk '/layout/{print $2}')"
}

function get_netstate() {
    # Prints the current state of the used net interface
    # Modes: up - down
    printf "%s" "${SEP}"
    case "$(cat /sys/class/net/${IFACE}/operstate 2>/dev/null)" in
	up) printf "󱊪 ${IFACE}: up\n" ;;
	down) printf "󰌙 ${IFACE}: down\n" ;;
	esac
}

function get_cpusage() {
	local CPU=$(top -bn1 | grep 'Cpu' | awk '{print $2}')%
  printf "%s󰍛 %s\n" "${SEP}" "${CPU}"
}

function get_ramusage() {
  local free_out=$(free -h | grep 'Mem')
  local MEMUSED=$(echo ${free_out} | awk '{print $3}')
	local MEMTOT=$(echo ${free_out} | awk '{print $2}')
  local MEMPER=$(python ${SCRIPT_DIR}/div.py $MEMUSED $MEMTOT)%

  printf "%s %s (%s)\n" "${SEP}" "${MEMUSED}" "${MEMPER}"
}

function get_kernel() {
    # Prints the current version of the system kernel
    printf "%s %s\n" "${SEP}" "$(uname -a | cut -d ' ' -f3)"
}

function get_netraffic() {
    local output=$(python ${SCRIPT_DIR}/net.py)
    printf "%s%s\n" "${SEP}" "${output}"
}

while true
do
    upperbar=""
    #upperbar="$upperbar$(get_keyboard)"
    #upperbar="$upperbar$(get_netstate)"    
    upperbar="$upperbar$(get_netraffic)"
    upperbar="$upperbar$(get_ramusage)"
    upperbar="$upperbar$(get_cpusage)"
    upperbar="$upperbar$(get_kernel)"
    upperbar="$upperbar$(get_hour)"

    xsetroot -name "$upperbar"
    sleep 1
done

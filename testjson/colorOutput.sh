#!/bin/sh
val=$1
case $val in
    white)
        echo "\e[1;41m\e[1;37mThe Color is $val and it is in red background \e[0m";;
    red)
        echo "\e[1;31mThe Color is $val \e[0m";;
    green)
        echo "\e[1;32mThe Color is $val \e[0m";;
    blue)
        echo "\e[1;34mThe Color is $val \e[0m";;
    cyan)
        echo "\e[1;36mThe Color is $val \e[0m";;
    magenta)
        echo "\e[1;35mThe Color is $val \e[0m";;
    yellow)
        echo "\e[1;33mThe Color is $val \e[0m";;
    black)
        echo "\e[1;47m\e[1;30mThe Color is $val and it is in white background \e[0m";;
esac

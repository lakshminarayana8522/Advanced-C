#!/bin/sh

# switch case example

echo -n "Enter number: "
read number

case $number in
	1) echo "in case 1"
	;;

	2) echo "in case 2"
	;;

	*)echo "unknown case "
	;;

esac



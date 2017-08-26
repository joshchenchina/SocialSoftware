#!/bin/bash
clear
echo "Welcome to the Monster Hunter's Datbase Creation tool."
read -p "What would you like the table to be called? : " TABLENAME
read -p "How many columns do you want in your table? : " TABLENUM
while ! [[ "$TABLENUM" =~ ^[0-9]+$ ]]
	do
	echo "\nThat was not a valid number, try again."
	read -p "How many columns do you want in your table? : " TABLENUM
done
INFO="create table "$TABLENAME"("
SEGMENT1=""
SEGMENT2=""
for i in `seq 1 $TABLENUM`; do
	if [[ $i -ne 1 ]]
	then
		INFO=$INFO", "
	fi
	echo "Column $i"
	read -p "	Col Name : " SEGMENT1
	read -p "	Col Type : " SEGMENT2
	echo
	INFO=$INFO$SEGMENT1" "$SEGMENT2
done
INFO=$INFO")"
echo "Execute command ... $INFO"
read -p "y/n : " RESPO
if [ "$RESPO" = "y" ]
then 
	sqlite3 $TABLENAME.sql "$INFO"
fi

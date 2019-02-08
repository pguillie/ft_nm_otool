#!/bin/bash

FAIL=FAILED_TESTS

function cmp_file
{
	echo -n $1 ": "
	if [[ ! -x $1 ]]
	then
		echo -n "(not exe) "
	fi
	./ft_nm -j $1 > mine 2>log
	nm -j $1 2>/dev/null > real
	diff mine real 2>&1 >/dev/null
	if [[ $? -eq 0 ]]
	then
		echo $'\e[32mOK\e[0m'
	else
		echo $'\e[31mko...\e[0m'
		echo >> $FAIL
		echo "==== $1 ====" >> $FAIL
		echo "(ft_nm, nm)" >> $FAIL
		diff mine real >> $FAIL
	fi
	rm mine real
}

function rec
{
	if [[ -f $1 ]]
	then
		cmp_file $1
	elif [[ -d $1 ]]
	then
		for file in `ls $1`
		do
			rec $1/$file
		done
	else
		echo "error: $1: invalid file"
	fi
}

if [[ -z $1 ]]
then
	echo "please give an arg"
else
	rm -f $FAIL
	for arg in "$@"
	do
		rec $arg
	done
fi

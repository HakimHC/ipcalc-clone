#! /bin/bash

make test -C ../.. 

gcc main.c -I ../../include -I ../../libft/inc ../../test.a -o test

function test {
	diff <(./test $1 $2 $3 $4) <(readarray -t <<< "$5")
	if [[ $? -ne 0 ]]; then
		echo ko
	else
		echo ok
	fi
}

expected=("A B 0 0")
test "A" "B" "" "" "$expected"

rm test

#! /bin/bash

function test {
	diff <(./test "A" "B") <(readarray -t < "$1")
}

expected=("A B 0 0")
./test $expected

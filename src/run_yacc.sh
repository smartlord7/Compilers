#!/bin/bash

compiler_name='gocompiler'
test_cases='../yacc_test_cases/*.dgo'
in_ext='.dgo'
out_ext='.out'

lex $compiler_name.l
yacc -d -v gocompiler.y
cc -o gocompiler.out y.tab.c lex.yy.c util/token_type.c util/error_handling.c

for test_case in $test_cases
do
	echo -e "Running test case ${test_case}"
	echo "----------------------------------------------------"
	./gocompiler.out < $test_case > ${test_case//${in_ext}/${out_ext}}
	# cat "${test_case//${in_ext}/${out_ext}}"
	diff "${test_case//${in_ext}/${out_ext}}" "${test_case::-3}out"
	echo -e ""
	echo "----------------------------------------------------"
done

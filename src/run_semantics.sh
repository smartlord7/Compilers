#!/bin/bash

compiler_name='gocompiler'
test_cases='tests/meta3/*.dgo'
in_ext='.dgo'
out_ext='.out'

lex $compiler_name.l
yacc -d -v gocompiler.y
cc -o gocompiler.out y.tab.c lex.yy.c token_type.c error_handling.c abstract_syntax_tree.c linked_list.c symbol_entry.c tables.c data_types.c -g

for test_case in $test_cases
do
	echo -e "Running test case ${test_case}"
	echo "----------------------------------------------------"
	./gocompiler.out < $test_case > "${test_case//${in_ext}/${out_ext}}"
	#cat "${test_case//${in_ext}/${out_ext}}"
	diff "${test_case//${in_ext}/${out_ext}}" "${test_case::-3}out"
	echo -e ""
	echo "----------------------------------------------------"
done

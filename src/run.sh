compiler_name='gocompiler'
test_cases='../test_cases/*.in'
in_ext='.in'
out_ext='.out'

lex $compiler_name.l
clang -o  $compiler_name lex.yy.c util/token_type.c util/error_handling.c -g

for test_case in $test_cases
do
	echo -e "Running test case ${test_case}"
	echo "----------------------------------------------------"
	./gocompiler $1 < $test_case > "${test_case//${in_ext}/${out_ext}}"
	cat "${test_case//${in_ext}/${out_ext}}"
	echo -e ""
	echo "----------------------------------------------------"
done
yacc -d -v gocompiler.y
cc -o gocompiler.out y.tab.c lex.yy.c util/token_type.c util/error_handling.c

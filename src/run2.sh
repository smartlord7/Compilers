compiler_name='gocompiler'
test_cases='../test_cases/*.dgo'
in_ext='.dgo'
out_ext='.out'

lex $compiler_name.l
clang-9 -o $compiler_name lex.yy.c -g

for test_case in $test_cases
do
	echo -e "Running test case ${test_case}"
	echo "----------------------------------------------------"
	./gocompiler < $test_case > "${test_case//${in_ext}/${out_ext}}"
	#cat "${test_case//${in_ext}/${out_ext}}"
	diff "${test_case//${in_ext}/${out_ext}}" "${test_case::-3}out"
	echo -e ""
	echo "----------------------------------------------------"
done
yacc -d -v gocompiler.y

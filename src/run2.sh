compiler_name='gocompiler'
test_cases='../test_cases/*.in'
in_ext='in'
out_ext='out'

lex $compiler_name.l
clang-9 -o $compiler_name lex.yy.c

for test_case in $test_cases
do
	echo -e "Running test case ${test_case}"
	echo "----------------------------------------------------"
	./gocompiler < $test_case > "${test_case//${in_ext}/${out_ext}}"
	cat "${test_case//${in_ext}/${out_ext}}"
	echo -e ""
	echo "----------------------------------------------------"
done


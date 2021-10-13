compiler_name='gocompiler'
test_cases='../test_cases/*.in'
in_ext='in'
out_ext='out'

lex $compiler_name.l
clang -o $compiler_name lex.yy.c

for test_case in $test_cases
do
	echo "Running test case ${test_case}..."
	./gocompiler < $test_case > "${test_case//${in_ext}/${out_ext}}"
done

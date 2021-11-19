#!/bin/bash

compiler_name='gocompiler'
test_cases='../yacc_test_cases/*.dgo'
in_ext='.dgo'
out_ext='.out'

lex $compiler_name.l
yacc -d -v -t gocompiler.y
cc -o gocompiler.out y.tab.c lex.yy.c util/token_type.c util/error_handling.c

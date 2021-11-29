#!/bin/bash

compiler_name='gocompiler'
test_cases='yacc_test_cases/*.dgo'
in_ext='.dgo'
out_ext='.out'

lex $compiler_name.l
yacc -d -v gocompiler.y
cc -o gocompiler.out y.tab.c lex.yy.c token_type.c error_handling.c abstract_syntax_tree.c linked_list.c symbol_entry.c tables.c

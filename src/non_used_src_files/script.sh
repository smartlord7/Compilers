lex gocompiler.l
yacc -d -v gocompiler.y
clang -o gocompiler y.tab.c lex.yy.c token_type.c error_handling.c abstract_syntax_tree.c linked_list.c
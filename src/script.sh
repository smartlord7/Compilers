lex gocompiler.l
yacc -d -v gocompiler.y
clang -o gocompiler y.tab.c lex.yy.c util/token_type.c util/error_handling.c data_structures/abstract_syntax_tree.c data_structures/linked_list.c
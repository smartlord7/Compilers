%{
	#include <stdlib.h>
	#include <stdio.h>
%}

whitespaces		\r|\n|\t|\f|" "
other			.


%%

{whitespaces}		{;}
{other}		{;}


%%

int main(int argc, char * argv[]) {
	
	return EXIT_SUCCESS;
}

int yywrap() {

	return 1;
}


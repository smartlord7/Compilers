#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strings.h"

char * trim_value(char * original_value) {
    char * value, * aux;
    int i;

    if(original_value == NULL) {
        return NULL;
    }

    while (original_value[0] != '(') {
        original_value++;
    }
    aux = ++original_value;

    i = 0;
    while (original_value[0] != ')') {
        original_value++;
        i++;
    }

    value = (char *) malloc((i + 1) * sizeof(char));
    strncpy(value, aux, i);
    value[i] = '\0';

    return value;
}

char * to_lower(char * src_string) {
    char * src = NULL;
    int i;

    src = (char *) malloc((strlen(src_string) + 1) * sizeof(char));

    for(i = 0; i < strlen(src_string); i++) {
        src[i] = tolower((unsigned char) src_string[i]);
    }
    src[i] = '\0';

    return src;
}

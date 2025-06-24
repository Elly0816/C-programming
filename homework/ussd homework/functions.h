#ifndef  FUNCTION_H
#define FUNCTION_H

#include <ctype.h>

int is_alpha(const char *name){
    while(*name){

        if(!isalpha(*name) && !isspace(*name)){
            return 0;
        }
        name++;
    }
    return 1;

}




#endif
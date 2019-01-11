#include <stdio.h>
#include "generic_defs.h"
#include <string.h>

void _printc(char *stream, char * msg, char * color)
{
    if(strcmp(stream, _STDOUT))
    {
        fprintf(stdout,"%s",color);
        fprintf(stdout,"%s",msg);
        fprintf(stdout,"%s\n",RESET);
    }else if(strcmp(stream, _STDERR))
    {
        fprintf(stderr,"%s",color);
        fprintf(stderr,"%s",msg);
        fprintf(stderr,"%s\n",RESET);
    }    
    printf("%s\n", msg);
}


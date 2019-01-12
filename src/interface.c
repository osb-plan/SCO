#include <stdio.h>
#include "generic_defs.h"
#include <string.h>

 extern FILE *stdin;

 extern FILE *stdout; 

void _printc(char *stream, char * msg, char * color)
{
    if(strcmp(stream, _STDOUT))
    {
        fprintf(stdout,"%s%s",PREFIX, color);
        fprintf(stdout,"%s",msg);
        fprintf(stdout,"%s%s\n",PREFIX, RESET);
    }else if(strcmp(stream, _STDERR))
    {
        fprintf(stderr,"%s%s", PREFIX, color);
        fprintf(stderr,"%s",msg);
        fprintf(stderr,"%s%s\n", PREFIX, RESET);
    }    
    printf("%s\n", msg);
}


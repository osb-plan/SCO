#include <stdio.h>
#include "generic_defs.h"
#include <string.h>

 extern FILE *stdin;

 extern FILE *stdout; 

void _printc(char *stream, char * msg, char * color)
{
    if(strcmp(stream, _STDOUT))
    {
        fprintf(stdout,"\033%s",color);
        fprintf(stdout,"%s",msg);
        fprintf(stdout,"\033%s\n",RESET);
    }else if(strcmp(stream, _STDERR))
    {
        fprintf(stderr,"\033%s",color);
        fprintf(stderr,"%s",msg);
        fprintf(stderr,"\033%s\n",RESET);
    }    
    printf("%s\n", msg);
}


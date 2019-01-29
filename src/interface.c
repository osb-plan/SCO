#include <stdio.h>
#include "generic_defs.h"
#include <string.h>

#ifdef TIME_SUPPORT_ENABLED
	#include <time.h>
#endif

extern FILE *stdin;
extern FILE *stdout; 

#ifdef TIME_SUPPORT_ENABLED
void print_datetime(char * stream)
{
    FILE *_stream = NULL;	
    if(strcmp(stream, _STDOUT))
    {
        _stream = stdout;       	
    }
    else
    {
        _stream = stderr;       	
    }

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
        fprintf(_stream,"%s%s",PREFIX, BRIGHT_BLACK);
	fprintf(_stream,"[%d-%d-%d %d:%d:%d] "
                , tm.tm_year + 1900
                , tm.tm_mon + 1
                , tm.tm_mday
                , tm.tm_hour
                , tm.tm_min
                , tm.tm_sec
              );
        fprintf(_stream,"%s%s",PREFIX, RESET_COLOR);
}
#endif

void _printc(char *stream, char * msg, char * color)
{

#ifdef TIME_SUPPORT_ENABLED
        print_datetime(stream);
#endif
    if(strcmp(stream, _STDOUT))
    {
        fprintf(stdout,"%s%s",PREFIX, color);
        fprintf(stdout,"%s",msg);
        fprintf(stdout,"%s%s\n",PREFIX, RESET_COLOR);
    }else if(strcmp(stream, _STDERR))
    {

        fprintf(stderr,"%s%s", PREFIX, color);
        fprintf(stderr,"%s",msg);
        fprintf(stderr,"%s%s\n", PREFIX, RESET_COLOR);
    }    
}


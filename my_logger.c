#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

FILE *fp ;

typedef enum
{
    INFO,
    WARNINING,
    ERROR,
    FATAL
} LEVELS;

char* print_time()

{
    time_t timer = time(NULL);
    return ctime(&timer);
}

void log_print(char *filename, LEVELS my_log, LEVELS prog_log, const char* fmt,...)
{
   
    fp = fopen(filename,"a");
    
    if (!fp)
    {
        fprintf(stderr, "Can't create or open file log.txt \n");
        return;
    }

    if (my_log < prog_log)
        return;
    
    va_list list;
    fprintf(fp, "%s", print_time());
    va_start( list, fmt );
    vfprintf(fp, fmt, list);
    va_end (list);
    fclose(fp);
   
}


int main()
{
    LEVELS my_logger = FATAL;
    int i = 5;
    char *s = "very";
    
    log_print("log.txt", my_logger, WARNINING, "I don't like this %d %s \n",i,s);
    
    return 0;
}

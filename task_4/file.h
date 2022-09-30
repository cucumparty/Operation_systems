#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <sys/errno.h>
#include <utime.h>
#include <sys/time.h>

int func(FILE* f_help, int flag_h, int flag_v, int flag_f, int flag_i, int flag_p, 
          FILE* f1, FILE* f2,  FILE* f3, char* s, char* help, char* f1_name, char* f2_name);

void verbose(char* f1, char* f2);

char* interactive();

void Print(FILE* f1, FILE* f2, char* s);

void preserve(char* f1_name, char* f2_name);
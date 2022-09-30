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

void strmode(int mode, char * buf);

void month_change(char month[], int num);

void l_flag(struct stat info, int* total, int* directory);

int flag_func(DIR* file, int argc, char** argv, int flag_a, int flag_l, int flag_R);

void read_file(DIR* file, int flag_a, int flag_l, int flag_R);

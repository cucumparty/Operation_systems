#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <string.h>

int main()
{
    int my_id = getuid();
    struct passwd* pwd= getpwuid(my_id);
    int group_id = getgid();
    struct group* getgr = getgrgid(group_id);
    printf("uid=%d(%s) gid=%d(%s) groups=", my_id, pwd->pw_name, group_id, getgr->gr_name);

    struct group* grent = getgrent();
    while(grent != NULL)
    {
        while(*(grent->gr_mem) != NULL)
        {
            if(strcmp(pwd->pw_name, *(grent->gr_mem)) != 0)
                (grent->gr_mem)++;
            else
            {
                printf("%d(%s) ", grent->gr_gid, grent->gr_name);
                (grent->gr_mem)++;
            }
        } 
        grent = getgrent();
    }
    
    return 0;
}
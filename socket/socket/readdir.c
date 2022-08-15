#include <stdio.h>
#include <dirent.h>

int main() {
    DIR           *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(dir->d_type == '\x04'){
                printf("[dir] ");
            }else{
                printf("[fil] ");
            }
            printf("%s\n", dir->d_name);
        }

        closedir(d);
    }

}
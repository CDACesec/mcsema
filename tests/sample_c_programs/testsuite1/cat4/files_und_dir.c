#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>


int main() {

    char buff[51];
    // chmod
    //printf("changing file_perms.txt to readonly\n");
    system("touch file_perms.txt");
    printf("before\n");
    system("ls -l file_perms.txt");
    chmod("file_perms.txt", S_IRUSR);
    printf("now\n");
    system("ls -l file_perms.txt");

    // chown
    printf("before\n");
    system("ls -l file_perms.txt");
    chown("file_perms.txt", 0, 0);
    printf("now\n");
    system("ls -l file_perms.txt");


    // link
    // unlink

    // mkdir
    printf("before\n");
    system("ls -l temp_dir_");
    mkdir("temp_dir_", O_CREAT); 
    printf("now\n");
    system("ls -l temp_dir_");

    // rmdir
    printf("before\n");
    system("ls -l temp_dir_");
    rmdir("temp_dir_"); 
    printf("now\n");
    system("ls -l temp_dir_");

    // getcwd and chdir
    printf("cwd: %s\n", getcwd(buff, 50));
    chdir("exp");
    printf("cwd: %s\n", getcwd(buff, 50));

    // opendir
    DIR * directory = opendir("../exp"); /* previous command changes cwd */

    // readdir
    struct dirent * dir_info = readdir(directory);
    
    //view all members of the directory
    while( dir_info != NULL) {
        printf("inode: %d name: %s\n", dir_info->d_ino, dir_info->d_name);
        dir_info = readdir(directory); //get next entry
    }

    // closedir
    closedir(directory);
    return 0;
}

void __start() {
    main();
    _Exit(0);
}

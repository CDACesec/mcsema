#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

typedef struct Utilizadores{
    char *login;
    char *pwd;
} USERS;

void ReadUsers(USERS user[]);

int u = 0;

int main(){
    USERS user[MAX_USERS];

    ReadUsers(user);

    return 0;
}

void ReadUsers(USERS user[]){
    FILE *fp;

    fp = fopen("/home/mohit/Desktop/users.txt", "r");

    while(fscanf(fp, "%s[^=]=%s\n", user[u].login, user[u].pwd) != EOF){
        u++;
    }

    fclose(fp);
}

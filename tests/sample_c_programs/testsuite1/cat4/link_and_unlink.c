#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main() {
    char path[] = "/home/cdacesec/Desktop/clang_O3";
    // first create the file
    system("touch /home/cdacesec/Desktop/clang_O3");

    //check that file exists
    system("ls -l /home/cdacesec/Desktop/clang_O3");
    
    //unlink the file(delete it)
    unlink("/home/cdacesec/Desktop/clang_O3");
    
    //check again
    system("ls -l /home/cdacesec/Desktop/clang_O3");
    
    // first create the file
    system("touch /home/cdacesec/Desktop/clang_O3");
    
    //check that file exists
    system("ls -l /home/cdacesec/Desktop/clang_O3_link");
    
    // create the link
    link("/home/cdacesec/Desktop/clang_O3", "/home/cdacesec/Desktop/clang_O3_link");
    
    // check again
    system("ls -l /home/cdacesec/Desktop/clang_O3_link");
    
    // delete the link and the file
    unlink("/home/cdacesec/Desktop/clang_O3");
    unlink("/home/cdacesec/Desktop/clang_O3_link");
    
    // check again
    system("ls -l /home/cdacesec/Desktop/clang_O3_link");
    system("ls -l /home/cdacesec/Desktop/clang_O3");
    
    return 0;
}

void __start() {
    main();
    _Exit(0);
}

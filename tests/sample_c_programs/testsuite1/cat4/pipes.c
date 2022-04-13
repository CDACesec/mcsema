#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>


#define ReadEnd  0
#define WriteEnd 1
int main() {

    int fd1, fd; 
  	char * myfifo = "myfifo"; 

    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
	

	  char str1[20];
    pid_t pid = fork();
    if (pid == 0) {
      //child will read
      fd1 = open(myfifo,O_RDONLY); 
      read(fd1, str1, 20); 

      // Print the read string and close 
      printf("parent said: %s\n", str1); 
      close(fd1); 
      _Exit(0);
    }
    
    //parent will write
		fd = open(myfifo, O_WRONLY); 
    char message[] = "hello my child!";
		write(fd, message, 15); 
		close(fd); 
   
    return 0;
}


void __start()
{
   int a = main();
	_Exit(0);
}

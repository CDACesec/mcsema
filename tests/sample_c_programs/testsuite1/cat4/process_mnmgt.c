// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping
// when child process exits.

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }

int main() {
   int x = fork(); //create child process
   if (x > 0) //if x is non zero, then it is parent process
      printf("Inside Parent---- PID is : %d\n", getpid());
   else if (x == 0) { //for chile process x will be 0
      sleep(5); //wait for some times
      x = fork();
      if (x > 0) {
         printf("Inside Child---- PID :%d and PID of parent : %d\n", getpid(), getppid());
         while(1)
            sleep(1);
         printf("Inside Child---- PID of parent : %d\n", getppid());
      }
      else if (x == 0)
      printf("Inside grandchild process---- PID of parent : %d\n", getppid());
   

   // To check use commmand "pgrep daemon"
   // and ps -p 4841 -o "user pid ppid pgid sid tty command"
   // change to the "/" directory
   int nochdir = 0;

  // redirect standard input, output and error to /dev/null
  // this is equivalent to "closing the file descriptors"
  int noclose = 0;

  // glibc call to daemonize this process without a double fork
  if(daemon(nochdir, noclose))
    perror("daemon");

  // our process is now a daemon!
  sleep(444);
   }

   return 0;
}

#include <stdio.h>
#include <unistd.h> 
#include <sys/syscall.h>
#include <errno.h>

int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }
 
int main(void) {
  char *binaryPath = "/bin/ls";
  char *arg1 = "-lh";
  char *arg2 = "/home";
  int rc;

  rc = syscall(SYS_fchmod, "/etc/passwd", 0666);
  if (rc == -1)
      fprintf(stderr, "chmod failed, errno = %d\n", errno);
  printf("%d\n",rc);
  execl(binaryPath, binaryPath, arg1, arg2, NULL);
  return 0;
}

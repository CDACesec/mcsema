#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdlib.h>
#include  <unistd.h>
int main();
void __start()
{
	int a=main();
	_Exit(0);
}
void  SIGINT_handler(int);   
void  SIGQUIT_handler(int); 

int   ShmID;      
pid_t *ShmPTR;    

int main(void)
{

     int   i;
     pid_t pid = getpid();
     key_t MyKey;

     /* signal handling */
     if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("SIGINT install error\n");
          exit(1);
     }
     if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) {
          printf("SIGQUIT install error\n");
          exit(2);
     }

     MyKey   = ftok(".", 's');    
     ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     *ShmPTR = pid;               

     printf("try sending SINGINT\n");
     
     for (i = 0; i < 5 ; i++) {        
          printf("From process %d: %d\n", pid, i);
          sleep(1);
     }
     
     
     /* signal blocking */
     // add sigint and to blocking set
     sigset_t intmask;
     sigemptyset(&intmask);
     sigaddset(&intmask, SIGINT);
     sigaddset(&intmask, SIGALRM);
          
     // block and show
     printf("SIGINT and SIGALRM will be blocked now\n");
     sigprocmask(SIG_BLOCK, &intmask, NULL);
     
     //child will kill the parent
     pid = fork();
     if(pid == 0) {
     //send SIGALRM, which is blocked
     printf("alarm sent to parent\n");
     kill(getppid(), SIGALRM);
       
     printf("sending kill now\n");
     sleep(2);
     
     // send SIGKILL signal to itself
     //kill(getpid(), SIGKILL); /* this can't be ignored */ 
     raise(SIGKILL);
     
    }
     
     sleep(6);
     
     //unblock and show
     printf("SIGINT/SIGALRM unblocked\n");
     sigprocmask(SIG_UNBLOCK, &intmask, NULL);
    return 0;
     
}

void  SIGINT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGINT: just got a %d (SIGINT ^C) signal\n", sig);
     signal(sig, SIGINT_handler);
}

void  SIGQUIT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal"
                          " and is about to quit\n", sig);
     shmdt(ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);

     exit(3);
}

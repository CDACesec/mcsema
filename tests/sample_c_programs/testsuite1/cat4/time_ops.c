#include <stdio.h>
#include <time.h>
#include <unistd.h> //you need this for linux!

int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }
 

/*
 * The result should look something like
 * Fri 2008-08-22 15:21:59 WAST
 */

int main(void)
{
    time_t     now;
    struct tm *ts;
    char       buf[80];

    /* Get the current time */
    now = time(NULL);

    /* Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" */
    ts = localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    puts(buf);

// To demonstrate working of sleep()
    printf("Hello,\n");
    sleep(5);		 // format is sleep(x); where x is # of seconds.
    printf("World\n");


// to demonstrate working of wait()

    if (fork()== 0)
        printf("HC: hello from child\n");
    else
    {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }
 
    printf("Bye\n");
    return 0;
}

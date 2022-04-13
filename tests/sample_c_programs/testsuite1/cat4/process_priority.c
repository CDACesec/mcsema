#include <sys/resource.h>
#include <sys/time.h>
#define _GNU_SOURCE
#include <sched.h>
#include <assert.h>
#include <sched.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main();

void __start() {
	int a=main();
	_Exit(0);
}

int main() {
    // yielding, priority, affinity, nice
    // priority 
    
    int curr_priority = getpriority(PRIO_PROCESS, getpid());
    printf("current priority: %d\n", curr_priority);
    
    // niceness
    nice(4);
    curr_priority = getpriority(PRIO_PROCESS, getpid());
    printf("current priority: %d\n", curr_priority);
    return 0;
       
}

//C program for Producer process illustratiing POSIX shared-memory API. 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<sys/types.h>
#include <sys/mman.h>
int main();
void __start()
{

	int a=main();
	_Exit(0);
}
int main() 
{ 
	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096; 

	/* name of the shared memory object */
	const char* name = "OS"; 

	/* strings written to shared memory */
	const char* message_0 = "CDAC"; 
	const char* message_1 = "TEST SUITE!";
	printf("Producing %s %s\n", message_0,message_1); 

	/* shared memory file descriptor */
	int shm_fd; 

	/* pointer to shared memory obect */
	void* ptr; 

	/* create the shared memory object */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 

	/* configure the size of the shared memory object */
	ftruncate(shm_fd, SIZE); 

	/* memory map the shared memory object */
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 

	/* write to the shared memory object */
	sprintf(ptr, "%s", message_0); 

	ptr += strlen(message_0); 
	sprintf(ptr, "%s", message_1); 
	ptr += strlen(message_1); 
	return 0; 
} 


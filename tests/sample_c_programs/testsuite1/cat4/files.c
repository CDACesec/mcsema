#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char buff[15];
	//create or open
	char * file_name = "cdac_test_suite.txt";
	printf("opening file\n");
	int file_fd = open(file_name, O_CREAT | O_RDWR | O_SYNC, S_IRWXU);

	// write to a file
	printf("writing to the file\n");
	char msg [] = "cdac_test_suite";
	write(file_fd, msg, 15); // 15 is strlen of cdac_test_suite 

	// seek | reset offset to beginning
	lseek(file_fd, 0, SEEK_SET);

	// read
	printf("reading from the file now\n");
	read(file_fd, buff, 15);
	printf("read: %s\n", buff);
	
	// truncate then read
	printf("trucating file size to 10 bytes\n");
	ftruncate(file_fd, 10);

	// synced i/o, done via O_SYNC flag while opening
	
	// multiplxed i/o
	close(file_fd);
	return 0;
}

void __start() {
	main();
	_Exit(0);
}

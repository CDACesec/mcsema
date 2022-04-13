#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
	// make it so that printing to console writes to a file
	printf("the next printf goes inside the outfile\n");
	char * out_file = "created_using_dup"; // created in cwd
	int out_fd = open(out_file, O_RDWR | O_CREAT, S_IRWXU );
	dup2(out_fd, 1);
	//close(1); /* not required? */
	printf("your printf was redirected here! strange! \n");
	return 0;
}

void __start() {
	int ret_val = main();
	_Exit(ret_val);
}

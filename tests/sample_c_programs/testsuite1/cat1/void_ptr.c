#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 10;
	char b = 'x';
	char * message = "some sample output\n";

	void *p = &a; // void pointer holds address of int 'a'
	printf("void * using an int: %d \n", *(int *)p);
	
	p = &b; // void pointer holds address of char 'b'
	printf("void * using an char: %c\n", *(char *)p );
	
	p = message; // void pointer holds address of a string
	printf("void * using an char *: %s \n", (char *)p);
	
	return 0;
}

void __start() {
	int retval = main();
	_Exit(retval);
}

#include <stdio.h>

// Inline function in C
static inline int foo()
{
	return 2;
}

// Driver code
int main()
{

	int ret;

	// inline function call
	ret = foo();

	printf("Output is: %d\n", ret);
	return 0;
}

void __start() {
	int retval = main();
	_Exit(0);
}

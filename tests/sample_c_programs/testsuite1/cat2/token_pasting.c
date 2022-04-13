
// source code for token pasting

#include <stdio.h>
int main();
void __start()
{
int a = main();
_Exit(0);

}

// Macro definition with token pasting
#define CONCAT(a, b) a##b

int main()
{
	printf("CONCAT(10, 20) = %d\n", CONCAT(10, 20));
	
	return 0;
}

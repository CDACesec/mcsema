#include <stdio.h> 
#include <stdlib.h>
int main();

void __start()
{
	int a=main();
	_Exit(0);
}

int main()
{
	// int constant
	const int intVal = 10;

	// Real constant
	const float floatVal = 4.14;

	// char constant
	const char charVal = 'A';

	// string constant
	const char stringVal[10] = "ABC";
	
	printf("Integer constant:%d \n", intVal );
	printf("Floating point constant: %.2f\n", floatVal );
	printf("Character constant: %c\n", charVal );
	printf("String constant: %s\n", stringVal);
	return 0;
}

/* Compile code with optimization option */
#include <stdio.h> 
int main();
void __start()
{
	int a=main();
	_Exit(0);
}
int main(void) 
{ 
	const volatile int local = 10; 
	int *ptr = (int*) &local; 

	printf("Initial value of local : %d \n", local); 

	*ptr = 100; 

	printf("Modified value of local: %d \n", local); 

	return 0; 
} 


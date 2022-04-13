#include<stdio.h>
int main();
void __start()
{
	int a=main();
	_Exit(0);
}
int main()
{
	int *a,b=10,c=20,*d;
	a=&b;
	d=&b;
	printf("The sum of value is %d\n", (*a + *d));
	printf("Incremening the adress of %p\n",++a);
	printf("Decrementing the address of %p\n",--d);
	return 0;
	
}

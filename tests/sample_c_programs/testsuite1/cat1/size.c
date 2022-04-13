/* PROGRAM FOR SIZEOF.


/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:4/SEP/2019
	E-MAIL: kmohit@cdac.in


*/


#include <stdio.h>
#include <limits.h>
 
int main()
{
int a=1;
char b='a';
float c=1.2;
double d=2.222;
printf("Storage size for int data type:%lu \n",sizeof(a));	//integer
printf("Storage size for char data type:%lu \n",sizeof(b));	//character
printf("Storage size for float data type:%lu \n",sizeof(c));	//float	
printf("Storage size for double data type:%lu\n",sizeof(d));	//double
return 0;
}

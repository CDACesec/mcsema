

/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:1/dec/2020
	E-MAIL: kmohit@cdac.in


*/


//Program for float pointer

#include<stdio.h>

int main()
{
    float var = 3.1415,*ptr;

    ptr = &var;   //ptr references var

    printf("Address of var = %x\n",&var);
    printf("ptr is pointing to an address  %x\n",ptr);
    printf("Value stored at ptr = %f",*ptr);

    return 0;
}


/* Name     :- Tiwari Abhinav Ashok Kumar
   Emp Id   :- 343813
   Email Id :- abhinavt@cdac.in*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main();
union koti
{
    int i;
    float f;
    char c;
};
void __start()
{
	int a=main();
	_Exit(0);
}

int main()
{
    union koti  *p;
    p= (union  koti *)malloc(1 * sizeof(union koti));
    p->f =12.3;
    printf ("%f\n",p->f);
    return 0;
}

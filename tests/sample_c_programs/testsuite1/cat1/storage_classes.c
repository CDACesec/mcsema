#include<stdio.h>
int main();
void __start()
{
	int a=main();
	_Exit(0);
}

extern int x = 32;
int b = 8;

int main()

  {
    auto int j= 2;
    static int k=90;
    register int l=5;
    extern int b;
    printf("The value of extern variables x and b : %d,%d\n\n\n",x,b);
    {
      		auto int j = 3;
	        static int k=9;
		register int l=51;
  	    	printf ( " auto:%d  static:%d  register:%d\n", j,k,l);
    }
      printf("outside scope: auto:%d  static:%d  register:%d", j,k,l);
    x = 15;
    printf("\n\n\nThe value of modified extern variable x : %d\n",x);
	return 0;
}


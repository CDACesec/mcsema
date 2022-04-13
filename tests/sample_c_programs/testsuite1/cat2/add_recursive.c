/*   Name     :- Tiwari Abhinav Ashok kumar
     Emp Id   :- 343813
     Email id :- abhinavt@cdac.in
*/


#include<stdio.h>
int main();

int add(int x, int y)
{
   if(y == 0)
     return x;
   else   
     return add( x^y, (x & y) << 1);//Use of the opeator to add
}
void __start()
{
	int a=main();
	_Exit(0);
}

int main()
{
   int a, b, sum;
   printf("Enter two numbers: ");
   printf("\n");
   scanf("%d %d", &a, &b);
   sum = add(a,b);
   printf("Sum = %d\n",sum);
   printf("\n");
   return 0;
}

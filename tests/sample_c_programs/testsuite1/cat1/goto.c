

/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:1/dec/2020
	E-MAIL: kmohit@cdac.in


*/




// Program to calculate the sum and average of positive numbers
// If the user enters a negative number, the sum and average are displayed.

#include<stdio.h>

int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   
int main()
{
   int sum=0;
   for(int i = 0; i<=10; i++){
	sum = sum+i;
	if(i==5){
	   goto addition;
	}
   }

   addition:
   printf("Sum: %d\n", sum);

   return 0;
} 

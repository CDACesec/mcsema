/* Name       :- Tiwari Abhinav Ashok Kumar
   Emp id     :- 343813
   E-Mail id  :-abhinavt@cdac.in
*/



// C program to find if machine is little 
// endian or big endian. 
#include <stdio.h> 
int main();
void __start()
{
	int a=main();
	_Exit(0);
}  
int main()  
{ 
   unsigned int n = 1; 
   printf("The machine endiness is \n");
   char *c = (char*)&n; 
   if (*c)     
       printf("LITTLE ENDIAN"); 
   else
       printf("BIG ENDIAN"); 
printf("\n");
   return 0; 
} 

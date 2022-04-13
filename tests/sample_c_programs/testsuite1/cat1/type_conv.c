// An example of implicit conversion
#include<stdio.h>


int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   

int main()
{
    int x = 10;    // integer x
    char y = 'a';  // character c
    char z = 'd';   // character d
  
    // y implicitly converted to int.
    // ASCII value of 'a' is 97
    int i = x + y;
    

    // z explicitly converted to int.
    // ASCII value of 'd' is 100  

    int sum = (int)z + 1;
  
    printf("implicit = %d\n", i); 
    printf("explicit = %d\n", sum);
    return 0;
}

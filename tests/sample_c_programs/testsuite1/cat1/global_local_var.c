// local variables with-in a function and they take precedence over global variables.


#include <stdio.h>
int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   

/* global variable declaration */
int a = 20;
 
int main () {

  /* local variable declaration in main function */
  int a = 10;
  int b = 20;
  int c = 0;

  printf ("value of a in main() = %d\n",  a);
  c = sum( a, b);
  printf ("value of c in main() = %d\n",  c);

  return 0;
}

/* function to add two integers */
int sum(int a, int b) {

   printf ("value of a in sum() = %d\n",  a);
   printf ("value of b in sum() = %d\n",  b);

   return a + b;
} 

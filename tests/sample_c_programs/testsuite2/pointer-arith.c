#include <stdio.h>
 




int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }



int main()
{
    int x[10] = { 0 }, i = 0, *p;
  
    // p point to starting address of array x
    p = &x[0];
    while (i < 10) {
        *p = 10;
  
        // intention was to point to integer at x[1]
        p = p + 4;
        i++;
    }
}

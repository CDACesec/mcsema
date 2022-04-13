#include <stdio.h>


int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   



int main()
{
     int num =0;
     while(num<=100)
     {
        printf("value of variable num is: %d\n", num);
        if (num==2)
        {
            break;
        }
        num++;
     }
     printf("Out of while-loop\n");
     return 0;
}

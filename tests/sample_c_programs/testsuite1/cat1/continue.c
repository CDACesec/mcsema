#include<stdio.h>



int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   

 int main()
 {
   int i=0;
   while(i<5)
   {
     i++;
     if(i==3) continue;
     printf("%d\t\n",i);
   }
   return 0;
 }

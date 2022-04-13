
/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:1/dec/2020
	E-MAIL: kmohit@cdac.in


*/


//Program for Enumeration


#include <stdio.h>

void __start()
   {  
       int a = main();
       _Exit(0);
   }                   


enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main()
{
    // creating today variable of enum week type
    enum week today;
    today = Wednesday;
    printf("Day %d",today+1);
    return 0;
}

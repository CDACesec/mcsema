#include<stdio.h>
#include <string.h>


int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   
struct student 
{
     int id;
     char name[30];
     int percentage;
};
 
int main() 
{
     int i;
     struct student record1 = {1, "Raju", 90.5};
     struct student *ptr;
 
     ptr = &record1;     
 
         printf("Records of STUDENT1: \n");
         printf("  Id is: %d \n", ptr->id);
         printf("  Name is: %s \n", ptr->name);
         printf("  Percentage is: %d \n\n", ptr->percentage);
 
     return 0;
}

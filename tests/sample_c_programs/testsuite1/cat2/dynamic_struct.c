/* Name      :- Tiwari Abhinav Ashok Kumar
   Emp Id    :- 343813
   E-mail id :- abhinavt@cdac.in
*/





#include <stdio.h>
#include <stdlib.h>
int main();
struct person {
   int age;
   float weight;
   char name[30];
};
void __start()
{
	int a=main();
	_Exit(0);
}
int main()
{
   struct person *ptr;
   int i, n;

   printf("Enter the number of persons: ");
   scanf("%d", &n);

   // allocating memory for n numbers of struct person
   ptr = (struct person*) malloc(n * sizeof(struct person));

   for(i = 0; i < n; ++i)
   {
       printf("Enter first name and age respectively: ");

       // To access members of 1st struct person,
       // ptr->name and ptr->age is used

       // To access members of 2nd struct person,
       // (ptr+1)->name and (ptr+1)->age is used
       scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
   }

   printf("Displaying Information:\n");
   for(i = 0; i < n; ++i)
       printf("Name: %s\tAge: %d\n", (ptr+i)->name, (ptr+i)->age);

   return 0;
}

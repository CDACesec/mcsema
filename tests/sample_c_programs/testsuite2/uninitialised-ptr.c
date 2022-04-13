
// C program to demonstrate segmentation
// fault when uninitialized pointer is accessed.
#include <stdio.h>
 
int main()
{
   int *p;
   printf("%d",*p);
   return 0;
}

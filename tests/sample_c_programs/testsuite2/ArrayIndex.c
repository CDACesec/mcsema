#include<stdio.h>                                   //Used to include basic c library files
void main()                                        //Used to execute the C application
{
                                                 //declaring and defining the array variables
int a[5] = {100,101,102,103,104};
int b[5] = {105,106,107,108,109};
                                                //displaying the output
printf("%d\n",a[100]);                               //array index out of bounds run-time error
                                                        //in c this is not shown any error message it will just show out of bound values as 0
printf("%d\n",b[700]);                                      //array index out of bounds run-time error
}

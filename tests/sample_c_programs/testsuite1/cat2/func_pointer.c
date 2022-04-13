/*      NAME:  MOHIT KUMAR
        E-CODE:343542
        DATE:1/dec/2020
        E-MAIL: kmohit@cdac.in
   
   
*/



#include <stdio.h>
void my_int_func(int x)
{
    printf( "%d\n", x );
}
 
 
int main()
{
    void (*foo)(int);
    foo = &my_int_func;
 
    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );
 
    return 0;
}

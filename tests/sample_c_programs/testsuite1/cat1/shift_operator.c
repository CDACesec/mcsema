#include <stdio.h>

int main();
void __start()
{
int a = main();
_Exit(0);

}
int main(void)
{
    unsigned int b = 16, result;
    int c = -16 , val;
 
    printf("value of exp. result = b >> 3 is %d\n", result = b >> 3);
    printf("value of b after right shift by 3 bits, is %d\n", b); 
    printf("value of exp. result = b << 3 is %d\n", result = b << 3);
    printf("value of b after left shift by 3 bits, is %d\n", b); 
    printf("value of exp. val = c >> 3, is %d\n", val = c >> 3);
    
  
    return 0;
}

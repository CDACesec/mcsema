#include <stdio.h>
#line 100
int main(void)
{
printf("%d\n", __LINE__); /* line 102 */
return 0;
}


void __start() {
    main();
    _Exit(0);
}

#include<stdio.h>
int main();
struct Scope
{
    // Anonymous structure
    struct
    {
        char alpha;
        int num;
    };
};
void __start()
{
	int a=main();
	_Exit(0);
} 
int main()
{
    struct Scope x;
    x.num = 65;
    x.alpha = 'B';
 
    // Note that members of structure are accessed directly
    printf("x.alpha = %c, x.num = %d", x.alpha, x.num);
    printf("\n");
    return 0;
}

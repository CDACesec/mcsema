/* Name     :- Tiwari Abhinav Ashok Kumar
   E id     :- 343813
   emai-id  :-abhinavt@cdac.in
*/

// C Program to demonstrate working of anonymous union
#include <stdio.h>
int main();
struct Scope {
    // Anonymous union
    union {
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
    x.alpha = 'A';
 
    // Note that members of union are accessed directly
    printf("x.alpha = %c, x.num = %d\n", x.alpha, x.num);
 
    return 0;
}

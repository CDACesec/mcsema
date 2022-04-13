/* Name     :- Tiwari Abhinav Ashok Kumar
   Emp id   :- 343813
   Email id :-abhinavt@cdac.in
*/
#include <stdio.h>
int main();
void __start()
{
	int a=main();
	_Exit(0);
}
int main() {
    int data[5];

    printf("Enter elements: ");
    for (int i = 0; i < 5; ++i)
        scanf("%d", data + i);

    printf("You entered: \n");
    for (int i = 0; i < 5; ++i)
        printf("%d\n", *(data + i));
    return 0;
}

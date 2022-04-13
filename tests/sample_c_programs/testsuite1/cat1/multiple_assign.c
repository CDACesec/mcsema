#include <stdio.h> 

void __start()
{
	int a=main();
	_Exit(0);
}

// C program to demonstrate multiple assignment
int main() {
    long a, b, c ,d;
    printf("before assignment: %li %li %li %li \n", a, b, c, d);
    a = b = c = d = 106;
    printf("after assignment: %l %l %l %l\n", a, b, c, d);
    return 0;
} 


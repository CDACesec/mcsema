#include <stdio.h>

FILE *input, *output;
size_t pepe;
char *c1;

int main()
{
	input= fopen("1.in", "r");
	output= fopen("1.out", "w");

	pepe= fread(c1, 1, 1, input);
    c1="a";
	printf("%s\n", c1);
	return 0;
};

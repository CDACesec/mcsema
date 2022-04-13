#include <stdio.h>
#include <string.h>

int main()
{
	 char *str = "Hi.123456789";

	 strcpy(str, "Changed.");
	 puts(str);
	 return 0;
}


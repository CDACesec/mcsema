// A C/C++ program for splitting a string 
// using strtok() 
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char str[] = "CDAC-TEST-SUITES"; 
	char *p;
        p=str;
	printf("The string to be split is  %s",p);
	// Returns first token 
	char* token = strtok(str, "-"); 
	printf("\nThe spliting token is -\n");

	// Keep printing tokens while one of the 
	// delimiters present in str[]. 
//	printf("%s\n",token);
	while (token != NULL) { 
		printf("%s\n", token); 
		token = strtok(NULL, "-"); 
	} 

	return 0; 
} 


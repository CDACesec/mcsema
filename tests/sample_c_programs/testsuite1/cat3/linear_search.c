/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:1/dec/2020
	E-MAIL: kmohit@cdac.in


*/

/*##Simple Searching In Array*/
/*##Searching Programs, Array Example Programs*/

#include  <stdio.h>
#define ARRAY_SIZE 5
int main();
void __start()
{
	int a=main();
	_Exit(0);
} 
int main()
{
    int numbers[ARRAY_SIZE], i ,search_key;

	// Read Input
    for (i = 0; i < ARRAY_SIZE; i++)
    {
		printf("Enter the Number : %d  : ", (i+1));
        scanf("%d", &numbers[i]);
    }
    
    printf("Enter the key\n");
    scanf("%d", &search_key);
    
    /*  Simple Search with Position */
	for (i = 0; i < ARRAY_SIZE; i++)
    {
		if(numbers[i] == search_key)
		{
			printf("Search Element Found . Position Is : %d \n",(i+1));
			break;
		}
		if(i == ARRAY_SIZE - 1)
		{
			printf("Search Element is not in Array.\n");
		}
    }
    
    
}

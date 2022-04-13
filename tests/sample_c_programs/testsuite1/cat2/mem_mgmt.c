
#include <stdio.h> 
#include <stdlib.h> 
int main();
void __start()
{
	int a=main();
	_Exit(0);
}

int main() 
{ 

	// This pointer will hold the 
	// base address of the block created 
	int* ptr; 
	int n, i; 
        int n1, r, *ptr1, sum = 0;
        int m, *ptr2; 

	// Get the number of elements for the array 
	n = 5; 
	printf("Enter number of elements: %d\n", n); 

	// Dynamically allocate memory using calloc() 
	ptr = (int*)calloc(n, sizeof(int)); 

	// Check if the memory has been successfully 
	// allocated by calloc or not 
	if (ptr == NULL) { 
		printf("Memory not allocated.\n"); 
		exit(0); 
	} 
	else { 

		// Memory has been successfully allocated 
		printf("Memory successfully allocated using calloc.\n"); 

		// Get the elements of the array 
		for (i = 0; i < n; ++i) { 
			ptr[i] = i + 1; 
		} 

		// Print the elements of the array 
		printf("The elements of the array are: "); 
		for (i = 0; i < n; ++i) { 
			printf("%d, ", ptr[i]); 
		} 
	} 
        free(ptr);
	printf("\n");
  

       printf("Enter number of elements: ");
       scanf("%d", &n1);

       ptr1 = (int*) malloc(n1 * sizeof(int));
 
    // if memory cannot be allocated
      if(ptr1 == NULL)                     
      {
         printf("Error! memory not allocated.");
         exit(0);
      }

       printf("Enter elements: ");
       for(r = 0; r < n1; ++r)
       {
          scanf("%d", ptr1 + r);
          sum += *(ptr1 + r);
       }

       printf("Sum = %d", sum);
  
      // deallocating the memory
      free(ptr1);
      printf("\n"); 

        ptr2 = (int *)malloc(5 *sizeof(int));
        if(ptr2 == NULL)
        {
                printf("Memory not available\n");
                exit(1);
        }
        printf("Enter 5 integers : ");
        for(m=0; m<5; m++)
                scanf("%d", ptr2+m);
        /*Allocate memory for 4 more integers*/
        ptr2 = (int *)realloc(ptr2, 9*sizeof(int));
        if(ptr2 == NULL)
        {
                printf("Memory not available\n");
                exit(1);
        }
        printf("Enter 4 more integers : ");
        for(m=5; m<9; m++)
                scanf("%d", ptr2+m);
        for(m=0; m<9; m++)
                printf("%d\n ", *(ptr2+m));

	free(ptr2);
	return 0; 
} 



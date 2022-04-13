#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr = fopen("Helloworld.txt","r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Failed to open the file\n");
//        abort();
    }
    /* Normal processing continues here. */
    fclose(fptr);
    printf("Normal Return\n");
    return 0;
}

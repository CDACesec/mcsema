

/* PROGRAM FOR NESTED LOOP


   	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:4/SEP/2019
	E-MAIL: kmohit@cdac.in


*/







#include <stdio.h>
int main()
{
    int i=1,j;
    while (i <= 5)	// nested loop
			//checking the condition of i
    {
        j=1;
        while (j <= i )	//checking the condition of j
        {
            printf("%d ",j);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

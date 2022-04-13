
/* PROGRAM FOR MACROS..*/


/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:4/SEP/2019
	E-MAIL: kmohit@cdac.in


*/



#include <stdio.h>

    #define PI 3		//defining the macros
    int main()
    {
        int radius, area;
        printf("Enter the radius: ");
        scanf("%d", &radius);

        			// Notice, the use of PI
        area = PI*radius*radius;
        printf("Area=%d",area);
        return 0;
    }

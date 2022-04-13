
/* PROGRAM FOR BITWISE OPERATOR.


/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:4/SEP/2019
	E-MAIL: kmohit@cdac.in


*/



#include <stdio.h>
 
int main()
{
   int m = 40,n = 80,AND_opr,OR_opr,XOR_opr,NOT_opr ;//DECLARING AND INITIALISING

   AND_opr = (m&n);	//AND
   OR_opr = (m|n);	//OR
   NOT_opr = (~m);	//NOT
   XOR_opr = (m^n);	//XOR

   printf("AND_opr value = %d\n",AND_opr );
   printf("OR_opr value = %d\n",OR_opr );
   printf("NOT_opr value = %d\n",NOT_opr );
   printf("XOR_opr value = %d\n",XOR_opr );
   printf("left_shift value = %d\n", m << 1);
   printf("right_shift value = %d\n", m >> 1);

}

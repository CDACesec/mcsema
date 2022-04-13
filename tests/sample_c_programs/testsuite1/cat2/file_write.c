
/* PROGRAM FOR FILE HANDLING.


/*	NAME:  MOHIT KUMAR
	E-CODE:343542
	DATE:4/SEP/2019
	E-MAIL: kmohit@cdac.in


*/

/*
     * C program to create a file called emp.rec and store information

     * about a person, in terms of his name, age and salary.

     */

   
 #include <stdio.h>
   int main()

    {

        FILE *fptr;

        char name[20];

        int age;

        float salary;  

     				   /*  open for writing */

        fptr = fopen("emp.rec", "w");

     

        if (fptr == NULL)		//checking condition

        {

            printf("File does not exists \n");

            return 0;

        }

        printf("Enter the name \n");

        scanf("%s", name);

        fprintf(fptr, "Name    = %s\n", name);

        printf("Enter the age\n");

        scanf("%d", &age);

        fprintf(fptr, "Age     = %d\n", age);

        printf("Enter the salary\n");

        scanf("%f", &salary);

        fprintf(fptr, "Salary  = %.2f\n", salary);

        fclose(fptr);

    }

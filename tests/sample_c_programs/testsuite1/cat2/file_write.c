/*
 * Copyright (c) 2022 Centre for Development of Advanced Computing, Hyderabad.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* PROGRAM FOR FILE HANDLING.

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

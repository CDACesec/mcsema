    

    /*  DATE = 04/09/2019
 
      NAME =ANIL BANDGAR

      EMPLOY-ID = 343551 

      MAIL-ID = anilb@cdac.in  */

                                                                // program for structure understanding
  #include <stdio.h>
 void __start()
{
	int a=main();
	_Exit(0);
}

   struct StudentData{
                      char* stu_name;
                      int stu_id;
                      int stu_age;
                     };
    int main()
   {
     struct StudentData student;

     student.stu_name = "Anil";
     student.stu_id = 123;
     student.stu_age = 24;

     printf("Student Name is: %s", student.stu_name);
     printf("\nStudent Id is: %d", student.stu_id);
     printf("\nStudent Age is: %d", student.stu_age);
     return 0;
   }

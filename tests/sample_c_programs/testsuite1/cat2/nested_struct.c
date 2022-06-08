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
   	
#include <stdio.h>
#include <string.h>
int main();

struct student_college_detail
{
    int college_id;
    char college_name[50];
};

struct student_detail 
{
    int id;
    int per;
    char name[20];
    float percentage;
    // structure within structure
    struct student_college_detail clg_data;
}stu_data;
void __start()
{
	int a=main();
	_Exit(0);
}
int main() 
{
    struct student_detail stu_data = {1, 98,"Prashant", 90.5, 71145,
                                       "CDAC Institute"};
    printf(" Id is: %d \n", stu_data.id);
    printf(" Name is: %s \n", stu_data.name);
    printf(" Percentage is: %f \n\n", stu_data.percentage);
    printf(" Percentage is: %d \n\n", stu_data.per);
printf(" College Id is: %d \n", 
                    stu_data.clg_data.college_id);
    printf(" College Name is: %s \n", 
                    stu_data.clg_data.college_name);
    return 0;
}



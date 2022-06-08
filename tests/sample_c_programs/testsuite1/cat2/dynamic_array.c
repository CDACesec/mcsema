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

#include<stdio.h>
#include<stdlib.h>
int main();
void __start()
{
	int a=main();
	_Exit(0);
}
int main()
{
	int *ptr;	//declaration of integer pointer
	int limit;	//to store array limit
	int i;		//loop counter
	int sum;	//to store sum of all elements

	printf("Enter limit of the array: ");
	scanf("%d",&limit);

	//declare memory dynamically
	ptr=(int*)malloc(limit*sizeof(int));

	//read array elements
	for(i=0;i<limit;i++)
	{
		printf("Enter element %02d: ",i+1);
		scanf("%d",(ptr+i));
	}

	//print array elements
	printf("\nEntered array elements are:\n");
	for(i=0;i<limit;i++)
	{
		printf("%d\n",*(ptr+i));
	}
	
	//calculate sum of all elements
	sum=0;	//assign 0 to replace garbage value
	for(i=0;i<limit;i++)
	{
		sum+=*(ptr+i);
	}
	printf("Sum of array elements is: %d\n",sum);
	
	//free memory
	free(ptr);	//hey, don't forget to free dynamically allocated memory.
	
	return 0;
}

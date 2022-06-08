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
int main();

int add(int x, int y)
{
   if(y == 0)
     return x;
   else   
     return add( x^y, (x & y) << 1);//Use of the opeator to add
}
void __start()
{
	int a=main();
	_Exit(0);
}

int main()
{
   int a, b, sum;
   printf("Enter two numbers: ");
   printf("\n");
   scanf("%d %d", &a, &b);
   sum = add(a,b);
   printf("Sum = %d\n",sum);
   printf("\n");
   return 0;
}

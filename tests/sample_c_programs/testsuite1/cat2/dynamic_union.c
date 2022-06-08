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
#include<malloc.h>
int main();
union koti
{
    int i;
    float f;
    char c;
};
void __start()
{
	int a=main();
	_Exit(0);
}

int main()
{
    union koti  *p;
    p= (union  koti *)malloc(1 * sizeof(union koti));
    p->f =12.3;
    printf ("%f\n",p->f);
    return 0;
}

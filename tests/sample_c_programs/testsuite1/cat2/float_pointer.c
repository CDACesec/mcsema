
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


//Program for float pointer

#include<stdio.h>

int main()
{
    float var = 3.1415,*ptr;

    ptr = &var;   //ptr references var

    printf("Address of var = %x\n",&var);
    printf("ptr is pointing to an address  %x\n",ptr);
    printf("Value stored at ptr = %f",*ptr);

    return 0;
}


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
void multiply(int mat1[12][12],int mat2[12][12],int ,int ,int );
void main();
void __start()
{
	main();
	_Exit(0);

}
void main()
{
    int mat1[12][12],mat2[12][12];
    int i,j,k,m,n,p;
    printf("Enter the number of rows and columns for 1st matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the 1st matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    //no of col of 1st mat = no of rows of 2nd mat
    printf("Enter the number of columns for 2nd matrix\n"); 
    scanf("%d",&p);
    printf("Enter the elements of the 2nd matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    
    printf("The 1st matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",mat1[i][j]);
        }
        printf("\n");
    }
    printf("The 2nd matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }
    multiply(mat1,mat2,m,n,p);
}

void multiply(int mat1[12][12],int mat2[12][12],int m,int n,int p)
{
    int mul[12][12],i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            mul[i][j]=0;
            for(k=0;k<n;k++)
            {
                mul[i][j]=mul[i][j]+mat1[i][k]*mat2[k][j];
            }
        }
    }

    printf("The resultant matrix formed on multiplying the two matrices\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
}

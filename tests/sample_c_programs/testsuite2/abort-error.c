#include<stdio.h>
#include<stdlib.h>
int main();
    void __start()
   {  
       int a = main();
       _Exit(a);
   }

int main()
{
  FILE *fp = fopen("C:\\myfile.txt", "w");
    
  if(fp == NULL)
  {
    printf("\n could not open file ");
    getchar();
    exit(1);
  }  
    
  fprintf(fp, "%s", "Hello from CDAC");
   
  abort();
    
  getchar();
  return 0;  
}    


#include <stdio.h>
#include <string.h>

    int main();
      void __start()
     {  
        int a = main();
        _Exit(a);
     }


int main () {
   char str1[50], str2[50];
   char string3[] = "Hello";
   char string4[] = "CDAC";
   int i,j,k;

   //destination string
   strcpy(str1, "This is my initial string");
 
   //source string
   strcpy(str2, ", add second string");
	
   //copy the string in str2
   printf("String after copy to str2(strcpy): %s\n", str2);

   //concatenating the string str2 to the string str1
   strcat(str1, str2);

   //display destination string
   printf("String after concatenation(strcat): %s\n", str1);

  //compare the two string
  i = strcmp(string3, "Hello");

  //display compare string
  printf("Compare string output(strcmp): %d\n", i);

 // print length of string without using strlen 
  for(j = 0; string4[j] != '\0'; ++j);
        printf("Length of string(without using strlen): %d\n", j);
	

// copy the string without using strcpy
  for(k = 0; string3[k] != '\0'; ++k)
        {
            string4[k] = string3[k];
        }
        string4[k] = '\0';
        printf("String copied(without using strcpy): %s\n", string4);


 
  return(0);
}


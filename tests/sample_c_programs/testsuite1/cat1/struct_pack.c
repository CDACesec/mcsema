// source code for demonstating structure packing using attribute

 #include <stdio.h>        
 int main();
 void __start()
 
{
  int a = main();
  _Exit(0);

 }

    struct base  
    {  
        int a;  
        char b;  
        double c;  
    }__attribute__((packed));  ;  
    int main()  
    {  
      struct base var; // variable declaration of type base  
      // Displaying the size of the structure base  
      printf("The size of the var is : %d\n", sizeof(var));  
      
        return 0;  
    }  

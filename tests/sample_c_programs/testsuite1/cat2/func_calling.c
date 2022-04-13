    #include <stdio.h>  

    int main();
    void __start()
    {
       int a =main();
       _Exit(0);
    }

    void swap_val(int , int); //prototype of the function
    void swap_ref(int* , int*); //prototype of the function   
    int main()  
    {  
        int a = 10;  
        int b = 20;   
        printf("Before swapping the values in main a = %d, b = %d\n",a,b); // printing the value of a and b in main  
        swap_val(a,b);  
        printf("After swapping values in main a = %d, b = %d\n",a,b); // The value of actual parameters do not change by changing the formal parameters in call by value, a = 10, b = 20 
        swap_ref(&a,&b);
        printf("After swapping values in main a = %d, b = %d\n",a,b); // The values of actual parameters do change in call by reference, a = 20, b = 10  
    }  
    void swap_val (int a, int b)  
    {  
        int temp;   
        temp = a;  
        a=b;  
        b=temp;  
        printf("After swapping values in function a = %d, b = %d\n",a,b); // Formal parameters, a = 20, b = 10   
    }  
 
    void swap_ref (int *a, int *b)  
   {  
       int temp;   
       temp = *a;  
       *a=*b;  
       *b=temp;  
       printf("After swapping values in function a = %d, b = %d\n",*a,*b); // Formal parameters, a = 20, b = 10   
   }  

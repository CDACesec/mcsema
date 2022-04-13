
    #include <stdio.h>

int main();

 void __start()
   {  
       int a = main();
       _Exit(0);
   }                   

    int main()
     {
                                                                          // Program to add numbers until the user enters zero
        int number, sum = 0;
        // the body of the loop is executed at least once
        do
        {
            printf("Enter a number: ");
            scanf("%d", &number);
            sum += number;
        }
        while(number != 0);
        printf("Sum = %d",sum);
        return 0;
    }

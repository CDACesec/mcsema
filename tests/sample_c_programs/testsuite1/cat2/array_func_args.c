#include <stdio.h>
//#include <stdlib.h>
// way 1 void myFunction(int *param)
int getSum2(int * arr); /* function declaration */
int getSum2(int * arr) {
    int sum = 0;
    int i;
    for (i = 0; i < 5; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

// way 2 void myFunction(int param[10])
int getSum3(int arr[5]) ; /* function declaration */
int getSum3(int arr[5]) {
    int sum = 0;
    int i;
    for (i = 0; i < 5; ++i)
    {
        sum += arr[i];
    }
    return sum;
}


// way 3 void myFunction(int param[])
int getSum(int arr[], int size); /* function declaration */
int getSum(int arr[], int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int main () {
    /* an int array with 5 elements */
    int balance[5] = {1000, 2, 3, 17, 50};
    int sum;
    /* pass pointer to the array as an argument */
    sum = getSum( balance, 5 ) ;
    /* output the returned value */
    printf( "sum value is: %d \n", sum );
    
    /* test this on the second function */
    sum = getSum2( balance) ;
    printf( "sum value is: %d \n", sum );
    
    /* test this on third function */
    sum = getSum3( balance );
    printf( "sum value is: %d \n", sum );
    
    return 0;
}

void __start() {
    main();
    _Exit(0);
}

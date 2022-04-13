#include <stdio.h>
int main();
void __start()
   {  
       int a = main();
       _Exit(0);
   }                   
int main() {
  short int a = 10;
  unsigned short int b  = 20;
  long int c = 30;
  unsigned long int d = 50;
  double e = 70;
  long double f = 80;

  printf("short int a = %hi\n", a);
  printf("unsigned short int b = %hu\n", b);
  printf("long int c = %li\n", c);
  printf("unsigned long int d = %lu\n", d);
  printf("double e = %lf\n", e);
  printf("long double f = %Lf\n", f);
  return 0;
}

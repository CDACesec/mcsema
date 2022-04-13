#include<stdio.h> 
 #include<stdlib.h> 
 #include<string.h> 
  
  
 char* func() 
 { 
     char c = 'a'; 
     return &c; 
 } 
  
 int main(int argc, char *argv[]) 
 { 
     char *ptr = func(); 
     char arr[10]; 
     memset(arr,'0', sizeof(arr)); 
     arr[0] = *ptr; 
     return 0; 
 }

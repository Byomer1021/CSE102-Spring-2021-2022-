#include <stdio.h>
#include <math.h>
#include "util.h"

int main (){
  int c,o;
  int summ;
  int multip;
  int prime;
  int n1,n2,flag;
  int a,n;
  
  printf("Please select an operation\n");
  printf("1.Calculate sum/multiplication between two numbers\n");
  printf("2.Calculate prime numbers\n");
  printf("3.Show number sequence in file\n");
  printf("4.Sort number sequence in file\n");
  scanf("%d",&c);

  switch(c)
  {
     case 1: 
      printf("Select operation\n");
      printf("Please enter '0' for sum '1' for multiplication\n");
      scanf("%d",&o);  
        if(o==0) 
        summ=sum(n1,n2,flag);
        else if(o==1)
        multip= multi (n1,n2,flag);
     break;

     case 2:          
      printf("Please enter an integer\n");
      scanf("%d",&a);
        for(n=2;n<a;n++)
        {
          if(isprime (n)==-1)
          {
            printf("%d is a prime number\n",n);
          }
          else
          {
            printf("%d is not a prime number,it is divisible by %d\n",n,isprime(n) );
          }
        }
     break;




  }
  return 0;
}
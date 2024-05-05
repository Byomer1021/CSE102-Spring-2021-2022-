#include <stdio.h>
#include <math.h>
#include "util.h"


int sum (int n1, int n2, int flag)
{
    
    int result=0;
    int i;
    printf("Please enter '0' to work for even numbers '1' to work for odd numbers\n");
    scanf("%d",&flag);

    switch(flag){
       case 0:
            printf("Please enter two different numbers \n");
            printf("Number1:");
            scanf("%d",&n1);
            printf("Number2:");
            scanf("%d",&n2);
            printf("Result\n");
            for(i=n1+1;i<n2;i+=2)
            {
                 if(i%2==0)
                 {
                   printf("%d",i);
                   if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                   printf("+");
                 }
                 else if(i%2==1)
                 {
                   i++;
                   printf("%d",i);
                  if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                   printf("+");
                 }
               result+=i;
            }            
            printf("=%d\n",result);
             printf("The result is written to the result.txt file.\n");    
             write_file(result);       
            break;
        
       case 1:
            printf("Please enter two different numbers \n");
            printf("Number1:");
            scanf("%d",&n1);
            printf("Number2:");
            scanf("%d",&n2);
            printf("Result\n");
            for(i=n1+1;i<n2;i+=2)
            {
                 if(i%2==0)
                 {
                   i++;
                   printf("%d",i);
                   if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                   printf("+");
                 }
                 else if(i%2==1)
                 {
                  printf("%d",i);
                  if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                   printf("+");
                 }
                result+=i;
            }            
            printf("=%d\n",result);
             printf("The result is written to the result.txt file.\n");
             write_file(result);
        break; 
        default:
        printf("Error");
         
    }

    return 1;
}

int multi (int n1, int n2, int flag)
{
  
      int result=1;
      int i;
      printf("Please enter '0' to work for even numbers '1' to work for odd numbers\n");
      scanf("%d",&flag);

      switch(flag){
         case 0:
              printf("Please enter two different numbers \n");
              printf("Number1:");
              scanf("%d",&n1);
              printf("Number2:");
              scanf("%d",&n2);
              printf("Result\n");
              for(i=n1+1;i<n2;i+=2)
              {
                   if(i%2==0)
                   {
                     printf("%d",i);
                     if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                     printf("*");
                   }
                   else if(i%2==1)
                   {
                     i++;
                     printf("%d",i);
                    if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                     printf("*");
                   }
                result*=i;
              }                
                printf("=%d\n",result);
                printf("The result is written to the result.txt file.\n");
                write_file(result);
              break;

         case 1:
              printf("Please enter two different numbers \n");
              printf("Number1:");
              scanf("%d",&n1);
              printf("Number2:");
              scanf("%d",&n2);
              printf("Result\n");
              for(i=n1+1;i<n2;i+=2)
              {
                   if(i%2==0)
                   {
                     i++;
                     printf("%d",i);
                     if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                     printf("*");
                   }
                   else if(i%2==1)
                   {
                    printf("%d",i);
                    if( (i!=(n2-1) ) && ( i!=(n2-2) ))
                     printf("*");
                   }
              }
                    result*=i;
                    printf("=%d\n",result);
                    printf("The result is written to the result.txt file.\n");
                    write_file(result);
          break;
          default:
         printf("Error");
      }
      return 1;
} 

int isprime (int a)
{ 
   int n;
   for(n=2;n<=sqrt(a);n++)
   {
     if(a%n==0)
     {
       return n;     
     }
   }    
      return -1;
}

void write_file (int number)
{
  FILE *ptr= fopen("result.txt","a");
  fprintf(ptr,"%d",number);
  fclose(ptr);
}
void print_file ();

void sort_file ();

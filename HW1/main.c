#include <stdio.h>
#include "utils.h"
  
  int main() 
  {
    int x,y,z;
    int n;
    int f_I;
    int next;
    int control1=0; /*for identity number*/
    int control2=0; /*for password*/
    int control3=0; /*for checking id and password*/
    int control4=0; /*for withdrawable amount*/
    float cash_amount;
    int withdrawable_amount_;
    char identity_number [11] ;
    char pasword [4]="\0";
    
    /*------PART1------*/

    do
    {
      printf("Please enter the first integer\n");
      scanf("%d",&x);
      printf("Please enter the second integer\n");
      scanf("%d",&y);
      printf("Please enter the divisor\n");
      scanf("%d",&z);
    } while (x<0 || y<0 || z <=0 );
    
    f_I=find_divisible(x,y,z);
      if (f_I==-1)
      {
        printf("There is no integer between %d and %d\n",x,y);
      }    
      else
      {    
        do
        {
            printf("Enter how many next\n");
            scanf("%d",&n);
              if (n<0)
              {
                   printf("Please Enter positive number\n");
              }
        
        } while (n<0);
    
      }
    next=find_nth_divisible(n,f_I,z);
      if (next > y)
      {
          printf("Try again\n");
      }
      else
          printf(" The %d. integer between %d and %d divided by %d is %d \n",n+1,x,y,z,next);

     /*-----PART2----*/

                FILE *ptr = fopen("customeraccount.txt", "w");
        if (ptr == NULL)
      {
     printf("ERROR WHILE OPENING THE FILE !\n");
     return 0;
      }
     
    
      
      

     printf("Please enter an 11 digts identity number \n");
     scanf("%s", identity_number);
     printf("identity number= %s", identity_number);
     fprintf(ptr,"%s,",identity_number);
     control1=validate_identity_number(identity_number);
    
      
     printf("Now please enter a 4 digit password \n");
     scanf("%s", pasword);
     fprintf(ptr,"%s",pasword);       					                                
     control2=password(pasword);
    fclose(ptr);
    if (!control1 || !control2)
    {
      printf("Invalid Id or password.\n");
    }
    else
    {
       printf("Successful Registration\n");

      ptr = fopen("customeraccount.txt", "r");
      char check_identity[12];
      printf("Please enter an 11 digts identity number \n");
      scanf("%s", check_identity);
      printf("Now please enter a 4 digit password \n");
      scanf("%s", pasword);
      char temp_identity[11];
      fscanf(ptr,"%11s",temp_identity);
      fgetc(ptr);
      char temp_pass[4];
      fscanf(ptr, "%4s", temp_pass);
      
      int i;
      for(i=0; i < 11;i++)
      {
        if(temp_pass[i] && temp_pass[i] - pasword[i] != 0) return 0;
        
          if(temp_identity[i] - check_identity[i] != 0)
        {
        return 0;
        }
      }
      printf("Login Succesful\n");
          
     
          /*-----PART3-----*/

          printf("Enter how much money you want to withdraw:\n");
          scanf("%f",&cash_amount);
          control4=withdrawable_amount(cash_amount);
          
    }  
      
    fclose(ptr);
    
    return 1;    
}
    

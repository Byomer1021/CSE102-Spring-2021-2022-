 #include <stdio.h>
 #include "utils.h"
 
 int find_divisible(int x, int y, int z)
 {
    int control=0; /*in order to stop function*/
    int i=x;
   
    while(i<y)
    {
        
        if(i%z==0)
        {
            printf("The first integer between %d and %d divided by %d is %d \n",x,y,z,i);

            return i;
            control++;
        }
        i++;       
    }

    if (control==0)
    {       
        return -1;
    }
  }

int find_nth_divisible(int n, int f_I, int z)
 {    
    return f_I+z*n;
 }

int validate_identity_number(char identity_number [11])
{
   int d;
   int n,i;
   int sum_of_odd=0;   /* for 1. 3. 5. 7. 9. digits */
   int sum_of_even=0;  /* for 2. 4. 6. 8. digits */
   int sum_of_first_10_digits=0;
   int result;        /*the result of (sum_of_odd*7-sum_of_even)%10 */


if(identity_number[11]!='\0' || identity_number[0] == '0')
{
  return 0;
}
    
else
{
    for(d=0;d<11;d++)
    {
  	    if((identity_number [d] > '9') || (identity_number [d] < '0'))	
	 
	 	      break;
    }     
    
    for(n=0;n<9;n+=2)
    {
      sum_of_odd+=(int)identity_number[n]-48;       /*sum of odd*/
    }
     
    for(i=1;i<8;i+=2)
    {
       sum_of_even+=(int)identity_number[i]-48;    /*sum of even*/
    }
     
       result=((sum_of_odd*7)-sum_of_even)%10;      /*to find 10th digit*/
       
       sum_of_first_10_digits = (sum_of_odd + sum_of_even + (int)identity_number[9]-48);   /*to find 11th digit*/
     
    if (result != (int)identity_number[9]-48)
    {
      //printf("Invalid ID Number \n");
      return 0;
    }
    else if (sum_of_first_10_digits%10 == (int)identity_number[10]-48 )
    {
          //printf("Login Succesful");
        return 1;
    }
}
return 1;
   
}
int password(char pasword [4] )
{
   int d;
  
  if(pasword[4]!='\0')
  {
    return 0;
  }
   else
   {
      for(d=0;d<4;d++)
      {
           if((pasword [d] > '9') || (pasword [d] < '0'))
          {
               printf("Invalid Password");
               return 0;
          }	        
      } 
   } 
      return 1;

}
int create_customer(char identity_number , int password);

int check_login(char identity_number , int password);

int withdrawable_amount(float cash_amount)
{
  
  int k=0;
  int p=0;
  int t=0;
  int withdrawable_amount_;

    while(k*50<=cash_amount)
    {
          k++;
    }
      --k;  /*inside the box returns the k by one more so did it to prevent*/
    
    cash_amount=cash_amount-k*50;
    while(p*20<=cash_amount)
    {
          p++;
    }
      --p; /*same as upper*/
    
    cash_amount=cash_amount-p*20;
    while(t*10<=cash_amount)
    {
          t++;
    }  
      --t; /*same as upper*/

 withdrawable_amount_=k*50+p*20+t*10;
 printf("Withdrawable amount is:%d",withdrawable_amount_);
   return 1;
}

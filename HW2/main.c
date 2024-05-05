#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"


int main() {

    int sonuc1a,sonuc1b; // for functions
    double sonuc2a,sonuc2b; // for functions 
    double sonuc3a,sonuc3b;          
    double c;
    int p;  /*it means which part */
    float pl,pw; //elements of function one
    float x1,x2,x3; //elements of function two
    int x4,x5; //elements of function two

    /* Ask for the problem selection (1,2,3) .....  */

    do
    {   
        printf("Which problem do you want to solve?\n");
        printf("1:\n");
        printf("2:\n");
        printf("3:\n");
        scanf("%d",&p);
    }
    while( (p<1) || (p>3) ) ;
    
    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */

    if(p==1)
    {
        sonuc1a=dt1a(pl,pw);
        sonuc1b=dt1b(pl,pw);

         if((sonuc1a==0)&&(sonuc1b==0)) printf("Versicolor");
        
         else if((sonuc1a==0)&&(sonuc1b==1)) printf("Versicolor and Virginica");
         
         else if((sonuc1a==0)&&(sonuc1b==-1)) printf("Versicolor and Setosa ");
         
         else if((sonuc1a==1)&&(sonuc1b==0)) printf("Virginica and Versicolor");
          
         else if((sonuc1a==1)&&(sonuc1b==1)) printf("Virginica");
         
         else if((sonuc1a==1)&&(sonuc1b==-1)) printf("Virginica and Setosa");
         
         else if((sonuc1a==-1)&&(sonuc1b==-0)) printf("Setosa and Versicolor");
         
         else if((sonuc1a==-1)&&(sonuc1b==-1)) printf("Setosa");
         
         else if((sonuc1a==-1)&&(sonuc1b==1)) printf("Setosa and Virginica");
         
               
    }

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */
    
    else if(p==2)
    {
        sonuc2a=dt2a(x1,x2,x3,x4,x5);
        sonuc2b=dt2b(x1,x2,x3,x4,x5);

        if( ((sonuc2a>sonuc2b) && (sonuc2a-sonuc2b<=0.01)) || ((sonuc2b>sonuc2a) && (sonuc2b-sonuc2a<=0.01)) )
        {
            c=(sonuc2a+sonuc2b)/2;
            printf("%.1f\n",c);
        }
        else
         printf("Part2a:%.2f \nPart2b:%.2f",sonuc2a,sonuc2b);
    }     

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */


    else if(p==3)
    {
        sonuc3a=dt3a(x1,x2,x3,x4,x5);
        sonuc3b=dt3b(x1,x2,x3,x4,x5);
        
         if( ((sonuc3a>sonuc3b) && (sonuc3a-sonuc3b<=CLOSE_ENOUGH)) || ((sonuc3b>sonuc3a) && (sonuc3b-sonuc3a<=CLOSE_ENOUGH)) )
        {
            c=(sonuc2a+sonuc2b)/2;
            printf("%.1f\n",c);
        }
         else
         printf("Part3a:%.2f \nPart3b:%.2f",sonuc3a,sonuc3b);
    }

    return 0;
}

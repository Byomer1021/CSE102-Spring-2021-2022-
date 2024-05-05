#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

char dt1a(float pl,float pw)
{
       printf("Please enter Pl value: \n");
       scanf("%f",&pl);
       printf("Please enter the Pw value: \n");
       scanf("%f",&pw);
       
         if( (pl>2.45) && (pw<1.75) && (pl<4.95) && (pw<1.65) ) return 0;
         else if( (pl>2.45) && (pw<1.75) && (pl<4.95) && (pw>1.65) ) return 1;
         else if( (pl>2.45) && (pw<1.75) && (pl>4.95) ) return 1;
         else if( (pl>2.45) && (pw>1.75) ) return 1;
         else if(pl<2.45) return -1;
         

         
}

char dt1b(float pl,float pw)
{
       printf("Please enter Pl value: \n");
       scanf("%f",&pl);
       printf("Please enter the Pw value: \n");
       scanf("%f",&pw);
       
         if( (pl>2.55) && (pw<1.69) && (pl<4.85) ) return 0;
         else if( (pl>2.55) && (pw<1.69) && (pl>4.85) ) return 1;
         else if( (pl>2.55) && (pw>1.69) ) return 1;
         else if(pl<2.55) return -1;
         
}

double dt2a(float x1,float x2,float x3,int x4,int x5)
{
       double r=0;

       printf("Please enter x1,x2,and x3 as a real nuumber then enter the x4 and x5  as an integer:\n");
       scanf("%f%f%f%d%d",&x1,&x2,&x3,&x4,&x5);

       if( (x1<31.5) && (x2<-2.5) && ( (x2-0.1<=x1) && (x1<=x2+0.1) ) ) r=2.1;
       else if( (x1<31.5) && (x2<-2.5) && ( (x2-0.1>x1) || (x1>x2+0.1) ) ) r=-1.1;
       else if( (x1<31.5) && (x2>-2.5) ) r=5;
       else if( (x1>31.5) && ( (-1>x3) || (x3>2) ) && ((x4==1) && (x5==1)) ) r=-2.23;
       else if( (x1>31.5) && ( (-1>x3) || (x3>2) ) && ((x4==1) || (x5==1)) ) r=11;
       else if( (x1>31.5) && ( (-1<=x3) && (x3<=2) ) ) r=1.4;
       

       return r;
              
}


double dt2b(float x1,float x2,float x3,int x4,int x5)
{
       double r=0;

       printf("Please enter x1,x2,and x3 as a real nuumber then enter the x4 and x5 as an integer\n");
       scanf("%f%f%f%d%d",&x1,&x2,&x3,&x4,&x5);

       if( ( (12<x1) && (x1<22) ) && (x3<=5/3) && ((x1-0.1<=x3) && (x3<=x1+0.1)) ) r=1.01; 
       else if( ((12<x1) && (x1<22)) && (x3<=5/3) && ((x1-0.1>x3) || (x3>x1+0.1)) ) r=-8;
       else if( ((12<x1) && (x1<22)) && (x3>5/3) ) r=-2.0;        
       else if( ((12>=x1) || (x1>=22) ) && ((x4==1) || (x5==1)) && ( (-1<=x2) && (x2<=2) ) ) r=-1/7;   
       else if( ((12>=x1) || (x1>=22) ) && ((x4==1) || (x5==1)) && ( (-1>x2) || (x2>2) ) ) r=sqrt(2)/3;       
       else if( ((12>=x1) || (x1>=22) ) && ((x4==1) && (x5==1)) )  r=-1;

       return r;
              
}

double dt3a(float x1,float x2,int x3,int x4,int x5)
{
    double r=0;
  
          printf("Please enter x1,x2 as a real number and x3 as an integer\n");
          scanf("%f%f%d",&x1,&x2,&x3);
    do
    {      
          printf("Which day is your favourite day\n");
          printf("1) Monday\n");
          printf("2) Tuesday\n");
          printf("3) Wednasday\n");
          printf("4) Thursay\n");
          printf("5) Friday\n");
          printf("6) Saturday\n");
          printf("7) Sunday\n");
          scanf("%d",&x4);
     }while((x4<1) || (x4>7));


    do
    {
          printf("Which colour is your favourite colour\n");
          printf("1) Brown\n");
          printf("2) Red\n");
          printf("3) Blue\n");
          printf("4) Green\n");
          printf("5) Yellow\n");
          printf("6) White\n");
          printf("7) Black\n");
          printf("8) Pink\n");
          scanf("%d",&x5);
    } while ((x5<1) || (x5>8) );

    if( (x1<9.5) && (x2<x1-5) && (x2+x1<=x3) ) r= 6.309;
    else if( (x1<9.5) && (x2<x1-5) && (x2+x1>x3) ) r= 4.5;
    else if( (x1<9.5) && (x2>=x1-5) && ( (x2-x1<=x3) &&  (x3<=x2+x1) ) && (x3<3.4) )  r= 5.01;                                   
    else if( (x1<9.5) && (x2>=x1-5) && ( (x2-x1<=x3) &&  (x3<=x2+x1) ) && (x3>=3.4) ) r= 1.223;
    else if( (x1<9.5) && (x2>=x1-5) && ( (x2-x1>x3) ||  (x3>x2+x1) ) && ((x3-0.1<=x2) && (x2<=x3+0.1)) ) r= 7.98;                           
    else if( (x1<9.5) && (x2>=x1-5) && ( (x2-x1>x3) ||  (x3>x2+x1) ) && ((x3-0.1>x2) || (x2>x3+0.1)) ) r= -0.04;
    else if((x1>9.5) && (x4!=1) && (x4==0) ) r= 3.31;
    else if((x1>9.5) && (x4!=1) && (x4!=0) ) r= 4.499;
    else if((x1>9.5) && (x4==1) && (x4<x5) && (x5-3.8<x3)) r= -3.5;
    else if((x1>9.5) && (x4==1) && (x4<x5) && (x5-3.8>=x3)) r= 3.6;
    else if((x1>9.5) && (x4==1) && (x4>=x5) && ((x5+x1<x2) && (x2<x1+x3)) ) r=-9.311;
    else if((x1>9.5) && (x4==1) && (x4>=x5) && ((x5+x1>=x2) || (x2>=x1+x3)) ) r=sqrt(25);

    return r;
}

double dt3b(float x1,float x2,int x3,int x4,int x5)
{
    double r=0;
  
          printf("Please enter x1,x2 as a real number and x3 as an integer\n");
          scanf("%f%f%d",&x1,&x2,&x3);
    do
    {      
          printf("Which day is your favourite day\n");
          printf("1) Monday\n");
          printf("2) Tuesday\n");
          printf("3) Wednasday\n");
          printf("4) Thursay\n");
          printf("5) Friday\n");
          printf("6) Saturday\n");
          printf("7) Sunday\n");
          scanf("%d",&x4);
     }while((x4<1) || (x4>7));


    do
    {
          printf("Which colour is your favourite colour\n");
          printf("1) Brown\n");
          printf("2) Red\n");
          printf("3) Blue\n");
          printf("4) Green\n");
          printf("5) Yellow\n");
          printf("6) White\n");
          printf("7) Black\n");
          printf("8) Pink\n");
          scanf("%d",&x5);
    } while ((x5<1) || (x5>8) );

       
      if( (x1<x2) && ((x2-3.3<x1+5) && (x1+5<x2+3.3)) && (x2<x3-0.1)) r=6.31;
      else if( (x1<x2) && ((x2-3.3<x1+5) && (x1+5<x2+3.3)) && (x2>=x3-0.1)) r=-5;
      else if( (x1<x2) && ((x2-3.3>=x1+5) || (x1+5>=x2+3.3)) && (x2>x3) && (x3=1)) r=-7.38;
      else if( (x1<x2) && ((x2-3.3>=x1+5) || (x1+5>=x2+3.3)) && (x2>x3) && (x3!=1)) r=4.51;
      else if( (x1<x2) && ((x2-3.3>=x1+5) || (x1+5>=x2+3.3)) && (x2<x3) && (x3=0)) r=-3/4;
      else if( (x1<x2) && ((x2-3.3>=x1+5) || (x1+5>=x2+3.3)) && (x2<x3) && (x3!=0)) r=9.310;
      else if( (x1>=x2) && (x3<x4) && (x4<x5)) r=18.322;
      else if( (x1>=x2) && (x3<x4) && (x4>=x5)) r=1.985;
      else if( (x1>=x2) && (x3>=x4) && (x5<7-x1) && (x5<x4)) r=-3.499; 
      else if( (x1>=x2) && (x3>=x4) && (x5<7-x1) && (x5>=x4)) r=sqrt(3/2);
      else if( (x1>=x2) && (x3>=x4) && (x5>=7-x1) && ((x1+x2<x4+x5) && (x4+x5<x1+x2+x3))) r=-0.0039;
      else if( (x1>=x2) && (x3>=x4) && (x5>=7-x1) && ((x1+x2>=x4+x5) || (x4+x5>=x1+x2+x3))) r=3.599;

     return r;


}

/* Provide your implementations for all the requested functions here */
#include <stdio.h>
#include <math.h>
#define PI 3.14

enum shapes {triangle=1,quadrilateral,circle,pyramid,cylinder} A; /*defined enums*/
enum calculators {area=1,perimeter,volume} B;

int select_shape() /*selecettion of shape screen  */
{
    int A;
          do{  
             printf("Select a shape to calculate: \n");
             printf("1.Triangle \n");
             printf("2.Quadrilateral \n");
             printf("3.Circle \n");
             printf("4.Pyramid \n");
             printf("5.Cylinder \n");
             printf("0.Exit \n");
             scanf("%d",&A);
             getchar(); /*to prevent getting character errors*/
             if(A == 0)return 0;
             else if(A == 1) return triangle;
             else if(A == 2) return quadrilateral;
             else if(A == 3) return circle;
             else if(A == 4) return pyramid;
             else if(A == 5) return cylinder;
             else printf("Please enter a valid entry.\n");
            }while(A != 0);                   
}
int select_calc()  /*selection of calculation*/
{
    int B=4;
    do{
      printf("Select Calculator:\n");
      printf("1.Area \n");
      printf("2.Perimeter \n");
      printf("3.Volume \n");      
      scanf("%d",&B);
      getchar(); /*to prevent getting character errors*/
      if(B == 0) return 0;
      else if(B == 1) return area;
      else if(B == 2) return perimeter;
      else if(B == 3) return volume;
      else printf("ERROR ! Please enter a valid entry.\n");
      }while(B != 0);
}

int calc_triangle(int A)   /*triangle area and perimeter calculation*/
{
   float s;
   float a,b,c;
    printf("Please enter three sides of triangle\n");
    scanf("%f%f%f",&a,&b,&c);
     
     if(a<=0 || b<=0 || c<=0)
        {
            do
            {
                printf("Please enter a valid entry.\n");
                scanf("%f%f%f",&a,&b,&c);

                getchar(); /*to prevent getting character errors*/
                
            } while ((a<=0 || b<=0 || c<=0));
        }
      if (!(a+b>c && a+c>b && b+c>a && fabs(a-b)<c && fabs(c-b)<a && fabs(a-c)<b))
      {
        do
        {
            printf("Please enter a valid triangle sides.\n");
            scanf("%f%f%f",&a,&b,&c);
        getchar(); /*to prevent getting character errors*/
        }while(!(a+b>c && a+c>b && b+c>a && fabs(a-b)<c && fabs(c-b)<a && fabs(a-c)<b));
      }
        s=(a+b+c)/2;
        switch (A)
          {
             case area:
                     printf("The area of triangle is : %.2f\n",sqrt(s*(s-a))*sqrt((s-b)*(s-c)));
             break;

             case perimeter:
                      printf("The area of triangle is : %.2f\n",(a+b+c));
             break;
          }            
}

int calc_quadrilateral(int A) /*quadrilateral area and perimeter calculation*/
{
    float s;
    float a,b,c,d;          
        printf("Please enter four sides of quadrilateral\n");
        scanf("%f%f%f%f",&a,&b,&c,&d);
            
            if(a<=0 || b<=0 || c<=0 || d<=0)
            {
            do
            {
                printf("Please enter a valid entry.\n");
                scanf("%f%f%f%f",&a,&b,&c,&d);
            getchar();/*to prevent getting character errors*/
            }while (a<=0 || b<=0 || c<=0 || d<=0);
            }   
             s=(a+b+c+d)/2;
            switch (A)
            {
                 case area:
                         printf("The area of quadrilateral is : %.2f\n",sqrt((s-a)*(s-b))*sqrt((s-c)*(s-d)));
                 break;

                 case perimeter:
                          printf("The perimeter of quadrilateral is : %.2f\n",(a+b+c+d));
                 break;
            }                       
}

int calc_circle(int A) /*circle area,perimeter and volume calculation*/
{
    float r;
    int c;
    printf("Please enter the radius of circle:\n");
    scanf("%f",&r);
        
    if(r<=0)
    {
        do
        {
            printf("Please enter a valid entry.\n");
            scanf("%f",&r);
        getchar();  /*to prevent getting character errors*/  
        }while(r<=0);    
    }            
    switch(A)
    {
        case area:
            printf("Area of circle : %.2f\n",(PI*r*r));
            break;
        case perimeter:
            printf("Perimeter of circle : %.2f\n",(2*PI*r));
            break;
    }
}

int calc_pyramid(int A) /*pyramid area,perimeter and volume calculation*/
{
    float a,h;
    printf("Please enter the base side and height of a pyramid :\n");
    scanf("%f%f",&a,&h);
   
    if ((a<=0 || h <= 0))
    {
        do
        {
            printf("Please enter a valid entry.\n");
            scanf("%f%f",&a,&h);
        getchar(); /*to prevent getting character errors*/        
        } while ((a<=0 || h <= 0));
    }
    switch(A)
    {   
        case area:
            printf("Base Surface area of a pyramid : %.2f\n",(a*a));
            printf("Lateral Surface area of a pyramid : %.2f\n",(2*a*h));
            printf("Surface area of a pyramid : %.2f\n",((a*a)+(2*a*h)));
            break;
        case perimeter:
            printf("Perimeter of a pyramid : %.2f\n",4*a);
            break;
        case volume:
            printf("Volume of a pyramid : %.2f\n",(a*a*h/3));
            break;
    }
}

int calc_cylinder(int A) /*cylinder area,perimeter and volume calculation*/
{
    float r,h;
    printf("Please enter the radius and height of a cylinder :\n");
    scanf("%f%f",&r,&h);
        
     if((r <= 0 || h <= 0 ))
     {
        do
        {
            printf("Please enter a valid entry.\n");
            scanf("%f%f",&r,&h);
        getchar();  /*to prevent getting character errors*/               
        } while ((r <= 0 || h <= 0 ));
     }
    switch(A)
    {
        case area:
            printf("Base Surface area of a cylinder : %.2f\n",(PI*r*r));
            printf("Lateral Surface area of a cylinder : %.2f\n",(2*PI*r*h));
            printf("Surface area of a cylinder : %.2f\n",(2*PI*r*(r+h)));
            break;
        case perimeter:
            printf("Base Surface perimeter of a cylinder : %.2f\n",(2*PI*r));
            break;
        case volume:
            printf("Volume of a cylinder : %.2f\n",(PI*r*r*h));
            break;
    }
}

int calculate( int A(),int B()) /*function parameter*/
{
   do{ 
    int select,calculate;
    select = A();
    if(select == 0){
        printf("Exiting..\n");
        return 0;
    }
    calculate = B();
    if(calculate == 0)
    {
        printf("Exiting..\n");
        return 0;
    }
    switch(select)
    {
        case triangle: 
            switch(calculate) 
            {
                case area: 
                    calc_triangle(area);
                    break;    
                case perimeter:
                    calc_triangle(perimeter);
                    break;
                case volume:
                    printf("You cannot calculate the volume of a triangle. Please try again.\n");
                    return -1;
                    break;
            }
        break;
        case quadrilateral: 
            switch(calculate) 
            {
                case area: 
                    calc_quadrilateral(area);
                    break;
                case perimeter:
                    calc_quadrilateral(perimeter);
                    break;
                case volume:
                    printf("You cannot calculate the volume of quadrilateral. Please try again.\n");
                    return -1;
                    break;
            }
        break;
        case circle:
            switch(calculate)
            {
                case area:
                    calc_circle(area);
                    break;
                case perimeter:
                    calc_circle(perimeter);
                    break;
                case volume:
                    printf("You cannot calculate the volume of circle. Please try again.\n");
                    return -1;
                    break;
            }
        break;
        case pyramid:
            switch(calculate)
            {
                case area:
                    calc_pyramid(area);
                    break;
                case perimeter:
                    calc_pyramid(perimeter);
                    break;
                case volume:
                    calc_pyramid(volume);
                    break;
            }
        break;
        case cylinder:
            switch(calculate)
            {
                case area:
                    calc_cylinder(area);
                    break;
                case perimeter:
                    calc_cylinder(perimeter);
                    break;
                case volume:
                    calc_cylinder(volume);
                    break;
            }
        break;
    }
    }while(calculate!=0);   
}
    
int main() /*main screen*/
{
 int A;
    printf("Welcome the geometric calculator!\n");
    printf("---------------------------------------\n");
    do{
    A = calculate(select_shape,select_calc); /*calling other functions*/
    }
    while(A == -1);
}      
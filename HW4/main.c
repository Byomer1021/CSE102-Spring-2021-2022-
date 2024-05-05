#include <stdio.h>

void write_file(int a, int b, int c)
{
       FILE *ptr = fopen("coefficients.txt", "w");
       fprintf(ptr, "%d\n%d\n%d", a, b, c);
       fclose(ptr);
}
void draw_graph()
{
       int a, b, c, x, y, i;

       FILE *ptr = fopen("coefficients.txt", "r");
       if (ptr == NULL)
              printf("There is no coefficients.txt file");

       else
       {
              fscanf(ptr, "%d", &a);
              fscanf(ptr, "%d", &b);
              fscanf(ptr, "%d", &c);
              fclose(ptr);
              printf("Printing the graph of x = %d(y*y) + %d*y + %d\n", a, b, c);
              for (y = 16; y >= -16; y--)
               {
                            for (x = -55; x <= 55; x++)
                            {
                                   if (y == 16 && x == 0) printf("^");

                                   else if(x == -55 && y == 0) printf("<");

                                   else if(x == 55 && y == 0) printf(">");

                                   else if(y == -16 && x == 0)	printf("v");
                                   
                                   else if(x == y*y*a + y*b + c){
                                          printf("#");
                                   }
                                   
                                   else if (x == 0)
                                   {
                                          printf("|");
                                   }

                                   else if (y == 0)
                                   {
                                          printf("-");
                                   }

                                   else if(y == -1 && (x %10 == 9 || (-x) %10 == 1))
					{
						printf("\b\b");
						printf("\033[1;31m");
						printf("\033[1;33m");
						printf("%3d", x+1);
						printf("\033[0m");
					}
					else if(x == -1 && (y %5 == 0 || (-y) %5 == 0))
					{
						printf("\b\b");
						printf("\033[1;31m");
						printf("\033[1;33m");
						printf("%3d", y);
						printf("\033[0m");
					}

                                   else printf(" ");
                            }
                            printf("\n");
                     }
              }
}

void print_text_file(){

       int a, b, c;

       FILE *ptr= fopen("coefficients.txt", "r");
			fscanf(ptr, "%d\n%d\n%d\n", &a, &b, &c);
			fclose(ptr);

			printf("\nCoefficents has been read from coefficients.txt file.");


			FILE *ptr2= fopen("graph.txt", "w");
			
			int y, x;

			for(y= 16; y >= -15; y--)
			{
				for(x= -55; x <=55; x++)
				{
					if(x == a*(y*y) + b*y +c)	fprintf(ptr2, "#");
					else if(x == 0 && y == 16)	fprintf(ptr2, "^");
					else if(y == 0 && x == -55)	fprintf(ptr2, "<");
					else if(y == 0 && x == 55)	fprintf(ptr2, ">");
					else if(x == 0)	fprintf(ptr2, "|");
					else if(y == 0)	fprintf(ptr2, "-");

					else	fprintf(ptr2, " ");
				}
				fprintf(ptr2, "\n");
			}
			fclose(ptr2);

			printf("\nThe graph of x=%d*(y*y) + %d*y +%d has been written to graph.txt file.\n", a, b, c);

}

int main()
{
       int a, b, c;
       int op;

       do
       {
              printf("Select an operation..\n");
              printf("0 -> Enter the coefficients.\n");
              printf("1 -> Draw the graph.\n");
              printf("2 -> Print the graph into a .txt file.\n");
              printf("3 -> Exit.\n");
              printf("Choice: ");
              scanf("%d", &op);

              switch (op)
              {

              case 0:
                     printf("Please enter the coefficients for the following equations x= a*(y*y) + b*y + c \n\n");
                     printf("a: ");
                     scanf("%d", &a);
                     printf("b: ");
                     scanf("%d", &b);
                     printf("c: ");
                     scanf("%d", &c);
                     write_file(a, b, c);
                     printf("\n\ncoefficients.txt file has been created.");
                     break;

              case 1:
                     draw_graph();
                     break;

              case 2:
                     print_text_file();
                     break;

              case 3:
                     break;
                     return 0;

              default:
                     printf("Invalid input value, please try again...\n\n");
                     break;
              }

       } while (op != 3);
}
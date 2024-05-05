#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int dice()
{
    return rand() % 6 + 1; // 1-6 dice define
}

int startGame() //i designed enter screen
{
    int dice1, dice2;

    while (1) // i make it loop because it should contuine every moment
    {
        printf("\033[0;32mPlayer1...Please enter to dice.\033[0m");
        getchar();
        dice1 = dice();
        printf("\033[0;32mPlayer1..%d\033[0m\n", dice1);
        printf("\033[0;32mPlayer2...Please enter to dice.\033[0m");
        getchar();
        dice2 = dice();
        printf("\033[0;32mPlayer2..%d\033[0m\n", dice2);
        if (dice1 > dice2)
        {
            printf("\n\n\033[0;31m****Player1 starts..****\033[0m\n");
            return 1;
        }
        else if (dice2 > dice1)
        {
            printf("\n\n\033[0;31m****Player2 starts..****\033[0m\n");
            return 2;
        }
        else if (dice1 == dice2)
        {
            printf("\n\n\033[0;31mSame dice value ... Try again..\033[0m\n");
        }
    }
}

void printMap(char board[][30],int karakter1_i,int karakter1_j,int karakter2_i,int karakter2_j) //first i created map
{
    int a,b;

    for (a = 0; a < 15; a++)
    {
        for (b = 0; b < 30; b++)
        {
            if ((a == 0 || a == 14) || ((b >= 2 && b <= 27) && (a == 2 || a == 12)))
                board[a][b] = '.';
            else if ((a > 0 && a < 14) && ((b == 0 || b == 29) || (b == 2 || b == 27)))
            {
                board[a][b] = ':';
                if ((a == 1 || a == 13) && (b != 0 && b != 29))
                    board[a][b] = ' ';
            }
			else if ((a == 4 || a == 10) && (b >= 4 && b <= 25))
                board[a][b] = '.';
            else if (a == karakter1_i && b == karakter1_j)
                board[a][b] = '1';
            else if (a == karakter2_i && b == karakter2_j)
                board[a][b] = '2';
			 else if ((a >= 5 && a <= 9) && (b == 4 || b == 25))
                board[a][b] = ':';	
            else if ((a == 1 && b == 14) || (a == 7 && b == 28) || (a == 13 && b == 14) || (a == 3 && b == 10) || (a == 3 && b == 19) || (a == 5 && b == 26) || (a == 10 && b == 26) || (a == 11 && b == 10) || (a == 11 && b == 18))
                board[a][b] = 'X';
			else if ((a == 2 && b == 1) || (a == 4 && b == 3))
                board[a][b] = '_';
            else
                board[a][b] = ' ';
             printf("\033[0;36m%c\033[0m", board[a][b]);
        }
        printf("\n");
    }
}

int main()
{
    int start, winner;
    int first,second;
    char board[15][30];
    int karakter1_i = 1,karakter1_j = 1,karakter2_i = 3,karakter2_j = 3;
    printMap(board,karakter1_i,karakter1_j,karakter2_i,karakter2_j);
    srand(time(NULL));
    printf("\n\033[0;33mTo start to game,players players should dice and decide who is going to start first according to it...\033[0m\n\n");
    start = startGame();

    while (1)
    {
             printf("\033[0;32mPlayer1...Please enter to dice.\033[0m");
             getchar();
             first = dice();
             printf("\033[0;32mPlayer1..%d\033[0m\n", first);
             printf("\033[0;32mPlayer2...Please enter to dice.\033[0m");
             getchar();
             second = dice();
             printf("\033[0;32mPlayer2..%d\033[0m\n", second);
                    
		if (start == 1)	
		{           
			if (karakter1_i == 1) //to adjust up row for karakter1	
			{
				karakter1_j += first;

				if (karakter1_j == 14)	
                {
					karakter1_j -= 2;//penalty 
                    printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }    
				if (karakter1_j >= 29)	
				{
					karakter1_i += karakter1_j - 28;//to adjust column and row relation
					karakter1_j = 28;
				}
			}
			else if (karakter1_j == 28)	//to adjust column 
			{
				karakter1_i += first;

				if (karakter1_i == 7)	
                {	
					karakter1_i -= 2;//penalty 
                    printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }
				if (karakter1_i >= 14)	
				{
					karakter1_j -= karakter1_i - 13;//to adjust column and row relation
					karakter1_i = 13;
				}
			}			
			else if (karakter1_i == 13)	//to adjust down row
			{
				karakter1_j -= first;

				if (karakter1_j == 14)
                {	
					karakter1_j += 2;//penalty
                    printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }    
				if (karakter1_j <= 0)		
				{
					karakter1_i -= -karakter1_j;//to adjust column and row relation
					karakter1_j = 1;
				}
			}
			else if (karakter1_j == 1) //to adjust left column
			{
				karakter1_i -= first;

				if (karakter1_i <= 2)	
		        {
                    winner = 1;
                    break;
                }
			}
			if (karakter2_i == 3)//to adjust first row for karakter 2
			{
				karakter2_j += second;
				if ((karakter2_j == 10)||(karakter2_j == 18))	
                {
					karakter2_j -=2;//penalty
                    printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                }
				if (karakter2_j >= 27)	
				{
					karakter2_i += karakter2_j - 26;//to adjust row and column relationship
					if (karakter2_i == 5)	
                    {
						karakter2_i -=2;//penalty
                        printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                    }    
					karakter2_j = 26;
				}
			}
			else if (karakter2_j == 26)	//to adjust right column
			{
				karakter2_i += second;
				if ((karakter2_i == 5)||(karakter2_i == 10))	
                {
					karakter2_i -= 2;//penalty
                     printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                }     
				if (karakter2_i >= 12)	
				{
					karakter2_j -= karakter2_i - 11;
					karakter2_i = 11;
				}
			}
			else if (karakter2_i == 11)	//to adjust down row
			{
				karakter2_j -= second;
				if ((karakter2_j == 10)||(karakter2_j == 18)) 
					karakter2_j +=2; //to adjust row between column relationship
				if (karakter2_j <= 2)		
				{
					karakter2_i += karakter2_j - 2;
					karakter2_j = 3;
				}
			}
			else if (karakter2_j == 3)	//to adjust left column
			{
				karakter2_i -= second;
				if (karakter2_i <= 4)	
                {
                    winner = 2;
                    break;
                }                    
			}
		printf("\n");
		printMap(board,karakter1_i,karakter1_j,karakter2_i,karakter2_j);
		}
		else if (start == 2)	
		{
			if (karakter2_i == 3)	//to adjust up row for karakter2	
			{
				karakter2_j += second;
				if ((karakter2_j == 10)||(karakter2_j == 18))
                {
					karakter2_j -=2;//penalty
                     printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                }	
				if (karakter2_j >= 27)	
				{
					karakter2_i += karakter2_j - 26;//adjusting column and row
					karakter2_j = 26;
				}
			}
			else if (karakter2_j == 26)	//adjusting column
			{
				karakter2_i += second;
				if ((karakter2_i == 5)||(karakter2_i == 10))
                {	
					karakter2_i -= 2;//penalty
                     printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                }     
				if (karakter2_i >= 12)	
				{
					karakter2_j -= karakter2_i - 11;//adjunting column and row
					karakter2_i = 11;
				}
			}
			else if (karakter2_i == 11)	//adjusting row
			{
				karakter2_j -= second;
				if ((karakter2_j == 10)||(karakter2_j == 18)) 
                {
					karakter2_j +=2;//penalty
                    printf("\033[0;31m!.!!!..! Penaltyyy for 2 !.!!!..!\033[m\n");
                }
				if (karakter2_j <= 2)	
				{
					karakter2_i -= 3 - karakter2_j;
					karakter2_j = 3;
				}
			}
			else if (karakter2_j == 3)//adjusting column
			{
				karakter2_i -= second;
				if (karakter2_i <= 4)	
                {
                    winner = 2;
                    break;
                }
			}
			if (karakter1_i == 1)		//to adjust up row for karakter1	
			{
				karakter1_j += first;
				if (karakter1_j == 14)
                {	
					karakter1_j -= 2;//penalty
                     printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }     
				if (karakter1_j >= 29)	
				{
					karakter1_i += karakter1_j - 28;//adjusting row and column
					karakter1_j = 28;
				}
			}
			else if (karakter1_j == 28)	//adjusting right column
			{
				karakter1_i += first;
				if (karakter1_i == 7)	
                {	
					karakter1_i -= 2;//penalty
                    printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }
				if (karakter1_i >= 14)	
				{
					karakter1_j -= karakter1_i - 13;
					karakter1_i = 13;
				}
			}			
			else if (karakter1_i == 13)	//adjusting down row
			{
				karakter1_j -= first;
				if (karakter1_j == 14)
                {
					karakter1_j += 2;
                     printf("\033[0;31m!.!!!..! Penaltyyy for 1 !.!!!..!\033[m\n");
                }
				if (karakter1_j <= 0)	//adjusting left column	
				{
					karakter1_i -= -karakter1_j;
					karakter1_j = 1;
				}
			}
			else if (karakter1_j == 1)
			{
				karakter1_i -= first;
				if (karakter1_i <= 2)	
                {
                    winner = 1;
                    break;
                }
			}
		printf("\n");
		printMap(board,karakter1_i,karakter1_j,karakter2_i,karakter2_j);
		}
    }
    printMap(board,karakter1_i,karakter1_j,karakter2_i,karakter2_j);
    if (winner == 1)
	    	printf("\033[0;31mPLAYER 1 WON THE GAME!!!\033[m");
	else if (winner == 2)
		printf("\033[0;31mPLAYER 2 WON THE GAME!!!\033[m");
          
    return 0;
}
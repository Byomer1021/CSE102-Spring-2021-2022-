#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void words(char word[7][15])
{
    int rnd, k = 0, dup = 0;
    char temp[15];
    FILE *ptr = fopen("wordlist.txt", "r");
    if (ptr == NULL)
        printf("Error in opening file\n");
	
		for (int m = 0; m < 7; m++)
    {
    	
    	rewind(ptr);
        dup = 0;
        rnd = rand() % 40;
        for (int i = 0; i < 40; i++)
        {
            if (i == rnd)
            {
                fscanf(ptr, "%s", temp);
                for (int j = i; j >= 0; j--)
                {
                    if (strcmp(word[j], temp) == 0)
                    {
                        m--;
                        i = 50;
                        dup = 1;
                        break;
                    }
                }
                if (!dup)
                {
                    strcpy(word[m], temp);
                    rewind(ptr);
                    break;
                }
            }
            else
            {
                fscanf(ptr, "%s", temp);
            }
        }
        
    }

    fclose(ptr);

    for (int i = 0; i < 7; i++)
        printf("%s\n", word[i]);
}

void create_board(char word[7][15], char boardd[15][15])
{

    int random_x, random_y, random_dir,sp=0; //sp:superposition

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            boardd[i][j] = '#';
        }
    }

    for (int a = 0; a < 7; a++)
    {
    	sp = 0;
        random_dir = rand() % 8;
        if (random_dir == 0)//right
        {
            do
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
                
            }while (strlen(word[a])+random_x >= 15);
            for(int b = 0; b < strlen(word[a]); b++)
            {
				if(boardd[random_y][random_x+b] != '#') sp = 1;
				
			}
            if(!sp)
            {
            for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y][random_x+b] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 1)//left
        {
            do
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_x-strlen(word[a]) < 0);
            for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y][random_x-b] != '#') sp = 1;
            }
            
            if(!sp)
            {
            for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y][random_x-b] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 2)//up
        {
            do
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y-strlen(word[a]) < 0);
             for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y-b][random_x] != '#') sp = 1;
            }
            if(!sp)
            {
            for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y-b][random_x] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 3)//down
        {
            do 
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y+strlen(word[a]) >= 15);
             
            for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y+b][random_x] != '#') sp = 1;
            }
            if(!sp)
            {
            for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y+b][random_x] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 4)//upright
        {
            do
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y-strlen(word[a]) < 0 || strlen(word[a])+random_x >= 15);
             for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y-b][random_x+b] != '#') sp = 1;
            }
            if(!sp)
            {
             for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y-b][random_x+b] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 5)//upleft
        {
            do
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y-strlen(word[a]) < 0 || random_x-strlen(word[a]) < 0);
             for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y-b][random_x-b] != '#') sp = 1;
            }
            if(!sp)
            {
             for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y-b][random_x-b] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 6)//downright
        {
            do 
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y+strlen(word[a]) >= 15 || strlen(word[a])+random_x >= 15);
             for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y+b][random_x+b] != '#') sp = 1;
            }
            if(!sp)
            {
             for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y+b][random_x+b] = word[a][b];
            }
            }else a--;
        }
        if (random_dir == 7)//downleft
        {
            do 
            {
                random_x = rand() % 15;
                random_y = rand() % 15;
            }while (random_y+strlen(word[a]) >= 15 || random_x-strlen(word[a]) < 0);
             for(int b = 0; b < strlen(word[a]); b++)
            {
    	        if(boardd[random_y+b][random_x-b] != '#') sp = 1;
            }
            if(!sp)
            {
             for (int b = 0; b < strlen(word[a]); b++)
            {
                boardd[random_y+b][random_x-b] = word[a][b];
            }
            }else a--;  
        }
    }
    for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			random_dir = rand()%26 + 97;
			if(boardd[i][j] == '#') boardd[i][j] = random_dir;
		}
	}
}

void game(char word[7][15],char boardd[15][15])
{
    int hearts=3;
    char row[15];
    char column[15];
    int points=0;
     
      if(hearts!=0)
      {
          for(int i=0; i<7; i++)
        {
            
        printf("Enter coordinates and word:");
        scanf("%s", row);

        if(row[0] != ':' && row[1] != 'q')
        {
            scanf("%s%s",column,word);


            if(strcmp(word[i], row)==0 && (strcmp(word[i], column)==0) )
            {
                 printf("Founded! You got 2 points. Your total point is: %d\n", points + 2);
                points += 2;
            }

        }

          
        }

         
      }

  
    


    if(points==14) printf("Congrats!!! You won the game...");
    else printf("Game finished :(( You  have %d points",points);








}

void write_board(char boardd[15][15], char word[7][15])
{
    // words(word);

    for (int a = 0; a < 15; a++)
    {
        for (int b = 0; b < 15; b++)
        {
            printf("%c ", boardd[a][b]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    char word[7][15];
    char boardd[15][15];
    words(word);
    create_board(word, boardd);
    write_board(boardd, word);
    game(word,boardd);
}

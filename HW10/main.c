#include <stdio.h>
#include <stdlib.h>
#define STACK_BLOCK_SIZE 10

typedef struct
{
    int *array;
    int currentsize;
    int maxsize;
} stack;

int push(stack *s, int d) /* the stack array will grow STACK_BLOCK_SIZE entries at a time */
{
    s->array[s->currentsize++] = d;
    // s->currentsize++;
    return 0;
}
int pop(stack *s) /* the stack array will shrink STACK_BLOCK_SIZE entries at a time */
{

    (s->currentsize)--;
    s->array[s->currentsize] = 0;
    return 0;
}

void move(stack * src, stack * dest, int d, int from, int to)    //adımları oynatan fonksiyon
{
    push(dest, d);
    printf("Move the disk %d from '%d' to '%d'\n", d, from, to);
    pop(src);
}

int init(stack *s) /* returns 1 if initialization is successful */
{
    if (s == NULL)
        return 0;
    return 1;
}

stack *init_return() /* initializes an empty stack */
{
    stack *isim;
    isim = (stack *)malloc(sizeof(stack));
    isim->array = (int *)calloc(STACK_BLOCK_SIZE, sizeof(int));
    isim->currentsize = 0;
    isim->maxsize = STACK_BLOCK_SIZE;
    if (init(isim) == 0)  printf("Error");

    else return isim;
}

void game_loop(stack *bir, stack *iki, stack *uc, int size)  //
{

    int check;

    for (int i = 0; i < size; i++)
    {
        bir->array[i] = size - i;
    }

    bir->currentsize = size;

    while (1)
    {
     /* for (int i = 0; i < size; i++)
        {
            printf("%d, ", bir->array[i]);
            printf("%d, ", iki->array[i]);
            printf("%d, ", uc->array[i]);
            printf("\n");
        }

            printf("\nbir: %d\n", bir->currentsize);
            printf("\niki: %d\n", iki->currentsize);
            printf("\nuc: %d\n", uc->currentsize);*/

        if (!(size % 2)) //çiftler için adımlar
        {
            if (bir->array[bir->currentsize - 1] < iki->array[iki->currentsize - 1] || iki->array[iki->currentsize - 1] == 0)  move(bir, iki, bir->array[bir->currentsize - 1], 1, 2);
        
            else  move(iki, bir, iki->array[iki->currentsize - 1], 2, 1);

            if (uc->currentsize == size)   return ;

            if (bir->array[bir->currentsize - 1] < uc->array[uc->currentsize - 1] || iki->array[iki->currentsize - 1] == 0) move(bir, uc, bir->array[bir->currentsize - 1], 1, 3);
            
            else move(uc, bir, uc->array[uc->currentsize - 1], 3, 1);
            
            if (uc->currentsize == size) return ;
            
            if (iki->array[iki->currentsize - 1] < uc->array[uc->currentsize - 1] || iki->array[iki->currentsize - 1] == 0) move(iki, uc, iki->array[iki->currentsize - 1], 2, 3);
            
            else move(uc, iki, uc->array[uc->currentsize - 1], 3, 2);

            if (uc->currentsize == size)  return ;
        }
        else //tekler için adımlar
        {

            if (bir->array[bir->currentsize - 1] < uc->array[uc->currentsize - 1] || iki->array[iki->currentsize - 1] == 0) move(bir, uc, bir->array[bir->currentsize - 1], 1, 3);
            
            else   move(uc, bir, uc->array[uc->currentsize - 1], 3, 1);

            if (uc->currentsize == size)   return ;
            
            if (bir->array[bir->currentsize - 1] < iki->array[iki->currentsize - 1] || iki->array[iki->currentsize - 1] == 0)   move(bir, iki, bir->array[bir->currentsize - 1], 1, 2);
            
            else   move(iki, bir, iki->array[iki->currentsize - 1], 2, 1);
           
            if (uc->currentsize == size)    return ;
            
            if (iki->array[iki->currentsize - 1] < uc->array[uc->currentsize - 1] || iki->array[iki->currentsize - 1] == 0)     move(iki, uc, iki->array[iki->currentsize - 1], 2, 3);
            
            else   move(uc, iki, uc->array[uc->currentsize - 1], 3, 2);

            if (uc->currentsize == size)    return ;
        }
    }
}

int main()
{
    stack *bir, *iki, *uc;

    int size;

    printf("Enter stack size: ");
    scanf("%d", &size);
    
    bir = init_return();
    iki = init_return();
    uc = init_return();

    if(size>STACK_BLOCK_SIZE) //bellekte yer açtım
    {
    bir->array = (int *)realloc(bir->array, size*sizeof(int));
    iki->array = (int *)realloc(iki->array, size*sizeof(int));
    uc->array = (int *)realloc(uc->array, size*sizeof(int));
    }
    
    for (int i = 0; i < bir->maxsize; i++) bir->array[i] = 0;
    for (int i = 0; i < iki->maxsize; i++) iki->array[i] = 0;
    for (int i = 0; i < uc->maxsize; i++) uc->array[i] = 0;

    game_loop(bir, iki, uc, size);

    return 0;
}
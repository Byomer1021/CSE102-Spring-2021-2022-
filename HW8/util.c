#include "util.h"

void generate_sequence (int xs, int currentlen, int seqlen,int *seq)
{    
        if(seqlen!=0)
        {
            if(xs%2==0)
            {
				seq[currentlen] = xs;
                xs=xs/2;
            }
            else
            {
				seq[currentlen] = xs;
                xs=(3*xs)+1;
            }
        }
        else
        {
                return ;
        }
		currentlen = currentlen + 1;	//Current lenght is incremented
		seqlen--;
	    generate_sequence(xs,currentlen,seqlen,seq);
   return ;
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
        int control =1,x,y,z,m,same = 0,temp = 0;
        int *half_1 = malloc(sizeof(int)*(looplen));   
		int *half_2 = malloc (sizeof(int)*(looplen));

		while (control)
		{
			m = 0;
            for (x = temp; x < looplen + temp; x++)    
			{                
				half_1[m] = arr[x];
				m++;
			}
			
			m = 0;
            for(z=x;z<x+looplen;z++)
            {
                half_2[m] = arr[z];
				m++;
            }

			for (x = 0; x < looplen; x++)
			{
				if (half_1[x] == half_2[x])
					same+=1;
			}
				if (same == looplen)     
				{
					*ls = temp;              
					*le = temp + looplen - 1;     		
					return (1);
				}

				else if (looplen * 2 + temp == n)  
				{
					control = 0;
				}
			temp++;
			same = 0;  
		}
		free(half_1);    
		free(half_2);
	return (0);
}

void check_loop_iterative(void (*f)(int,int,int,int *), int xs, int seqlen, int *loop, int *looplen)
{
	int *arr = malloc(sizeof(int)*seqlen);
	f(xs,0,seqlen,arr);
	int ls,le,k,x;

	if (*looplen == seqlen/2)		//Loop print
	{
		printf("\nSequence: {");
		for (int i = 0; i < seqlen; i++)
		{
			printf("%d, ",arr[i]);
		}
		printf("\b\b}\n\n");
	}
	
    if (*looplen >= 2) 
	{
		printf("Checking if there is a loop length %d...\n\n",(*looplen));
		
		int answer = has_loop(arr,seqlen,*looplen,&ls,&le);
		
		if (answer == 1)
		{
			printf("\n\n\nLoop detected with a lenght of %d.\n\n",*looplen);
			printf("The indexes of the loop's first occurance: %d(first digit), %d(last digit)\n\n",ls,le);

			int m = 0;
			for (x = ls; x <= le; x++)	
			{
				loop[m] = arr[x];
				m++; 
			}
		}
		else   
		{
			free(arr);
            *looplen -= 1;
			check_loop_iterative(f,xs,seqlen,loop,looplen);
		}
	}
	else
	{
		*looplen = 0;
		printf("No loop found.\n"); 
	}
}

void hist_of_firstdigits(void (*f)(int, int, int, int *), int xs, int seqlen, int *h, int digit)
{
	if (digit > seqlen - 1)
		return ;
	
	else
	{
		int *sequence = malloc(sizeof(int)*seqlen);
		f(xs,0,seqlen,sequence);

		while(sequence[digit] >= 10)	sequence[digit] /= 10;

		h[sequence[digit]-1] += 1;
		free(sequence);

		hist_of_firstdigits(f,xs,seqlen,h,++digit);

	}
}

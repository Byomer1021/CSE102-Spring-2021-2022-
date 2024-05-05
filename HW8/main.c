#include "util.h"

int main()
{ 
    int xs,currentlen,seqlen,*seq, flag;
    
    printf("\nPlease enter sequence length: ");
    scanf("%d",&seqlen);
    printf("\nPlease enter the first element: ");
    scanf("%d",&xs);

	int *loop = calloc(seqlen,sizeof(int));//Loop pointer is here
    int looplen = seqlen/2;

    check_loop_iterative(generate_sequence, xs, seqlen, loop, &looplen);

	printf("Loop : {");
	for (flag = 0; flag < looplen; flag++)
	{
		printf("%d, ",loop[flag]);
	}
	printf("\b\b}\n\n");

	int *his = (int *)calloc(9,sizeof(int));	//Histogram of first digits
	currentlen = 0;
	hist_of_firstdigits(generate_sequence,xs,seqlen,his,currentlen);

	printf("Histogram of the sequence: {");
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ", his[i]);
	}
	printf("\b\b}\n");

    return 0;
}
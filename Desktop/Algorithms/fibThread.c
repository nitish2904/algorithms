#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n;    // size of fibonacci sequence.
int *fibseq; // arry holds the value of each fibonacci term.

void *fibonacci(void *arg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("format is:./a.out <intgervalue>\n");
        return -1;
    }  // valdiate num of args.

    if (atoi(argv[1]) < 0)
    {
        printf("%d must be>=0\n", atoi(argv[1]));
        return -1;
    }  // valdiate value of arg1.

    n = atoi(argv[1]);
    fibseq = (int *)malloc(n * sizeof(int)); //creating array of size n
    pthread_t tid;
    pthread_attr_t attr;   

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, fibonacci, NULL); // creating thread
    pthread_join(tid, NULL); // waiting for thread to finish

    // printing fibseq.
    printf("The Fibonacci sequence: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d, ", fibseq[k]);
    }   // End of printing fibseq.
	printf("\n");
    return 0;
}  // End of main.


// thread for generating n terms of fibonnaci sequence
void *fibonacci(void *arg)
{
	fibseq[0]=0;
	fibseq[1]=1; //base case
	for(int i=2;i<n;i++){
		fibseq[i]=fibseq[i-1]+fibseq[i-2];	
	}
        pthread_exit(0); // thread exit.
}       

#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>  //getpid()'s header

void usage(char *);
void display(int *, int, int);
int N;  // number of elements
int *A; // array to be sorted

int main(int argc, char *argv[]){
    int i; //index
    int x; //random number
    int s; //starting value

    if(argc < 4)                //wrong usage handler
        usage(argv[0]);
    N = atoi(argv[2]);
    if(argc == 5)
        s = atoi(argv[4]);
    A = malloc(N*sizeof(int));  //mempry allocation
    assert(A != NULL);

    srand(getpid());

    switch(argv[3][0]){
        case 'A':
            x = (s > 0) ? s : 1;
            for(i=0; i<N; i++)
                A[i] = x++;
            break;
        case 'N':
            x = (s > 0) ? s : 1;
            for(i=0; i<N; i++)
                A[i] = x++;
            for(i=0; i<4; i++){
                int t, x, y;
                x = rand()%N;
                y = rand()%N;
                t = A[x];
                A[x] = A[y];
                A[y] = t;
            }
            break;
        case 'D':
            x = (s > 0) ? s : N;
            for(i=0; i<N; i++)
                A[i] = x--;
            break;
        case 'R':
            x = (s > 0) ? s : 1;
            for(i=0; i<N; i++)
                A[i] = x++;
            for(i=0; i<N; i++){
                x = rand()%N;
                int t = A[i];
                A[i] = A[x];
                A[x] = t;
            }
            break;
        default :
            usage(argv[0]);
            break;
    }
    printf("Before sorting: ");
    display(A, 0, N);
    int j=0;
    switch(argv[1][0]){
        case 'i':
            insertionSort(A,0,N-1);
            break;
        case 's':
            selectionSort(A,0,N-1);
            break;
        case 'b':
            bubbleSort(A,0,N-1);
            break;
        case 'h':
            shellSort(A,0,N-1);
            break;
        case 'q':
            quickSort2(A,0,N-1);
            break;
        case 'm':
            mergeSort(A,0,N-1);
            break;
        default:
            usage(argv[0]);
            break;
    }
    printf("After sorting: ");
    display(A,0,N);

    //printf("#compares: %d, #swaps: %d, #moves: %d ",ncompares,nswaps,nmoves);

    return 0;
}

void usage(char *prog){
    fprintf(stderr, "Usage: %s Algo Size Dist [Seed]\n", prog);
    fprintf(stderr, "Algo = bubble|selection|insertion|quick|shell|merge + Sort, Dist = A|D|R|N\n");
    exit(1);
}

void display(int *a, int lo, int hi){
    for(int i=0; i<hi; i++)
        printf("%d ",a[i]);
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h>

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

void local_max(int *, int, int);

int main() {
    int N;
    int M;
    int i;
    int *A;

    printf("\nEnter the number of elements: ");
    scanf("%d", &N);
    
    printf("\nEnter the number of local range to find the max element: ");
    scanf("%d", &M);

    A = malloc(N * sizeof(int));
    if (A == NULL) {
        printf("\nAn error occurred whilst trying to allocate memory for the array A with size %d * 4 bytes!\n", N);
        perror(errno);
        exit(EXIT_FAILURE);
    }
   
    srand(10);
    for (i = 0; i < N; i++) {
        A[i] = rand() % 10 + 1;
        printf("\nA[%d] = %d", i, A[i]);
    }

    local_max(A, N, M);

    free(A);
    exit(EXIT_SUCCESS);
}

void local_max(int A[], int N, int M) {
    if (N <= 0) {
        printf("Invalid number %d of local maxes!\nLocal maxes' value should be greater or equal to 1");
        return;
    }

    int i, j;
    bool isLocalMax;
    printf("\n");
    for (i = M; i < N - M; i++) {
        isLocalMax = true;
        for (j = i - M; j <= i + M; j++) {
            if (i != j) {
                //printf("\nA[%d] = %d > A[%d] = %d", i, A[i], j, A[j]);
                if (A[i] > A[j]) {
                    //printf("\t TRUE");
                } else {
                    //printf("\t FALSE");
                    isLocalMax = false;
                    break;
                }
            }
        }
        //printf("\n");

        if (isLocalMax) {
            printf("\n");
            for (j = i - M; j <= i + M; j++) {
                if (j == i - M)
                    printf("%d", A[j]);
                else if (j == i)
                    printf("-\x1B[31m%d\x1B[0m", A[i]);
                else 
                    printf("-%d", A[j]);
            }
        }
    }
}
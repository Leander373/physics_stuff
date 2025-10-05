#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Input needs to include exactly one number!\n");
        return EXIT_FAILURE;
    }

    int num = atoi(argv[1]);        // number of fibonacchi
    if(num <= 1) {
        fprintf(stdout, "Common, that's trivial, even for someone like you ;)\n");
    }

    double *fibo = calloc(num, sizeof(double));        // Allocate space for fibo array
    if (fibo == NULL) {                                 // Error handling
        fprintf(stdout, "ERROR: Unable to allocate array!\n");
        return EXIT_FAILURE;
    }

    *fibo = 0;
    *(fibo + 1) = 1;
    for (int i = 2; i < num; i++) {
        *(fibo + i) = *(fibo + i - 1) + *(fibo + i - 2);
    }

    fprintf(stdout, "The %ith fibo number is %lf\nThank you\n", num, *(fibo + num - 1));

    free(fibo);
    
    return EXIT_SUCCESS;
}
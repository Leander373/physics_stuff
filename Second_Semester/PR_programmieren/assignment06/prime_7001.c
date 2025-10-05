#include <stdio.h>
#define NUM 7001
// Authors: Mario Neuner, Leander Decristoforo

int main(void) {
    int count = 0, validation = 0;  // 0 means prime, 1 not
    long double result = 0, run = 2;
    while (count != NUM) {
        for (int i = 2; (i * i) <= run; i++) {
            // Check if prime
            if (((long long)run % i) == 0) {
                validation = 1;
            }
        }
        if (validation == 0) {
            count++;
            result = run;
        }
        run++;
        validation = 0;
    }
    printf("The 7001st prime is %Lf\n", result);
}
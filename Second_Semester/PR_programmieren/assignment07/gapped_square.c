#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Authors: Mario Neuner, Leander Decristoforo

long long power_10(int power) {
    long long result = 1;
    for (int i = 0; i < power; i++) {
        result *= 10;
    }
    return result;
}

int main (void) {
    long long num = 1010100000, result = 0;
    bool found = false;
    // Loop through numbers
    while (found == false && num < 1390000000) {      // ~sqrt(1930000000000000000)
         // Increment variable
        num += 10;

        result = num * num;
        found = true;

        if (num == 1010101010) {
            fprintf(stdout,"Found 1010101010\n");
            found = false;
            continue;
        }

        // Check second 5 conditions
        for (int i = 4; i >= 0; i--) {
            if ((result / power_10(2 * i)) % 10 != i) {
                found = false;
                break;
            }
        }

        // If conditions so far false, continue
        if (found == false) {
            continue;
        }

        // Check first 5 conditions
        for (int i = 1; i <= 5; i ++) {
            if ((result / power_10(20 - 2*i)) % 10 != i) {
                found = false;
                break;
            }
        }
    }

    fprintf(stdout, "The number is %lld with the square %lld\n", num, result);
    return EXIT_SUCCESS;
}
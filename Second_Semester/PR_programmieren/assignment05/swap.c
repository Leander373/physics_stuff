#include <stdio.h>
// AUTOR/IN: Leander Decristoforo

void swap(int *zahl1, int *zahl2);
void ausgabe(int zahl1, int zahl2);

int main(void) {
    int erste = 1234;
    int zweite = 5678;

    ausgabe(erste, zweite);
    swap(&erste, &zweite);
    ausgabe(erste, zweite);

    return 0;
}

// Swap two values
void swap(int *zahl1, int *zahl2) {
    int current = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = current;
}
void ausgabe(int zahl1, int zahl2) {
    printf("Erste Zahl:\t%i\tZweite Zahl:\t%i\n", zahl1, zahl2);
}

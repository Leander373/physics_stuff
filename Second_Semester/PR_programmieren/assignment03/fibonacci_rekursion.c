// AUTOR/IN: Leander Decristoforo

#include <stdlib.h>
#include <stdio.h>

unsigned long berechne_fibonacci_zahl(long zahl) {
    if (zahl <= 2) {
        return 1;
    }
    // Fügen Sie hier Ihre Implementierung ein
    return berechne_fibonacci_zahl(zahl - 2) + berechne_fibonacci_zahl(zahl - 1);
}

// Diese Funktion bricht das Programm ab falls die Eingabe nicht stimmt
void falsche_eingabe() {
    printf("Bitte eine einzelne positive Zahl angeben!\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        falsche_eingabe();
    }

    int zahl = atoi(argv[1]);

    if (zahl <= 0) {
        falsche_eingabe();
    }

    unsigned long fibonacci = berechne_fibonacci_zahl(zahl);
    printf("Die %i-te Fibonacci Zahl ist %lu.\n", zahl, fibonacci);

    return 0;
}

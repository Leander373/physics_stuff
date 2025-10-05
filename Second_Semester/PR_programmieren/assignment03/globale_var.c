// AUTOR/IN: Leander Decristoforo

/* Frage (im C-File als Kommentar zu beantworten): Warum müssen diese globalen Variablen, 
im Gegensatz zu Lokalen, nicht mit einem Wert initialisiert werden? 
Answer: because global variables are initialized to 0 per default */

#include <stdio.h>
// Now Zahl_GLOBAL is a global variable since it is not declared in a block 
int ZAHL_GLOBAL = 100;

int main(void) {
    int zahl_lokal = 10;
    printf("Lokale Variable: %i\n", zahl_lokal);
    printf("Globale Variable: %i \n", ZAHL_GLOBAL);
    return 0;
}

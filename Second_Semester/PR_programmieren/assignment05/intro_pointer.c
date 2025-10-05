#include <stdio.h>
// AUTOR/IN: Leander Decristoforo

int main() {
   int *zeiger;
   int zahl = 29;

   printf("Adresse von zahl: %p\n", (void *)&zahl);
   printf("Wert von zahl: %d\n\n", zahl);

   printf("zeiger bekommt die Adresse von zahl.\n");
   zeiger = &zahl;

   printf("Wert von zeiger: %p\n", (void *)zeiger);
   printf("Wert des Speichers an der Stelle auf die zeiger zeigt: %d\n\n", *zeiger);

   printf("Wert von zahl wird auf 36 gesetzt.\n");
   zahl = 36;

   printf("Wert von zeiger: %p\n", (void *)zeiger);
   printf("Wert des Speichers an der Stelle auf die zeiger zeigt: %d\n\n", *zeiger);

   printf("Wert des Speichers an der Stelle auf die zeiger zeigt wird auf 7 gesetzt.\n");
   *zeiger = 7;

   printf("Adresse von zahl: %p\n", (void *)&zahl);
   printf("Wert von zahl: %d\n\n", zahl);

   return 0;
}

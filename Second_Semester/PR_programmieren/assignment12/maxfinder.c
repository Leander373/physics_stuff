#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "stats.h"


/*
// Scan data into arrays
int arrays(double *t, double *m, int size) {
  FILE *file = fopen("timeseries.dat", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return -1;
  }

  // Scan data into arrays
  for (int i = 0; i < size; i++) {
    if (fscanf(file, "%lf;%lf", &t[i], &m[i]) != 2) {
      fprintf(stderr, "Error reading data\n");
      fclose(file);
      return -1;
    }
  }

  // Close and return
  fclose(file);
  return 0;
}

// Find maximum value in array
int maximum(double *m, double *t, int size) {
  double max = m[0], temp = t[0];

  for (int i = 0; i < size; i++) {
    if (m[i] > max) {
      max = m[i];
      temp = t[i];
    }
  }  

  // Print the maximum value and its time
  fprintf(stdout, "Maximum value: %lf at time: %lf\n", max, temp);

  return 0;
}
*/



int main(void) { //(int argc, char **argv) {

  // Allocate memory 
  double *t = malloc(MAX_SIZE * sizeof(double)); // Zeitpunkte in Sekunden
  if (t == NULL) {
    fprintf(stderr, "Memory allocation failed for time array\n");
    return EXIT_FAILURE;
  }

  double *m = malloc(MAX_SIZE * sizeof(double)); // Messwerte in arbiträren Einheiten
  if (m == NULL) {
    fprintf(stderr, "Memory allocation failed for measurement array\n");
    free(t);
    return EXIT_FAILURE;
  } 

  /* Hier fehlt Ihre Implementierung */
  if (arrays(t, m, MAX_SIZE) != 0) {
    free(t);
    free(m);
    return EXIT_FAILURE;
  }
  if (maximum(m, t, MAX_SIZE) != 0) {
    free(t);
    free(m);
    return EXIT_FAILURE;
  }

  // Free allocated memory
  free(t);
  free(m);
  return 0;
}

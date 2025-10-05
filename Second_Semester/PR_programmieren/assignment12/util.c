#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(double *array, int length) {
  int i = 0;
  for (i = 0; i < length; i++) {
    printf("%lf\n", array[i]);
  }
}

/* Hier fehlt Ihre Implementierung */
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

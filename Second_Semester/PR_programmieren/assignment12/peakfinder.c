#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "stats.h"

// Function for finding peaks
double *find_peaks(double *m) {
  // Allocate and initialize peaks array
  double *peaks = calloc(MAX_SIZE, sizeof(double));
  if (peaks == NULL) {
    fprintf(stderr, "Memory allocation failed for peaks array\n");
    return NULL;
  }

  double dev = 3 * standard_dev(m, mean(m, MAX_SIZE), MAX_SIZE);
  double mean_val = mean(m, MAX_SIZE);

  // Check for peaks
  for (int i = 0; i < MAX_SIZE; i++) {
    if (absolute(m[i] - mean_val) > dev) {
      peaks[i] = 1;
    }
  }

  return peaks;
}


int main(void) {
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

  // Read data from file
  FILE *file = fopen("timeseries.dat", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return EXIT_FAILURE;
  }

  // Scan data into arrays
  for (int i = 0; i < MAX_SIZE; i++) {
    if (fscanf(file, "%lf;%lf", &t[i], &m[i]) != 2) {
      fprintf(stderr, "Error reading data at index %d\n", i);
      fclose(file);
      free(t);
      free(m);
      return EXIT_FAILURE;
    }
  }

  // Print # datapoints and time
  fprintf(stdout, "Anzahl der Punkte: %d, Abgedeckte Zeitdauer: %lf Sekunden\n", MAX_SIZE, t[MAX_SIZE - 1]);

  // Print stand dev and mean
  double mean_val = mean(m, MAX_SIZE);
  double std_dev = standard_dev(m, mean_val, MAX_SIZE);
  fprintf(stdout, "Mittelwert: %lf, Standardabweichung: %lf\n", mean_val, std_dev);

  // Find peaks
  double *peaks = find_peaks(m);
  int count = 0;

  for (int i = 0; i < MAX_SIZE; i++) {
    if (peaks[i] == 1) {
      fprintf(stdout, "Ergebnis bei: %1lf s\n", t[i]);
      count++;
    }
  }
  fprintf(stdout, "Insgesamt wurden %d Ereignisse detektiert\n", count);

  free(t);
  free(m);
  return EXIT_SUCCESS;
}
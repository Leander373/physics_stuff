#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Absolute value function
double absolute(double x) {
  return (x < 0) ? -x : x;
}

// Maximum value in array
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


// Mean value in array
double mean(double *m, int size) {
  double sum = 0.0;

  for (int i = 0; i < size; i++) {
    sum += m[i];
  }

  return sum / size;
}


// Standard deviation in array
double standard_dev(double *m, double mean, int size) {
  double sum = 0.0;

  for (int i = 0; i < size; i++) {
    sum += (m[i] - mean) * (m[i] - mean);
  }

  return sqrt(sum / size);
}
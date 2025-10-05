#ifndef STATS_H
#define STATS_H

#define MAX_SIZE 500

int maximum(double *m, double *t, int size);

// Part d additions
double absolute(double x);

double mean(double *m, int size);

double standard_dev(double *m, double mean, int size);

#endif

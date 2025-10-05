#include <stdio.h>
#include <stdlib.h>
// AUTOR/IN: Leander Decristoforo

int *berechne_fibonacci(int zahl);

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Geben Sie an wie viele Elemente der Fibonacci Folge berechnet werden sollen!\n ");
    return 1;
  }
  else {
    // Get length
    int n = atoi(argv[1]);
    if (n > 0) {
      int *f = berechne_fibonacci(n);

      if (f != NULL) {
        int i;
        for (i = 0; i < n; i++) {
          printf("Fibonacci[%d] = %d\n", i + 1, f[i]);
        }
        // Free space
        free(f);
        return 0;
      }
      else {
        printf("Kein Array erhalten!");
        return 1;
      }
    }
    else {
      printf("Geben Sie eine positive ganze Zahl ein!");
      return 1;
    }
  }
}

int *berechne_fibonacci(int zahl) {
  if (zahl <= 0) {
    return NULL;
  }
  else {
    // Allocate memory 
    int *array = malloc(zahl * sizeof(int));
    if (array == NULL) {
      fprintf(stderr, "Not enough disk space, sorry :'(\n");
      return NULL;
    }

    if (zahl == 1) {
      array[0] = 1;
      return array;
    }
    else {
      array[0] = 1;
      array[1] = 1;
      int i;
      for (i = 2; i < zahl; i++) {
        array[i] = array[i - 2] + array[i - 1];
      }
      return array;
    }
  }
}
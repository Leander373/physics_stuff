#include <stdio.h>
#include <stdlib.h>
// AUTOR/IN: Leander Deristoforo

/* I used fprintf and maybe some unnecessary coding for this exercise,
but I want to practice these aspects as well, since I am quite familiar
with the c-programming*/

int main(int argc, char *argv[]) {
    // Variables for side lengths
    float a = 0, b = 0, c = 0;

    // Check for errors 
    if(argc != 4) {
        fprintf(stderr, "USAGE: ./quader <a> <b> <c>\n");
        return EXIT_FAILURE;
    }

    // Convert numbers
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    // Calculate area
    float area = 2*a*b + 2*b*c + 2*c*a;

    fprintf(stdout, "Ein Quader mit den Seitenlängen %f, %f und %f hat die Oberfläche %f\n", a, b, c, area);
}
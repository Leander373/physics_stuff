#include <stdio.h>
// Authors: Mario Neuner, Leander Decristoforo

int main(void)
{
    // definition of required variables
    float chips_in_total = 50;
    float chips_drawn = 9;
    float zehn_€_chips = 10;

    // computation of expected value via standard formula
    float erwartungswert = (chips_drawn * zehn_€_chips / chips_in_total);

    // print statement for result
    printf("The expected value for this draw is %.3f\n", erwartungswert);

    return 0;
}
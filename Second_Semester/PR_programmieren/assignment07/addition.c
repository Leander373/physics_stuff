#include <stdlib.h>
#include <stdio.h>
// Authors: Mario Neuner, Leander Decristoforo

int main(void) {
    // Allocate space for arrays
    int *result = malloc(50 * sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "ERROR: Not enough space for array allocation!\n");
        return EXIT_FAILURE;
    }
    
    // Initialize result array to zeros
    for (int i = 0; i < 50; i++) {
        result[i] = 0;
    }
    
    char nums[1200] = "938918109104763030378298060435209454570337033832208107028336258962907398456122018498417907494478410755380600453184341943028894395317925438761862988586773811519732953080089495558303181232598473471190479192252532428378139378604521250990199661707294115423620711595754899754826117524788273053060335773963910542967023024865247915845770374684673471907942001603553176858278177590926051378484248843218534218147200758339157960467834764358020492730045830851789351845249454170875149066364514199245176733372623543503890590518560010217087683491011990041819754945937694371059979861925182491763902773726033475577858875320263220296298564379925173162161180148528310774788618290387681329176354613966320620124811402830007484718820052976773558002519515500144029299463407976159559881045090340748548239579329785688397598218690608090519487400861064879010043676266098954057538395018586648724567206882185444133113309976646345680332049232490953196721887231383985910032402576834258527018945002097393431193049087468113239903212544032434049809268342509900799674281606393072098162086926866392218636949525930967896095133074700401984868148717389146262566941314966875159563321547859891752767931154781412383568277849214677089492562374";
    
    // Addition
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 40; j++) {
            // Calculate the correct index: Start from end of string and move backwards
            int index = 1199 - i*40 - j;
            if (index >= 0) {
                int digit = nums[index] - '0';
                // Add to corresponding position in result
                int pos = 49 - j;
                int sum = result[pos] + digit;
                result[pos] = sum % 10;
                
                // Add the rest to higher digits
                if (sum >= 10) {
                    if (pos > 0) {
                        result[pos-1] += sum / 10;
                    }
                }
            }
        }
    }
    
    // Print sum
    fprintf(stdout, "The result (sum) is:\n");
    
    // Find first non-zero digit
    int first_non_zero = 0;
    while (first_non_zero < 49 && result[first_non_zero] == 0) {
        first_non_zero++;
    }
    
    // Print from first non zero digit to least
    for (int i = first_non_zero; i < 50; i++) {
        fprintf(stdout, "%d", result[i]);
    }
    fprintf(stdout, "\n");
    
    free(result);
    return EXIT_SUCCESS;
}
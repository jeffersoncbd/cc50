#include <cs50.h>
#include <stdio.h>

int main(void) {
    int llamas;
    int initial_value;
    int final_value;
    int years = 0;

    do {
        initial_value = get_int("Valor inicial: ");
    } while (initial_value < 9);
    do {
        final_value = get_int("Valor final: ");
    } while (final_value < initial_value);

    llamas = initial_value;

    while (llamas < final_value) {
        llamas = llamas + (llamas / 3) - (llamas / 4);
        years++;
    }

    printf("Anos necessários: %i\n", years);
}
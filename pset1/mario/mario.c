#include <cs50.h>
#include <stdio.h>

int askHeight(void);
void printPyramid(int height);

int main (void) {
    int height = askHeight();
    printPyramid(height);
}

int askHeight(void) {
    int height = 0;
    while (height < 1 || height > 8) {
        height = get_int("Altura: ");
    }
    return height;
}

void printPyramid(int height) {
    // Altura
    for (int i = 0; i < height; i++) {

        // espaços
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        // blocos 1ª piramide
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        // lacuna
        printf("  ");
        // blocos 2ª piramide
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    string flag;
    long creditCardNumber = get_long("Número: ");

    if (creditCardNumber < 1000000000000 || creditCardNumber > 9999999999999999) {
        printf("INVALID\n");
        return 0;
    }

    char numbers[16];
    sprintf(numbers, "%ld", creditCardNumber);

    if (((int)numbers[0] - 48) == 3 && (((int)numbers[1] - 48) == 4 || ((int)numbers[1] - 48) == 7) && strlen(numbers) == 15) {
        flag = "AMEX";
    } else if (((int)numbers[0] - 48) == 4 && (strlen(numbers) == 13 || strlen(numbers) == 16)) {
        flag = "VISA";
    } else if (((int)numbers[0] - 48) == 5 && ((int)numbers[1] - 48) >= 1 && ((int)numbers[1] - 48) <= 5 && strlen(numbers) == 16) {
        flag = "MASTERCARD";
    } else {
        printf("INVALID\n");
        return 0;
    }

    char invertedNumbers[16];
    for (int i = strlen(numbers) - 1; i >= 0; i--) {
        invertedNumbers[strlen(numbers) - 1 - i] = numbers[i];
    }

    int totalOfTheFirstSum = 0;
    for (int i = 1; i <= strlen(numbers) - 1; i += 2) {
        int total = ((int)invertedNumbers[i] - 48) * 2;
        if (total > 9) {
            char product[2];
            sprintf(product, "%d", total);
            total = ((int)product[0] - 48) + ((int)product[1] - 48);
        }
        totalOfTheFirstSum += total;
    }

    int totalOfTheSeccondSum = 0;
    for (int i = 0; i <= strlen(numbers) - 1; i += 2) {
        totalOfTheSeccondSum += ((int)invertedNumbers[i] - 48);
    }

    int total = totalOfTheFirstSum + totalOfTheSeccondSum;

    int referenceValue = (float)total / 10;
    if (total != (referenceValue * 10)) {
        printf("INVALID\n");
        return 0;
    }

    printf("%s\n", flag);
}

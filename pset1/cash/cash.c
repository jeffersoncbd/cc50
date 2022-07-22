#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getRemainder(void);
void getTheAmountOfCoinsThatPaysTheRest(
  float valueOfCoin,
  int* remainder,
  int* amountOfCoins
);

int main(void) {
  int remainder = getRemainder();
  int amountOfCoins = 0;

  getTheAmountOfCoinsThatPaysTheRest(0.25, &remainder, &amountOfCoins);
  getTheAmountOfCoinsThatPaysTheRest(0.10, &remainder, &amountOfCoins);
  getTheAmountOfCoinsThatPaysTheRest(0.05, &remainder, &amountOfCoins);
  getTheAmountOfCoinsThatPaysTheRest(0.01, &remainder, &amountOfCoins);

  printf("Total de moedas: %i\n", amountOfCoins);
}

int getRemainder(void) {
  float value = get_float("Troco devido: ");
  if (value < 0) {
    return getRemainder();
  }
  return round(value * 100);
}

void getTheAmountOfCoinsThatPaysTheRest(
  float valueOfCoin,
  int* remainder,
  int* amountOfCoins
) {
  int coin = round(valueOfCoin * 100);
  if (*remainder >= coin) {
    int amountOfCoinsPaid = (float)*remainder / (float)coin;
    int valuePaid = amountOfCoinsPaid * coin;
    *remainder -= valuePaid;
    printf("Moedas de %i: %i\n", coin, amountOfCoinsPaid);
    *amountOfCoins += amountOfCoinsPaid;
  }
}

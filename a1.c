#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>

int askInput (void);
void calculateCoins(int, int);

int main(void)
{
    
    int inputCoin = askInput();
    int orgInput = inputCoin;
    calculateCoins(inputCoin, orgInput);
    
    return(0);
}

void calculateCoins(int inputCoin, int orgInput) {
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;
    int tempTotal = 0;

    if (inputCoin != 0) {
        if (inputCoin / 25 != 0) {
            quarter = inputCoin / 25;
            inputCoin %= 25;
        }
        if (inputCoin / 10 != 0) {
            dime = inputCoin / 10;
            inputCoin %= 10;
        }
        if (inputCoin / 5 != 0) {
            nickel = inputCoin / 5;
            inputCoin %= 5;
        }
        penny = inputCoin;
    }
        printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", quarter, dime, nickel, penny);
    
    while (penny < orgInput) {
        while (nickel != 0) {
            penny += 5;
            nickel--;
            printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", quarter, dime, nickel, penny);
        }
        while (dime != 0) {
            if (dime == 1 && nickel == 0) {
                tempTotal = (dime * 10) + penny;
                nickel = tempTotal / 5;
                tempTotal -= nickel * 5;
                dime--;
                penny = tempTotal;
            } else {
                nickel += 2;
                dime--; 
            }

            printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", quarter, dime, nickel, penny);
            
            while (nickel != 0) {

                penny += 5;
                nickel--;
                printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", quarter, dime, nickel, penny);
            }
        }
        if (quarter != 0) {
            if (dime == 0 && nickel == 0) {
                tempTotal = 25 + penny;
                quarter--;

                dime = tempTotal / 10;
                tempTotal -= dime * 10;
                nickel = tempTotal / 5;
                tempTotal -= nickel * 5;
                penny = tempTotal;
            } else {
                dime += 2;
                nickel++;
                quarter --;
            }

            printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", quarter, dime, nickel, penny);
        }
    }
}

int askInput (void) {
    int input;

    scanf("%d", &input);

    return input;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "games.h"

int cash = 200;

int main() {
    int gameSelection;

    srand((unsigned int)time(NULL));

    while (1) {
        printf("--- Enter a game ---\n");
        printf("1) Slots\n2) Blackjack\n3) Roulette\n4) Horse Racing\n5) Show Balance\n6) Exit\n\n");
        printf("Make a selection: ");
        scanf_s("%d", &gameSelection);

        switch (gameSelection) {
        case 1:
            slots();
            break;
        case 2:
            blackjack();
            break;
        case 3:
            roulette();
            break;
        case 4:
            horseRacing();
            break;
        case 5:
            printf("\nYour balance is: %d\n\n", cash);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}
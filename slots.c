#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "games.h"

int slots() {
    int active = 1;
    int n;
    int r[10];
    char symbolArray[6] = { '!','@','#','$','%','?' };

    srand((unsigned int)time(NULL));;

    do {
        printf("How much would you like to bet? You have (%d): ", cash);
        scanf_s("%d", &n);

        if (n <= cash)
        {
            cash = cash - n;

            for (int spin = 0; spin < 20; spin++) {
                system("cls");

                for (int i = 1; i <= 9; i++) {
                    r[i] = rand() % 6;
                }

                printf("\n\n\t%c %c %c\n", symbolArray[r[1]], symbolArray[r[2]], symbolArray[r[3]]);
                printf("\t%c %c %c\n", symbolArray[r[4]], symbolArray[r[5]], symbolArray[r[6]]);
                printf("\t%c %c %c\n", symbolArray[r[7]], symbolArray[r[8]], symbolArray[r[9]]);

                Sleep(100);

            }
            system("cls");
            Sleep(100);

            printf("You rolled...");

            Sleep(750);

            printf("\n\n\t%c %c %c\n", symbolArray[r[1]], symbolArray[r[2]], symbolArray[r[3]]);
            Sleep(500);
            printf("\t%c %c %c\n", symbolArray[r[4]], symbolArray[r[5]], symbolArray[r[6]]);
            Sleep(500);
            printf("\t%c %c %c\n\n", symbolArray[r[7]], symbolArray[r[8]], symbolArray[r[9]]);

            if (r[7] == r[8] && r[8] == r[9] || r[1] == r[2] && r[2] == r[3] || r[4] == r[5] && r[5] == r[6] || r[8] == r[2] && r[8] == r[5] || r[7] == r[1] && r[7] == r[4] || r[9] == r[3] && r[9] == r[6] || r[1] == r[5] && r[1] == r[9] || r[7] == r[5] && r[5] == r[3])
            {
                printf("WINNER!\n");
                cash += n * 2;
                if (r[1] == r[5] && r[1] == r[9] && r[9] == r[3] && r[3] == r[7]) {
                    printf("DOUBLE WINNER\n");
                    cash += n * 5;
                    if (r[7] == r[8] && r[8] == r[9] && r[1] == r[2] && r[1] == r[3] && r[4] == r[5] && r[4] == r[6]) {
                        printf("JACKPOT!\n");
                        cash += n * 10;
                    }
                }
            }
            else {
                printf("You lose!\n");
            }
            printf("You have %d chips\n", cash);
            printf("Play Again? (1 or 0): ");
            scanf_s("%d", &active);
        }
        else
        {
            printf("Hey! You don't have that much money!\n");
        }

    } while (active == 1);

    printf("\nYou have %d chips\n\n", cash);
    return 0;
}
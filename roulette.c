#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "games.h"

int roulette() {
    srand(time(NULL));
    int numb, i, j, betlocation, betAmount, specificNumber = -1, active = 1;
    int win = 0, mult = 0, winnings;

    while (active == 1)
    {
        printf("How much would you like to bet? You have (%d): ", cash);
        scanf_s("%d", &betAmount);

        system("cls");

        printf("\nWhat are you putting it on?\n ");
        printf("1. Black\n ");
        printf("2. Red\n ");
        printf("3. Odds\n ");
        printf("4. Evens\n ");
        printf("5. 1st Dozen\n ");
        printf("6. 2nd Dozen\n ");
        printf("7. 3rd Dozen\n ");
        printf("8. 1st Column\n ");
        printf("9. 2nd Column\n ");
        printf("10. 3rd Column\n ");
        printf("11. 1st Half\n ");
        printf("12. 2nd Half\n ");
        printf("13. Specific Number\n ");
        printf("Select an option: ");
        scanf_s("%d", &betlocation);

        if (betlocation == 13) {
            printf("What number?: ");
            scanf_s("%d", &specificNumber);
        }

        system("cls");
        j = 200;

        numb = rand() % 37;


        for (i = 0; i < 40; i++)
        {
            numb = numb + 1;
            if (numb > 36)
            {
                numb = 0;
            }

            int left2 = numb - 1;
            int left = numb - 2;
            int right = numb + 2;
            int right2 = numb + 1;
            if (left < 0)
                left = 35;
            if (left2 < 0)
                left2 = 36;
            if (right > 36)
                right = 0;
            if (right2 > 36)
                right2 = 1;
            printf("\n\n             |");
            printf("\n   %d   %d   %d   %d   %d", left, left2, numb,
                right, right2);

            Sleep(j);
            system("cls");
            j = j + 5;
        }

        switch (betlocation)
        {
        case 1:
            if (numb < 11 && numb % 2 == 0) win = 1;
            if (numb > 18 && numb < 29 && numb % 2 == 0) win = 1;
            if (numb > 10 && numb < 19 && numb % 2 == 1) win = 1;
            if (numb > 28 && numb % 2 == 1) win = 1;
            mult = 2;
            break;

        case 2:
            if (numb < 11 && numb % 2 == 1) win = 1;
            if (numb > 18 && numb < 29 && numb % 2 == 1) win = 1;
            if (numb > 10 && numb < 19 && numb % 2 == 0) win = 1;
            if (numb > 28 && numb % 2 == 0) win = 1;
            mult = 2;
            break;

        case 3:
            if (numb % 2 == 1) win = 1;
            mult = 2;
            break;

        case 4:
            if (numb != 0 && numb % 2 == 0) win = 1;
            mult = 2;
            break;

        case 5:
            if (numb >= 1 && numb <= 12) win = 1;
            mult = 3;
            break;

        case 6:
            if (numb >= 13 && numb <= 24) win = 1;
            mult = 3;
            break;

        case 7:
            if (numb >= 25 && numb <= 36) win = 1;
            mult = 3;
            break;

        case 8:
            if (numb != 0 && numb % 3 == 1) win = 1;
            mult = 3;
            break;

        case 9:
            if (numb != 0 && numb % 3 == 2) win = 1;
            mult = 3;
            break;

        case 10:
            if (numb != 0 && numb % 3 == 0) win = 1;
            mult = 3;
            break;

        case 11:
            if (numb >= 1 && numb <= 18) win = 1;
            mult = 2;
            break;

        case 12:
            if (numb >= 19 && numb <= 36) win = 1;
            mult = 2;
            break;

        case 13:
            if (numb == specificNumber) win = 1;
            mult = 35;
            break;
        }

        if (win == 1)
        {
            winnings = betAmount * mult;
            cash = cash + winnings;
            printf("\nNumber: %d", numb);
            printf("\nYou won %d!!!!", winnings);
        }
        else
        {
            cash = cash - betAmount;
            printf("\nNumber: %d", numb);
            printf("\nYou lose!!!!");
        }

        printf("\nCash: %d\n", cash);
        printf("Would you like to play again? (1 or 0): ");
        scanf_s("%d", &active);
        system("cls");
    }
}
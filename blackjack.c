#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "games.h"

void blackjackShuffle(int array[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int c = rand() % (i + 1);
        int e = array[i];
        array[i] = array[c];
        array[c] = e;
    }
}

int blackjack() {
    srand((unsigned int)time(NULL));;

    int ace;
    int d = 52;
    int dhand = 0;
    int phand = 0;
    int hit = 0;
    int active = 1;
    int deck[52] =
    {
        1,2,3,4,5,6,7,8,9,10,10,10,10,
        1,2,3,4,5,6,7,8,9,10,10,10,10,
        1,2,3,4,5,6,7,8,9,10,10,10,10,
        1,2,3,4,5,6,7,8,9,10,10,10,10
    };

    while (active == 1)
    {
        int bet;
        system("cls");
        printf("How much would you like to bet? You have (%d): ", cash);
        scanf_s("%d", &bet);
        system("cls");

        blackjackShuffle(deck, 52);
        int f = 51;

        phand = 0;
        dhand = 0;

        // initial deal
        for (int i = 2; i > 0; i--)
        {
            if (deck[f] == 1)
            {
                if (phand < 10)
                    ace = 11;
                else
                    ace = 1;

                phand = phand + ace;
                printf("You draw a %d\n\n", ace);
                f--;
            }
            else {
                phand = phand + deck[f];
                printf("You draw a %d\n\n", deck[f]);
                f--;
                Sleep(700);
            }


            if (deck[f] == 1)
            {
                if (dhand < 10)
                    ace = 11;
                else
                    ace = 1;

                dhand = dhand + ace;
                printf("Dealer draws a %d\n\n", ace);
                f--;
            }
            else {
                dhand = dhand + deck[f];
                printf("Dealer draws a %d\n\n", deck[f]);
                f--;
                Sleep(700);
            }
        }
        printf("Player Total: %d\nDealer Total: %d\n\n", phand, dhand);
        // player turn
        int pturn = 0;
        while (pturn == 0 && phand < 21)
        {
            printf("Would you like to hit or stand? (1 or 0): ");
            scanf_s("%d", &hit);
            if (hit == 1 && phand < 21)
            {
                if (deck[f] == 1)
                {
                    if (phand < 10)
                        ace = 11;
                    else
                        ace = 1;

                    phand = phand + ace;
                    printf("\nYou draw a %d\n", ace);
                    printf("Total: %d\n\n", phand);
                    f--;
                }
                else {
                    phand = phand + deck[f];
                    printf("\nYou draw a %d\n\n", deck[f]);
                    f--;
                }
            }
            else
            {
                pturn = 1;
            }
        }
        // dealer turn
        while (dhand < 17) {
            dhand = dhand + deck[f];
            printf("\nDealer draws a %d (Total: %d)\n\n", deck[f], dhand);
            f--;
            Sleep(300);
        }

        // end conditions
        if (dhand > phand && dhand <= 21 || phand > 21)
        {
            printf("You Lose!\n\n");
            cash = cash - bet;
        }
        else if (phand <= 21 && phand > dhand || dhand > 21)
        {
            printf("You Win!\n\n");
            cash = cash + bet;
        }
        else
        {
            printf("Its a wash!\n\n");
        }
        printf("You have %d chips\n\n", cash);
        printf("Would you like to play again? (1 or 0) : ");
        scanf_s("%d", &active);
    }
    return 0;
}
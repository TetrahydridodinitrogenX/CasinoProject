#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "games.h"

struct horse {
    char name[50];
    int speed;
    int stamina;
    int winPercentage;
    int HUNGRY;
    int injuryRisk;
};

struct horse horses[6] = {
    {"Renegade", 9, 3, 60, 0, 23},
    {"Chief", 3, 10, 45, 0, 5},
    {"Lucky", 5, 5, 90, 0, 10},
    {"Pablo", 6, 6, 50, 0, 7},
    {"Epona", 7, 7, 42, 0, 7},
    {"?????", 0, 0, 0, 0, 0},
};

void generateRandomName(char* name, int length) {
    name[0] = 'A' + rand() % 26;
    for (int i = 1; i < length; i++) {
        name[i] = 'a' + rand() % 26;
    }
    name[length] = '\0';
}

int randomizeHorse() {
    // random horse :)
    generateRandomName(horses[5].name, 8);
    horses[5].speed = rand() % 11;
    horses[5].stamina = rand() % 11;
    horses[5].winPercentage = rand() % 101;
    horses[5].injuryRisk = rand() % 51;
    return 0;
}

int horseRacing() {
    int userInput, listReturn, betAmount, horseChoice;
    int active = 1;

    while (active == 1) {
        system("cls");
        printf("1) Place Bets & Race\n2) List Horses\n3) Randomize Final Horse\n4) Exit Horse Racing\nMake a selection: ");
        scanf_s("%d", &userInput);

        switch (userInput) {
        case 1:
            randomizeHorse();

            printf("You have $%d\n", cash);
            printf("Choose a horse to bet on 1-6: ");
            scanf_s("%d", &horseChoice);

            if (horseChoice < 1 || horseChoice > 6) {
                printf("Invalid horse choice.\n");
                system("pause");
                break;
            }

            printf("Enter bet amount: ");
            scanf_s("%d", &betAmount);

            if (betAmount <= 0 || betAmount > cash) {
                printf("Invalid bet amount.\n");
                system("pause");
                break;
            }

            int positions[6] = { 0 };
            int stillRacing[6] = { 1, 1, 1, 1, 1, 1 };
            int finishLine = 50;
            int winner = -1;

            for (int i = 0; i < 6; i++) {
                horses[i].HUNGRY = rand() % 40;
            }

            while (winner == -1) {
                system("cls");

                for (int i = 0; i < 6; i++) {
                    if (stillRacing[i] == 0) {
                        printf("%-10s | TOO HUNGRY / STOPPED\n", horses[i].name);
                        continue;
                    }

                    int move = rand() % 3;
                    move += horses[i].speed / 3;
                    move += horses[i].stamina / 5;

                    horses[i].HUNGRY += move + 1; // hungy when mov

                    if (horses[i].HUNGRY >= 100) {
                        horses[i].HUNGRY = 100;
                        stillRacing[i] = 0;

                        printf("%-10s | TOO HUNGRY / STOPPED\n", horses[i].name);

                        if (i == horseChoice - 1) {
                            winner = -2;
                            break;
                        }

                        continue;
                    }

                    positions[i] += move;

                    if (positions[i] >= finishLine) {
                        winner = i;
                        break;
                    }

                    printf("%-10s |", horses[i].name);

                    for (int j = 0; j < finishLine; j++) {
                        if (j == positions[i]) printf("H");
                        else printf("-");
                    }

                    printf("| Hunger: %d/100\n", horses[i].HUNGRY);
                }

                Sleep(200);
            }

            if (winner == -2) {
                cash -= betAmount;
                printf("\nYour horse starved and stopped racing!\n");
                printf("You lost $%d.\n", betAmount);
            }
            else {
                printf("\nWinner: %s!\n", horses[winner].name);

                if (winner == horseChoice - 1) {
                    cash += betAmount;
                    printf("You won $%d!\n", betAmount);
                }
                else {
                    cash -= betAmount;
                    printf("You lost $%d.\n", betAmount);
                }
            }

            system("pause");
            break;

        case 2:
            for (int i = 0; i < 6; i++) {
                printf("Horse %d\n", i + 1);
                printf("Name: %s\n", horses[i].name);
                printf("Speed: %d/10\n", horses[i].speed);
                printf("Stamina: %d/10\n", horses[i].stamina);
                printf("Win %%: %d/100\n", horses[i].winPercentage);
                printf("Hungry: %d/100\n", horses[i].HUNGRY);
                printf("Injury Risk: %d/50\n", horses[i].injuryRisk);
                printf("------------------------\n");
            }

            printf("\nPress 1 to Return: ");
            scanf_s("%d", &listReturn);
            break;

        case 3:
            randomizeHorse();
            printf("Final horse randomized!\n");
            system("pause");
            break;

        case 4:
            system("cls");
            active = 0;
            break;

        default:
            printf("Invalid choice.\n");
            system("pause");
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int wins = 0;
int losses = 0;
int ties = 0;

void end();

int main() {
    srand((unsigned int) time(NULL) ^ (unsigned int) clock());

    Card* deck = newDeck();
    int deckSize = 52;

    Card playerHand[10];
    Card dealerHand[10];
    int playerCards = 0;
    int dealerCards = 0;

    playerHand[playerCards++] = draw(deck, &deckSize);
    dealerHand[dealerCards++] = draw(deck, &deckSize);
    playerHand[playerCards++] = draw(deck, &deckSize);
    dealerHand[dealerCards++] = draw(deck, &deckSize);

    displayHand(playerHand, playerCards, "Player");
    displayCard(dealerHand[0]);
    printf("Hidden card\n");
    printf("Total: %d\n\n", calculateScore(&dealerHand[0], 1));

    char choice;
    while (calculateScore(playerHand, playerCards) < 21) {
        printf("Hit or Stand? (h/s): ");
        scanf(" %c", &choice);
        if (choice == 'h') {
            playerHand[playerCards++] = draw(deck, &deckSize);
            clear();
            displayHand(playerHand, playerCards, "Player");
            displayCard(dealerHand[0]);
            printf("Hidden card\n");
            printf("Total: %d\n\n", calculateScore(&dealerHand[0], 1));
        } else {
            break;
        }
    }

    int playerScore = calculateScore(playerHand, playerCards);
    if (playerScore > 21) {
        printf("%s%sPlayer busts. Dealer wins.%s\n\n", BOLD, RED, RESET);
        losses++;
        end();
    }

    for (int i = 0; i < 2; i++) {
        clear();
        printf("Dealer drawing");
        pause(1);
        clear();
        printf("Dealer drawing.");
        pause(1);
        clear();
        printf("Dealer drawing..");
        pause(1);
        clear();
        printf("Dealer drawing...");
        pause(1);
        clear();
    }

    while (calculateScore(dealerHand, dealerCards) < 17) {
        dealerHand[dealerCards++] = draw(deck, &deckSize);
    }

    displayHand(playerHand, playerCards, "Player");
    printf("\n");
    displayHand(dealerHand, dealerCards, "Dealer");

    int dealerScore = calculateScore(dealerHand, dealerCards);
    if (dealerScore > 21 || playerScore > dealerScore) {
        printf("%s%sPlayer wins!%s\n\n", BOLD, GREEN, RESET);
        wins++;
    } else if (dealerScore > playerScore) {
        printf("%s%sDealer wins!\n\n%s", BOLD, RED, RESET);
        losses++;
    } else {
        printf("%s%sIt's a draw!%s\n\n", BOLD, YELLOW, RESET);
        ties++;
    }

    free(deck);

    end();

    return 0;
}

void end() {
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Ties: %d\n\n", ties);

    char choice;
    printf("Play again (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'n') {
        exit(0);
    }

    clear();
    main();
}

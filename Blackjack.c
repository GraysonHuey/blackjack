#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int calculateScore(Card* hand, int handSize) {
    int score = 0;
    int aceCount = 0;

    for (int i = 0; i < handSize; i++) {
        int value = hand[i].rank;
        if (value > 10) value = 10;
        if (value == Ace) aceCount++;
        score += value;
    }

    while (score <= 11 && aceCount > 0) {
        score += 10;
        aceCount--;
    }

    return score;
}

void displayHand(Card* hand, int size, const char* owner) {
    printf("%s's hand:\n", owner);
    for (int i = 0; i < size; i++) {
        displayCard(hand[i]);
    }
    printf("Total: %d\n\n", calculateScore(hand, size));
}

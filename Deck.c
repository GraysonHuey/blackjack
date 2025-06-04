#include <stdlib.h>

#include "utils.h"

Card* newDeck() {
    Card* deck = malloc(sizeof(Card) * 52);
    if (!deck) { return nullptr; }

    int currentCard = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[currentCard++] = newCard((Suit) i, (Rank) j);
        }
    }

    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    return deck;
}

Card draw(Card* deck, int* currentSize) {
    if (*currentSize == 0) {
        exit(1);
    }

    (*currentSize)--;
    return deck[*currentSize];
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

Card newCard(Suit suit, Rank rank) {
    Card card;
    card.suit = suit;
    card.rank = rank;
    return card;
}

void displayCard(Card card) {
    char* result = malloc(100 * sizeof(char));
    switch (card.rank) {
        case Ace:
            sprintf(result, "Ace of ");
            break;
        case Two:
            sprintf(result, "Two of ");
            break;
        case Three:
            sprintf(result, "Three of ");
            break;
        case Four:
            sprintf(result, "Four of ");
            break;
        case Five:
            sprintf(result, "Five of ");
            break;
        case Six:
            sprintf(result, "Six of ");
            break;
        case Seven:
            sprintf(result, "Seven of ");
            break;
        case Eight:
            sprintf(result, "Eight of ");
            break;
        case Nine:
            sprintf(result, "Nine of ");
            break;
        case Ten:
            sprintf(result, "Ten of ");
            break;
        case Jack:
            sprintf(result, "Jack of ");
            break;
        case Queen:
            sprintf(result, "Queen of ");
            break;
        case King:
            sprintf(result, "King of ");
            break;
    }

    switch (card.suit) {
        case Diamonds:
            sprintf(result + strlen(result), "Diamonds");
            break;
        case Hearts:
            sprintf(result + strlen(result), "Hearts");
            break;
        case Spades:
            sprintf(result + strlen(result), "Spades");
            break;
        case Clubs:
            sprintf(result + strlen(result), "Clubs");
            break;
    }
    printf("%s\n", result);
    free(result);
}


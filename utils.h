#ifndef UTILS_H
#define UTILS_H

typedef enum Suit {
    Spades,
    Diamonds,
    Clubs,
    Hearts,
} Suit;

typedef enum Rank {
    Ace = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
} Rank;

typedef struct Card {
    Suit suit;
    Rank rank;
} Card;

Card* newDeck();
Card draw(Card* deck, int* currentSize);
Card newCard(Suit suit, Rank rank);
void displayCard(Card card);

#endif //UTILS_H

#ifndef UTILS_H
#define UTILS_H

#ifdef __WIN32__
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define BOLD   "\x1b[1m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

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
int calculateScore(Card* hand, int handSize);
void displayHand(Card* hand, int size, const char* owner);

static void pause(int sec) {
#ifdef __WIN32__
    Sleep(sec*1000);
#else
    sleep(sec);
#endif
}

static void clear() {
#ifdef __WIN32__
    system("cls");
#else
    system("clear");
#endif
}

#endif //UTILS_H

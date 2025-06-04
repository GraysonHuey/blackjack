#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    Card* deck = newDeck();
    int currentSize = 52;

    for (int i = 0; i < 10; i++) {
        printf("Current size: %d\n", currentSize);
        displayCard(draw(deck, &currentSize));
    }
}
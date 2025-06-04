cmake_minimum_required(VERSION 3.31)
project(Blackjack C)

set(CMAKE_C_STANDARD 23)

add_executable(Blackjack main.c
        Card.c
        utils.h
        Deck.c)

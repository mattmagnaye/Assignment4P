/*
* Program: Poker (sort of) - Project 13.1 (Assignment 4P: Arrays)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Class: CIS 278
* Date: 06/27/2023
* FIle: main.cpp
* Description: It is a program that reads HAND_SIZE cards from the user, 
*              then analyzes the cards and prints out the type of poker 
*              hand that they represent.
*
*/
#include <iostream>
using namespace std;

// Declaring necessary constants and values per as instruction
const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;


int main() {

    int hand[HAND_SIZE];
    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use " << LOWEST_NUM << " - " << HIGHEST_NUM << ".\n";

    for (int i = 0; i < HAND_SIZE; ++i) {
        cout << "Card " << (i+1) << ": ";
        cin >> hand[i];
    }

    if (containsThreeOfaKind(hand)) {
        cout << "Three of a Kind!";
    }
    else if (containsTwoPair(hand)) {
        cout << "Two Pair!";
    }
    else if (containsPair(hand)) {
        cout << "Pair!";
    } else {
        cout << "High Card!";
    }

    return 0
}

/* 
* Function: containsPair
* This function checks if the poker hand contains a pair.
*/
bool containsPair(const int hand[]) {
    map<int, int> cardCount;
    for(int i = 0; i < HAND_SIZE; i++) {
        cardCount[hand[i]]++;
    }

    for(auto it : cardCount)  {
        if(it.second == 2) {
            return true;
        }
    }
    return false;

}

/*
* Function: containsTwoPair
* This function checks if the poker hand contains two pairs.
*/
bool containsTwoPair(const int hand[]) {
    map<int, int> cardCount;
    for(int i = 0; i++) {
        cardCount[hand[i]]++;
    }

    int pairCount = 0;
    for(auto it : cardCount) {
        if(it.second == 2) {
            pairCount++;
        }
    }
    return pairCount == 2;
}


/*
* Function: containsThreeOfaKind
* This function checks if the poker hand contains three of a kind.
*/
bool containsThreeOfaKind(const int hand[]) {
    map<int, int> cardCount;
    for(int i = 0; i < HAND_SIZE; i++) {
        cardCount[hand[i]]++;
    }

    for(auto it : cardCount) {
        if(it.second == 3) {
            return true;
        }
    }
    return false;
}

bool 
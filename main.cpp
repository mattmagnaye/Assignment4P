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
*              Program was made without trying the extra credit requirement.
*              But changed a couple of lines of code to ensure no nested loops. 
*
*/
#include <iostream>
#include <map>
using namespace std;

// Declaring necessary constants and values per as instruction
const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;

void populateCardCountMap(const int hand[], map<int, int>& cardCount);
int countOccurrences(const map<int, int>& cardCount, int count);

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

int main() {
    int hand[HAND_SIZE];
    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use " << LOWEST_NUM << " - " << HIGHEST_NUM << ".\n";

    for (int i = 0; i < HAND_SIZE; ++i) {
        cout << "Card " << (i+1) << ": ";
        cin >> hand[i];
    }

    if (containsFourOfaKind(hand)) {
        cout << "Four of a kind!";
    } else if (containsFullHouse(hand)) {
        cout << "Full House!";
    } else if (containsStraight(hand)) {
        cout << "Straight!";
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a Kind!";
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair!";
    } else if (containsPair(hand)) {
        cout << "Pair!";
    } else {
        cout << "High Card!";
    }

    return 0;
}

/*
* Function: populateCardCountMap
* This function takes a poker hand and a referance to a map.
* In requirement for extra credit.
*/
void populateCardCountMap(const int hand[], map<int, int>& cardCount) {
    for(int i = 0; i < HAND_SIZE; i++) {
        cardCount[hand[i]]++;
    }
}

/*
* Function: countOccurrences
* This function takes a map with card counts and an integer representing a count.
* In requirement for extra credit.
*/
int countOccurrences(const map<int, int>& cardCount, int count) {
    int occurrences = 0;
    for(auto it : cardCount) {
        if(it.second == count) {
            occurrences++;
        }
    }
    return occurrences;
}

/* 
* Function: containsPair
* This function checks if the poker hand contains a pair.
*/
bool containsPair(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 2) == 1;
}

/*
* Function: containsTwoPair
* This function checks if the poker hand contains two pairs.
*/
bool containsTwoPair(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 2) == 2;
}

/*
* Function: containsThreeOfaKind
* This function checks if the poker hand contains three of a kind.
*/
bool containsThreeOfaKind(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 3) >= 1;
}

/*
* Function: containsFourOfaKind
* This function checks if the poker hand contains four of a kind.
*/  
bool containsFourOfaKind(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 4) == 1;
}

/*
* Function: containsFullHouse
* This function checks if the poker hand contains a full house.
*/   
bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}

/*
* Function: containsStraight
* This function checks if the poker hand contains a straight.
*/
bool containsStraight(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);

    auto it = cardCount.begin();
    int prev = it->first;
    ++it;
    int count = 1;
    while(it != cardCount.end()) {
        if(it->first == prev+1) {
            count++;
        } else {
            count = 1;
        }
        if(count == 5) {
            return true;
        }
        prev = it->first;
        ++it;
    }
    return false;
}

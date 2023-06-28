#include <iostream>
#include <map>
using namespace std;

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

void populateCardCountMap(const int hand[], map<int, int>& cardCount) {
    for(int i = 0; i < HAND_SIZE; i++) {
        cardCount[hand[i]]++;
    }
}

int countOccurrences(const map<int, int>& cardCount, int count) {
    int occurrences = 0;
    for(auto it : cardCount) {
        if(it.second == count) {
            occurrences++;
        }
    }
    return occurrences;
}

bool containsPair(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 2) == 1;
}

bool containsTwoPair(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 2) == 2;
}

bool containsThreeOfaKind(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 3) >= 1;
}

bool containsFourOfaKind(const int hand[]) {
    map<int, int> cardCount;
    populateCardCountMap(hand, cardCount);
    return countOccurrences(cardCount, 4) == 1;
}

bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}

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

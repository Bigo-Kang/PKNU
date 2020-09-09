#include <stdio.h>
#define NUM_RANKS 14
#define NUM_SUITS 4
#define NUM_CARDS 5
int numInRank[NUM_RANKS];
int numInSuit[NUM_SUITS];
int input[NUM_CARDS][2];
void readCards(void);
void analyzeHand();
bool againGame();
int checkInput(int input[][2], char r, char s, int);
int checkFlush();
int checkStraight();
int checkFourCards();
int checkThreeCards();
int countPairs();
void analyzeHand();
int main()
{
    while (1) {
        readCards();
        analyzeHand();
        if (!againGame()) break;
    }
    return 0;
}
void initData() {
    int rank, suit;
    for (rank = 0; rank < NUM_RANKS; rank++)
        numInRank[rank] = 0;
    for (suit = 0; suit < NUM_SUITS; suit++)
        numInSuit[suit] = 0;
}
void readCards() {
    char rankCh, suitCh;
    int rank, suit;
    initData();
    int cardsRead = 0;
    while (cardsRead < NUM_CARDS) {
        printf("Enter a card : ");
        scanf(" %c", &rankCh);
        switch (rankCh) {
            case 'a': rank = 1; break;
            case '2': rank = 2; break;
            case '3': rank = 3; break;
            case '4': rank = 4; break;
            case '5': rank = 5; break;
            case '6': rank = 6; break;
            case '7': rank = 7; break;
            case '8': rank = 8; break;
            case '9': rank = 9; break;
            case 't': rank = 10; break;
            case 'j': rank = 11; break;
            case 'q': rank = 12; break;
            case 'k': rank = 13; break;
            default: printf("Input again\n"); continue;
        }
        scanf(" %c", &suitCh);
        switch (suitCh) {
            case 'c': suit = 0; break;
            case 'd': suit = 1; break;
            case 'h': suit = 2; break;
            case 's': suit = 3; break;
            default: printf("Input again\n"); continue;
        }
        if (checkInput(input, rankCh, suitCh, cardsRead) == 1) continue;
        input[cardsRead][0] = rankCh;
        input[cardsRead][1] = suitCh;
        numInRank[rank]++;
        numInSuit[suit]++;
        cardsRead++;
    }
}
int checkInput(int input[][2], char r, char s, int count) {
    for (int i = 0; i < count; i++) {
        if (input[i][0] == r && input[i][1] == s) {
            printf("Input again\n"); return 1;
        }
    }
    return 0;
}
int checkFlush() {
    for (int i = 0; i < NUM_SUITS; i++) {
        if (numInSuit[i] == 5) return 1;
    }
    return 0;
}
int checkStraight() {
    int count = 0;
    for (int i = 1; i < NUM_RANKS; i++) {
        if (numInRank[i] == 0) count = 0;
        else count++;
        if (count == 5) return 1;
        if (i == 13 && count == 4 && numInRank[1] == 1) return 1;
    }
    return 0;
}
int checkFourCards() {
    for (int i = 1; i < NUM_RANKS; i++) {
        if (numInRank[i] == 4) return 1;
    }
    return 0;
}
int checkThreeCards() {
    for (int i = 1; i < NUM_RANKS; i++) {
        if (numInRank[i] == 3) return 1;
    }
    return 0;
}
int countPairs() {
    int count = 0;
    for (int i = 1; i < NUM_RANKS; i++) {
        if (numInRank[i] == 2) count++;
    }
    return count;
}
void analyzeHand() {
    int count = countPairs();
    if (checkFlush() == 1 && checkStraight() == 1) {
        printf("Straight Flush\n"); return;
    }
    if (checkFourCards() == 1) {
        printf("Four Card\n"); return;
    }
    if (checkThreeCards() == 1 && count == 2) {
        printf("Full House\n"); return;
    }
    if (checkFlush() == 1) {
        printf("Flush\n"); return;
    }
    if (checkStraight() == 1) {
        printf("Straight\n"); return;
    }
    if (checkThreeCards() == 1) {
        printf("Triple\n"); return;
    }
    if (count == 2) {
        printf("Two Pair\n"); return;
    }
    if (count == 1) {
        printf("One Pair\n"); return;
    }
    else {
        int maxCard = 2;
        for (int i = 0; i < NUM_CARDS; i++) {
            if (input[i][0] > maxCard || input[i][0] == 'a')
                maxCard = input[i][0];
        }
        printf("%c Top Card\n", maxCard);
    }
}
bool againGame() {
    char command;
    printf("Play again?(Y/N) ");
    scanf(" %c", &command);
    return (command == 'Y' || command == 'y');
}
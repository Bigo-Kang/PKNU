#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void initializeNumberGenerator();
int chooseSecretNumber();
int play(int);

int main()
{
    char command;
    int secretNumber;
    int maxGuess, guess, num=0;
    initializeNumberGenerator();
    printf("Guess the secret number between 1 and %d\n", MAX);

    while(1){
        secretNumber = chooseSecretNumber();
        guess = play(secretNumber);
        if(num == 0) maxGuess = guess;
        if(guess < maxGuess){
            maxGuess = guess;
            printf("Congratulation!\n");
        }
        printf("Play again?(Y/N)");
        scanf(" %c", &command);
        if(command != 'y' && command != 'Y') break;
        printf("\n");
        num++;
    }
    return 0;
}
void initializeNumberGenerator(){
    srand((unsigned int)time(NULL));
}
int chooseSecretNumber(){
    int secretNumber = rand()%MAX+1;
    return secretNumber;
}
int play(int secretNumber){
    int guess,numGuesses=0;
    while(1){
        printf("Enter guess : ");
        scanf("%d",&guess);
        numGuesses++;
        if(guess == secretNumber){
            printf("You won in %d guesses!\n",numGuesses);
            return numGuesses;
        }
        else if(guess<secretNumber)
            printf("Too Low; Try again.\n");
        else
            printf("Too High; Try again.\n");
    }
}
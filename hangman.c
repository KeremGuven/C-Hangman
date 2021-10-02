// importing the libraries
#include <stdio.h> // main library
#include <stdlib.h> // for exiting the program and clearing console
#include <string.h> // for strlen and strchr

// variables
int WRONG_CHOICES = 0;
int TRUE_CHOICES = 0;
int healts_remain = 6;
int u = 0;

char word[10];
int arr[10];
char used[10];
char choice;

// macros
#define GAME_OVER 0
#define CHAR "_ "
#define RESET printf("\033[0m");
#define GREEN printf("\033[0;32m");
#define RED printf("\033[0;31m");

// drawing the board
void DRAW_BOARD() {
    RESET
    printf("\nHealts remain : %d\n\nWrong Choices : %d\n\nTrue Choices : %d\n\nUsed : %s\n\n", healts_remain, WRONG_CHOICES, TRUE_CHOICES, used);
    for(int i = 0; i < strlen(word); i++) {
        if(arr[i] == "_") {
            RESET
            printf(CHAR);
        }
        else {
            GREEN
            printf("%c‎‎", arr[i]);
            printf(" ");
        }
        if(i == strlen(word) - 1) {
            RESET
            printf("\n");
        }
    }
}

// getting the choice
void CHOICE() {
    RESET
    printf("\nYour Choice? ");
    scanf(" %c", &choice);
    if(TRUE_CHOICES == strlen(word) - 1) {
        system("clear");
        GREEN
        FILE *file = fopen("word.txt", "r");
        fscanf(file, " %s", &word);
        printf("\nYou Won! The word was %s\n", word);
        exit(1);
    }
    if(strchr(word, choice) != NULL) {
        
        for(int i = 0; i < strlen(word); i++) {
            if(choice == word[i]) {
                arr[i] = choice;
                word[i] = "_";
                TRUE_CHOICES += 1;
            }
        }
    }
    else {
        if(healts_remain == 1) {
            system("clear");
            RED
            printf("\nYou Lost!\n");
            exit(1);
        }
        WRONG_CHOICES += 1;
        healts_remain -= 1;
    }
    choice = choice;
    used[u] = choice;
    u += 1;
}

// main function
int main(void) {
    FILE *file = fopen("word.txt", "r");
    if(!file) {
        RESET
        printf("file dosent exsist\n");
        exit(1);
    }
    fscanf(file, " %s", &word);
    for(int i = 0; i < strlen(word); i++) {
        arr[i] = "_";
    }
    int len = strlen(word);
    if(len < 4 || len > 10) {
        RESET
        printf((len > 10) ? "the word is too long\n" : "the word is too short\n");
        exit(1);
    }
    while(!GAME_OVER) {
        system("clear");
        DRAW_BOARD();
        CHOICE();
    }
    return  0;
}
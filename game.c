// INCLUDED STANDARD LIBRARIES
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <err.h>
#include <string.h>

// NON STANDARD LIBRARIES
#include "colours.h"
#include "dict.h"
#include "list.h"
#include "game.h"

// GLOBAL DEFINITIONS
#define MAX_LIM 6


static void lowerWord(char *s1) {
  for (int i = 0; i < strlen(s1); i++) {
    s1[i] = tolower(s1[i]);
  }
}


// REMOVE NEWLINE 
static void remove_newline(char *input) {

    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    // Note: will have no effect if already at null terminator
    input[index] = '\0';
}

// CLEAR BUFFER 
static void clearBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// GET WORD IF A NULL CHARACTER IS INPUTTED
static void reinitaliseWord(char *input) {
  srand(time(NULL));
  FILE *list = fopen("valid-wordle-words.txt", "r");
  if (list == NULL) {
    fprintf(stderr, BOLDRED"ERR: FILE NOT FOUND"RESET);
    exit(EXIT_FAILURE);
  } 
  // Get a random number from 1-12972
  int random = rand() % 12972;
  int count = 0;
  char temp[6];
  while (fgets(temp, 6, list) != NULL) {
    if (count == random) {
      remove_newline(temp);
      strcpy(input, temp);
    }
    count++;
  }
  if (input[0] == '\0') {
    fclose(list);
    reinitaliseWord(input);
  }
  else {
    fclose(list);
    return;
  }
}

static bool isInWord(char *word, char input) {
  for (int i = 0; i < strlen(word); i++) {
    if (input == word[i]) {
      return true;
    }
  }
  return false; 
}

static int getIndex(char *word, char input) {
  int count = -1;
  for (int i = 0; i < strlen(word); i++) {
    if (word[i] == input) {
      return i;
    }
  }
  return count;
}


static bool isCorrectIndex(char *word, char input, int inputIndex) {
  // Find the index of character for chosen word 
  int count = getIndex(word, input);
  if (inputIndex == count) {
    return true; 
  }

  if (count == -1) {
    return false; 
  }
  return false; 
}

// MAIN FUNCTIONS

// Make an new instance of the game to be used

Game newInstance() {
  Game new = malloc(sizeof(*new));
  new->input = malloc(6 * sizeof(char));
  new->inputInfo = calloc(6, sizeof(int));
  new->recordedInputs = ListNew();
  return new;
}

Trie loadWords(char *random) {

  // Generate random number
  srand(time(NULL));
  // Given that wordle list is 12972 long,
  int pick_word = rand() % 12972;
  int counter = 0;
  // Construct Trie
  Trie new = newNode();
  // open "array --> File pointer to all words"
  FILE *words = fopen("valid-wordle-words.txt", "r");
  if (words == NULL) {
    printf(BOLDRED"ERR: FILE NOT FOUND" RESET);
    exit(EXIT_FAILURE);
  }
  // Read these words in line by line and insert them into the trie
  char temp[6];
  while (fgets(temp, 6, words)) {
    remove_newline(temp);
    TrieInsert(new, temp);
    if (counter == pick_word) {
      strcpy(random, temp);
      if (random[0] == '\0') {
        reinitaliseWord(random);
      }
    }
    counter++;

  }
  printf(BOLDGREEN"Worlde words loaded!\n"RESET);
  fclose(words);
  return new;
}


// POSSIBLE FUNCTOIN --> COMPARE INPUT (PUT IN WORDLE_FUNCTIONS.c)
// Will compare the input of characters in string with given word
// If in correct place --> print in green
// If present in word but wrong place --> print in yellow
// Else --> no colour or GREY-D OUT     



void FreeGame(Game g) {
  free(g->input);
  free(g->inputInfo);
  ListFree(g->recordedInputs);
  free(g);
}

// Function that transports game data into list ADT to hold
void gameHandoff(Game g) {
  // Game structure will only hold last inputs, port these into the recorded
  // inputs part of the list 
  g->recordedInputs = ListInsert(g->recordedInputs, g->input, g->inputInfo);
  
}


// Function (Prototype test)
// Checks if the inputted word is valid or not
// Input: 5 Letter word
// Output: True or false statement

void request_input(Trie s, char *chosenWord, Game g) {
  printf(GREEN"Enter word: "RESET);
  if (fgets(g->input, 6, stdin) != NULL) {
    if (g->input[0] == '\n') {
      clearBuffer();
    }
    remove_newline(g->input);
    lowerWord(g->input);
    if (TrieSearch(s, g->input)) {

      if (strcmp(g->input, chosenWord) == 0) {
        // PLACEHOLDER --> REMOVE IN LATER VARIATIONS
        ListShow(g->recordedInputs);
        printf(BOLDGREEN"Guessed the word!\n"RESET);
        FreeGame(g);
        TrieFree(s);
        exit(EXIT_SUCCESS);
      }
      else {
      // Check word --> Search every character and check if it is in word
        for (int i = 0; i < strlen(chosenWord); i++) {
          if (isInWord(chosenWord, g->input[i])) {
            if (isCorrectIndex(chosenWord, g->input[i], i)) {
              g->inputInfo[i] = 1;
              //printf(BOLDGREEN"RIGHT POSITION\n"RESET);
            }
            else {
              g->inputInfo[i] = 2;
              //printf(BOLDYELLOW"WRONG POSITION\n"RESET);
            }
          }
          else {
            g->inputInfo[i] = -1;
            //printf(BOLDRED"NOT IN WORD\n"RESET);
          }
        }
      }
      gameHandoff(g);
    }
    else {
      printf(BOLDRED"INVALID WORD\n"RESET);
      request_input(s, chosenWord, g);
    }
    clearBuffer();
  } 
  else {
    FreeGame(g);
    TrieFree(s);
    exit(0);
  }
}





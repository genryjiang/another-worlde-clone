// INCLUDED STANDARD LIBRARIES
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <err.h>
#include <string.h>
#include <assert.h>

// NON STANDARD LIBRARIES
#include "colours.h"
#include "dict.h"


// GLOBAL DEFINITIONS

#define MAX_LIM 6

// STATIC HELPER FUNCTIONS 

// REMOVE NEWLINE IMPLEMENTATION FUNCTION
void remove_newline(char *input) {

    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    // Note: will have no effect if already at null terminator
    input[index] = '\0';
}

// CLEAR BUFFER IMPLEMENTATION FILE 

void clearBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// MAIN FUNCTIONS

Trie loadWords() {
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
  }
  printf(BOLDGREEN"Worlde words loaded!\n"RESET);
  //char curr[6];
  //printf(BOLDWHITE"ALL TRIE WORDS: \n"RESET);
  //TrieShow(new, curr, 0);

  return new;
}

// POSSIBLE FUNCTION --> SETUP THE GAME 
// As wordle game is not a loop (LOOP FUNCTIONALITY LATER)
// DRAW RANDOM WORD FROM GIVEN WORD LIST
// RETURN IT TO MAIN


// POSSIBLE FUNCTOIN --> COMPARE INPUT (PUT IN WORDLE_FUNCTIONS.c)
// Will compare the input of characters in string with given word
// If in correct place --> print in green
// If present in word but wrong place --> print in yellow
// Else --> no colour or GREY-D OUT     

// Function (Prototype test)
// Checks if the inputted word is valid or not
// Input: 5 Letter word
// Output: True or false statement


void request_input(Trie s) {
  char input[6];
  printf(GREEN"Enter word: "RESET);
  // Stop gap measure to stop multiple inputs --> Fix later
  fflush(stdin);
  //clearBuffer();
  while (fgets(input, 6, stdin) != NULL) {
    remove_newline(input);

    if (TrieSearch(s, input)) {
      printf(BOLDGREEN"VALID WORD\n"RESET);
    }
    else {
      printf(BOLDRED"INVALID WORD\n"RESET);
      request_input(s);
    }
    clearBuffer();
  }
}

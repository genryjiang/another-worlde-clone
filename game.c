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
#include "game.h"


// GLOBAL DEFINITIONS

#define MAX_LIM 6

// GLOBAL MACROS FOR COLOURS IN STDOUT
#define RESET   "\033[0m"
#define BLACK   "\033[30 m"                 /* Black */
#define RED     "\033[31m"                 /* Red */
#define GREEN   "\033[32m"                 /* Green */
#define YELLOW  "\033[33m"                 /* Yellow */
#define BLUE    "\033[34m"                 /* Blue */
#define MAGENTA "\033[35m"                 /* Magenta */
#define CYAN    "\033[36m"                 /* Cyan */
#define WHITE   "\033[37m"                 /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


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
  char temp[69420];
  while (fgets(temp, 69420, words)) {
    remove_newline(temp);
    TrieInsert(new, temp);
  }
  printf(BOLDGREEN"Worlde words loaded!\n"RESET);
  //SetShow(new);
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

// Function 
// Checks if the inputted word is valid or not
// Input: 5 Letter word
// Output: True or false statement


void request_input(char *input, Trie s) {
  remove_newline(input);
  printf(GREEN"Enter word: ");
  fgets(input, 6, stdin);
  while (getchar() != '\n');
  remove_newline(input);
  if (TrieSearch(s, input)) {
    printf(RED"Invalid word!\n"RESET);
    request_input(input, s);
  }
  else {
    printf(GREEN"Valid word!\n"RESET);
  }
}

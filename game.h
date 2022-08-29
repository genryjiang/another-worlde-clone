#include <stdlib.h>
#include <stdbool.h>

// CONSTANT DEFINITIONS
#define MAX_STRING_LEN 6
#define TRUE 1
#define FALSE 0

#include "dict.h"
#include "list.h"

// STRUCTURE VARIABLES 
typedef struct game *Game;

struct game {
  char *input;
  // ARRAY FOR INPUTS
  // If the value at the index is 1 --> correct position
  // If the value at the index is -1 --> character does not belong in the game
  // If the value at the index is 0 --> unintalised
  // If the value at the index is 2 --> in word, wrong position
  int *inputInfo;
  List recordedInputs; 
};

// Function definitions to be made in game.c


char *get_word();

/*
  FUNCTION
  Setups game visuals
  INPUT: NONE
  OUTPUT: NONE 
*/

/* 
  FUNCTION
  Requests for input from user from STDIN
  INPUT: Trie and the chosen word
  OUTPUT: NONE
*/

void request_input(Trie s, char *chosenWord, Game g);

/*
   FUNCTION
   Loads all possible words into a SET DATA STRUCTURE made via a AVL tree
   INPUT: NONE
   OUTPUT: Set containing all valid wordle words
*/

Trie loadWords(char *word);


Game newInstance();

void FreeGame(Game g);

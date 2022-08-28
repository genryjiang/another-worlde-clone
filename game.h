
// CONSTANT DEFINITIONS
#define MAX_STRING_LEN 6
#define TRUE 1
#define FALSE 0

#include "dict.h"


// Function definitions to be made in game.c

// FUNCTION PROTOTYPES (HELPER FUNCTIONS)


// FUNCTION
// Remove newline character within a string 
// INPUT: char array
// OUTPUT: nothing
void remove_newline(char input[MAX_STRING_LEN]);

/* 
   FUNCTION
   USER-MADE STRCMPI FUNCTION TO BE USED IN THIS PROGRAM
   INPUT: TWO CHAR POINTERS
   OUTPUT: NUM (0 for equal, != 0 for not equal)

*/

int strcmpi(char* s1, char* s2);
/* 
  FUNCTION
  Returns a word from the valid wordle words.txt
  INPUT: Nothing
  OUTPUT: String containing valid word 
*/

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
  INPUT: string 
  OUTPUT: NONE
*/

void request_input(Trie s);

/*
   FUNCTION
   Loads all possible words into a SET DATA STRUCTURE made via a AVL tree
   INPUT: NONE
   OUTPUT: Set containing all valid wordle words
*/

Trie loadWords();



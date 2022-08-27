/**
 * @file wordle.c
 * @author HENRY JIANG (henryjiang13503@gmail.com)
 * @brief Text-based wordle clone that is printed onto terminal
 * @version 0.8
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

    TO DO: 

   1. IMPLEMENT RANDOM SELECTION OF WORD FROM AVAILABLE LIST *
   2. IMPLEMENT SYSTEM TO READ IN CHARACTER INPUT **
   3. IMPLEMENT SYSTEM TO SHOW CORRECT LETTERS BUT IN WRONG PLACE (YELLOW) 
      AND CORRECT LETTERS IN SAME PLACE (GREEN) ***
  
    SETUP: 

    WILL GIVE USER PROMPT ON HOW TO PLAY WORDLE AND WHAT THE COLOURS MEAN
    WILL ALSO GIVE USER POSSIBLE COMMANDS THAT CAN BE USED TO INPUT (HINTS, ETC)

    *  and ** --> Will use fgets for user input, while using rand() to draw random 
          character from the available word list. Also draw up the general look
          of the text-based game.

    HARDEST PART: PRINTING OUT STUFF IN COLOUR WHILE SHOWING THE 5
    TRIES IN WORDLE --> DO THIS WITH A COUNTER AND 5 STRINGS TO BE INPUT

    SOLUTION: USE LINKED LIST TO HANDLE PAST INPUT, WHILE USING 
    ANOTHER LINKED LIST TO HANDLE OUTPUT
    
**/

// INCLUDED STANDARD LIBRARIES
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

// NON-INCLUDED STANDARD LIBRARIES
#include "game.h"
#include "list.h"

int main() {
    
    List recordedInputs = ListNew();
    srand(time NULL);
    Trie words = loadWords();
    //SetShow(words);
    assert(words != NULL);
    char input[69420];
    request_input(input, words);
    ListInsert(recordedInputs, input);
    return 0;
}


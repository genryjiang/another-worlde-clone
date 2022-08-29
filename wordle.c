/**
 * @file wordle.c
 * @author HENRY JIANG (henryjiang13503@gmail.com)
 * @brief Text-based wordle clone that is printed onto terminal
 * @version 0.11
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

    TO DO: 

   3. IMPLEMENT SYSTEM TO SHOW CORRECT LETTERS BUT IN WRONG PLACE (YELLOW) 
      AND CORRECT LETTERS IN SAME PLACE (GREEN) ***
  
    SETUP: 

    WILL GIVE USER PROMPT ON HOW TO PLAY WORDLE AND WHAT THE COLOURS MEAN
    WILL ALSO GIVE USER POSSIBLE COMMANDS THAT CAN BE USED TO INPUT (HINTS, ETC)

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
#include "dict.h"
#include "colours.h"

int main() {
    
    Game new = newInstance();
    srand(time NULL);
    char random[6];
    Trie words = loadWords(random);
    printf("%s\n", random);
    assert(words != NULL);
    while (ListLength(new->recordedInputs) < 4) {
        request_input(words, random, new);
        ListShow(new->recordedInputs);
    }
    if (ListLength(new->recordedInputs) == 4) {
        printf(BOLDRED"GAME OVER!\n"RESET);
    }
    TrieFree(words);
    FreeGame(new);
    return 0;
}


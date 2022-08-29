// 
// DICTIONARY ADT CREATED WITH A TRIE DATA STRUCTURE
// USED TO STORE ALL WORDLE WORDS, ENSURING VALID INPUTS 
// AND LOOKUPS, ETC
// 
// 


#include <stdbool.h>
#include <stdlib.h>

typedef struct trieNode *Trie;

// Function to make a new trie node 
Trie newNode();

// Function to insert a word into the dictionary

void TrieInsert(Trie root, char *key);

// Function to search if a word is present or not in the dicitonary 

bool TrieSearch(Trie root, char *key);

// Function to print out all words stored in the trie.
//void TrieShow(Trie root, char *str, int level);

// Function to free a Trie 

void TrieFree(Trie root);

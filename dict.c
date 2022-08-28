// IMPLEMENTATION OF THE DICTIONARY ADT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <err.h>
#include <string.h>

#define CHAR_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
typedef struct trieNode *Trie;

// Data structure fo the Trie
struct trieNode {
    Trie children[CHAR_SIZE];
    bool isWordEnd;
};
/*
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
*/

Trie newNode() {
    Trie pNode = malloc(sizeof(*pNode));
    if (pNode == NULL) {
        fprintf(stderr, "ERR: NO MEMORY\n");
        exit(EXIT_FAILURE);
    }

    pNode->isWordEnd = false;

    for (int i = 0; i < CHAR_SIZE; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void TrieInsert(Trie root, char *key) {
    int index = 0;

    Trie pCrawl = root;

    for (int level = 0; level < strlen(key); level++) {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index]) {
            pCrawl->children[index] = newNode();
        }
            pCrawl = pCrawl->children[index];
    }
    pCrawl->isWordEnd = true;
}

bool TrieSearch(Trie root, char *key) {

    int index = 0;
    Trie pCrawl = root;
    if (key[0] == '\0') {
        return false;
    }
    for (int level = 0; level < strlen(key); level++) {
        index = CHAR_TO_INDEX(key[level]);
  
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isWordEnd);
}

/*
static bool isLeaf(Trie root) {
    return root->isWordEnd != false;
}
*/

// Function to print all possible words (HELPER --> DO NOT USE IN MAIN GAME)
/*
void TrieShow(Trie root, char *str, int level) {
    if (isLeaf(root)) {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < CHAR_SIZE; i++) {
        if (root->children[i]) {
            str[level] = i + 'a';
            TrieShow(root->children[i], str, level + 1);
        }
    }
}
*/


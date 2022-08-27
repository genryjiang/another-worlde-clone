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
    Trie pCrawl = root;
    int index = 0;
    for (int i = 0; i < strlen(key); i++) {
        index = CHAR_TO_INDEX(key[i]);

        if (!pCrawl->children[i]) {
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->isWordEnd;
}


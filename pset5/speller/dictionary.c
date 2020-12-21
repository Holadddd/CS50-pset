// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//prototype
unsigned int get_hash(const char *word);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536; //Max number

// Hash table
node *table[N];
int wordsCount = 0;

#define HASHTABLE_SIZE 10000

node *head = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int length =strlen(word);
    char tmp[length+1];
    tmp[length] = '\0';
    
    for (int i = 0; i < length; i++)
    {
        tmp[i] = tolower(word[i]);
    }

    int tmpIndex = get_hash(tmp);

    node *tmpNode = table[tmpIndex];
    //None of this table
    if (tmpNode == NULL)
    {
        return false;
    }

    while (tmpNode != NULL) 
    {
        if (strcasecmp(tmpNode->word, tmp) == 0)
        {
            //find the correct word
            return true;
        }
        //Looking for the next node
        tmpNode = tmpNode->next;
    }
    return false;
}
// Hashes word to a number
unsigned int get_hash(const char *word) {
    // TODO
    unsigned int hash = 5381;
    int c = *word;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];
    //Hash table
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *n= malloc(sizeof(node)); //Alloc a memory for n

        if (n == NULL) //Check n has been alloc
        {
            fclose(file);
            return false;
        }
        else
        {
            strcpy(n->word, buffer); //copy word to n->word

            n->next = NULL;

            unsigned int index = get_hash(buffer); //hash the word and get index

            //TODO:
            n->next = table[index]; //Take the first pointer
            table[index] = n;

            wordsCount ++;
        }

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // printf("The size is %i.\n", wordsCount);
    return wordsCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmpNode = table[i];

        while(tmpNode != NULL)
        {
            node *freeNode = tmpNode;

            tmpNode = tmpNode->next;

            free(freeNode);
        }
    }
    return true;
}

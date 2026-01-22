// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file_dict = fopen(dictionary, "r");
    if (file_dict == NULL)
    {
        printf("could not open dictionary file\n");
        fclose(file_dict);
        return false;
    }

    char c;
    char tmp_word[LENGTH + 1];
    int index = 0;
    while (fscanf(file_dict, "%s", tmp_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("could not allocate memory for new_node\n");
            return false;
        }
        strcpy(new_node->word, tmp_word);
        new_node->next = NULL;
        unsigned int value = hash(tmp_word);
        if (table[value] == NULL)
        {
            table[value] = new_node;
        }
        else
        {
            new_node->next = table[value];
            table[value] = new_node;
        }

    }
    fclose(file_dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

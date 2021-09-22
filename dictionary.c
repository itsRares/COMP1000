 /***************************************************************************
 *  FILE: dictionary.c
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Holds the words from the dictionary file
 *  LAST MOD: 27/10/17
 ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

/*This creates and allocates memory for the config file*/
LinkedList* createDictList() {
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/*This loads in the given file and adds the values to a linked list*/
void loadDictFile(LinkedList* dictList, char* filename)
{
    int eof = FALSE;
    int success = FALSE;
    FILE* f = fopen(filename, "r");
    char* line = (char*)malloc(MAX_LENGTH * sizeof(char));

    if (f != NULL)
    {
        do
        {
            fscanf(f, "%s", (char*)&line);
            if(feof(f)) {
                eof = TRUE;
            }
            else
            {
                printf("> %s \n", line);
                insertFirst(dictList,(char*)line);
            }
        } while (!eof);
        success = !ferror(f);
        fclose(f);
    }
    else
    {
        perror("> Error");
    }
    
    free(line);
}

/*Converts the linked list into a dynamic array*/
char* dictToArray(LinkedList* dictList)
{
    int i = 0;
    LinkedListNode* current = dictList->head;
    char* word;
    word = (char*)malloc(length(dictList)*sizeof(char));
    
    /*While no more nodes loop through and add it to words array*/
    while(current != NULL)
    {
        word[i] = (char*)malloc(MAX_LENGTH*sizeof(char));
        word[i] = (char*)current->data;
        current = current->next;
        i++;
    }
    return word;
}

/*This frees all the used memory*/
void freeDictList(LinkedList* dictList) {
    /*Loops through all nodes to free them also*/
    do
    {
        removeFirst(dictList);
    } while(length(dictList) > 0);
    free(dictList);
    
}
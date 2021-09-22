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

LinkedList* createDictList() {
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

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
}

char* dictToArray(LinkedList* dictList)
{
    int i = 0;
    LinkedListNode* current = dictList->head;
    char* word;
    word = (char*)malloc(length(dictList)*sizeof(char));
    
    while(current != NULL)
    {
        word[i] = (char*)malloc(MAX_LENGTH*sizeof(char));
        word[i] = (char*)current->data;
        current = current->next;
        i++;
    }
    return word;
}

void freeDictList(LinkedList* dictList) {
    do
    {
        removeFirst(dictList);
    } while(length(dictList) > 0);
    free(dictList);
    
}
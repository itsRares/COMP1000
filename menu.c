 /***************************************************************************
 *  FILE: menu.c
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Where all values are created and freed, the menu for the program
 *  LAST MOD: 27/10/17
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Error: Please enter the filename you would like to check\n");
    }
    else
    {
        /*Create memory and free memory also initiate variables*/
        LinkedList* wordList = createDictList();
        Config* configSet = createConfig();  
        menu(wordList, configSet, argv[1]);
        freeDictList(wordList);
        freeConfig(configSet);
    }
    return 0;
}

void menu(LinkedList* wordList, Config* configSet, char* filename)
{

    printf("=====================================\n");
    printf("            Spellchecker\n");
    printf("=====================================\n");
    
    /*Load files*/
    loadConfig(configSet);
    loadDictFile(wordList, configSet->dictfile);
}


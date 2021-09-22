 /***************************************************************************
 *  FILE: config.c
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Holds the .spellconfig info
 *  LAST MOD: 27/10/17
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

/*This creates and allocates memory for the config file*/
Config* createConfig() {
    Config* configSet;
    /*Allocates memory size of the struct*/
    configSet = (Config*)malloc(sizeof(Config));
    
    /*Sets default values*/
    configSet->dictfile = NULL;
    configSet->maxdifference = 0;
    configSet->autocorrect = 0;
    return configSet;
}

/*This loads in the given file and adds the values to a struct*/
void loadConfig(Config* configSet)
{
    /*set eof to false as default*/
    char name[MAX_LENGTH], whatIs[MAX_LENGTH];
    int ii;

    /*open the file*/
    FILE* f = fopen(CONFIG, "r");

    /*if the file is no null then run this*/
    if (f != NULL)
    {
        /*max 3 variables so for loop through then 3 times and get each value*/
        for (ii = 0; ii<3;ii++)
        {
            fscanf(f, "%s %*s %s", &name, &whatIs);
            sortConfig(configSet, name, whatIs);
        } 
        fclose(f);
    }
    else
    {
        perror("> Error");
    }
}

/*This sorts through the values in the file and adds each to
there parts in the struct*/
void sortConfig(Config* configSet, char* name, char* whatIs)
{
    /*in name dictfile add it as dictionary file name*/
    if (strcmp("dictfile",name) == 0)
    {
        configSet->dictfile = whatIs;
    }
    else if (strcmp("maxdifference",name) == 0)
    {
        configSet->maxdifference = (int)atoi(whatIs);
    }
    else if (strcmp("autocorrect",name) == 0)
    {
        if (strcmp("yes",whatIs) == 0)
        {
            configSet->autocorrect = 1;
        }
        else if (strcmp("no",whatIs) == 0)
        {
            configSet->autocorrect = 0;                            
        }
    }
}

/*This frees all the used memory*/
void freeConfig(Config* configSet) {
    free(configSet);
}
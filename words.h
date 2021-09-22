 /***************************************************************************
 *  FILE: dictionary.h
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Dictionary header file
 *  LAST MOD: 27/10/17
 ***************************************************************************/

#define FALSE 0
#define TRUE !FALSE
#define MAX_LENGTH 45
#define MAX_LINE 255

#include "linked_list.h"

LinkedList* createDictList();
void loadDictFile(LinkedList* dictList, char* filename);
char* dictToArray(LinkedList* dictList);
void freeDictList(LinkedList* dictList);
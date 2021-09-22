 /***************************************************************************
 *  FILE: config.h
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Header file
 *  LAST MOD: 27/10/17
 ***************************************************************************/

#define FALSE 0
#define TRUE !FALSE
#define MAX_LENGTH 45
#define CONFIG ".spellconf"

/*Creates a struct which holds the dict file name, maxdifference and autocorrect which is on or off*/
typedef struct {
    char* dictfile;
    int maxdifference;
    int autocorrect;
} Config;

/*defines functions*/
Config* createConfig();
void loadConfig(Config* configSet);
void sortConfig(Config* configSet, char* name, char* whatIs);
void freeConfig(Config* configSet);
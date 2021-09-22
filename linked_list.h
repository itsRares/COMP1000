 /***************************************************************************
 *  FILE: linked_list.h
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Linked list header file
 *  LAST MOD: 27/10/17
 *  REFERENCE: Based off my own code in Practical 6, ../UCP/P06/linked_list.c
 ***************************************************************************/

/*Creates a struct which holds the nodes*/
typedef struct LinkedListNode {
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;

/*Creates a struct which holds the linked list */
typedef struct {
    LinkedListNode* head;
} LinkedList;

/*defines functions*/
void insertFirst(LinkedList* list, void* value);
int length(LinkedList* list);
void removeFirst(LinkedList* list);
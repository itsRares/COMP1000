 /***************************************************************************
 *  FILE: linked_list.c
 *  AUTHOR: Rares Popa - 19159700
 *  UNIT: COMP1000 - Assignment
 *  PURPOSE: Holds the words as a linked list
 *  LAST MOD: 27/10/17
 *  REFERENCE: Based off my own code in Practical 6, ../UCP/P06/linked_list.c
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* Inserts the node at the beginning of the linked list */
void insertFirst(LinkedList* list, void* value)
{
    /*Allocate memory*/
    struct LinkedListNode* newNode = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    
    /*If linked list is empty then do this else set the next to the head value*/
    if (list->head == NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
        list->head = newNode;
    }
    else
    {
        newNode->data = value;
        newNode->next = list->head;
        list->head = newNode;
    }
}

/*remove the first node from the linked list*/
void removeFirst(LinkedList* list)
{
    /*Define temp value for later use*/
    struct LinkedListNode* temp = list->head;
    /*if not null set head value to next*/
    if (list->head != NULL)
    {
        list->head = list->head->next;
    }
    else
    {
        printf("No value here ");
    }
    
    /*Free up mem*/
    free(temp);
}

/*Get the length of the linked list*/
int length(LinkedList* list)
{
    LinkedListNode* current;
    int length = 0;
    current = list->head;
    /*Until null keep looping through linked list*/
    while(current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}


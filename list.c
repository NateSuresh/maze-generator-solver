//Nathanael Suresh CSEN 12 Lab 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <assert.h>
#include <stdbool.h>

typedef struct node{
    void *data;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct list{
    int count;
    NODE *head;
    int (*compare)();
} LIST;

// Creates a new list structure and sets up the comparison function
LIST *createList(int (*compare)())
{
    LIST *lp;
    lp = malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->count = 0;
    lp->compare = compare;
    lp->head = malloc(sizeof(NODE));
    assert(lp->head != NULL);
    lp->head->next = lp->head;
    lp->head->prev = lp->head;
    return lp;
}

// Frees memory used by the list and its nodes
void destroyList(LIST *lp)
{
    assert(lp != NULL);
    NODE *pDel, *pNext;
    assert(lp != NULL);
    pDel = lp->head;
    do
    {
        pNext = pDel->next;
        free(pDel);
        pDel = pNext;
    } while(pDel != lp->head);
    free(lp);
}

// Returns the number of elements currently in the list
int numItems(LIST *lp)
{
    assert(lp != NULL);
    return lp->count;
}

// Inserts a new item at the front of the list
void addFirst(LIST *lp, void *item)
{
    assert(lp != NULL);
    NODE *pFirst;
    pFirst = malloc(sizeof(NODE));
    assert(pFirst != NULL);
    pFirst->data = item;
    lp->head->next->prev = pFirst;
    pFirst->next = lp->head->next;
    pFirst->prev = lp->head;
    lp->head->next = pFirst;
    lp->count++;
    return;
}

// Appends an item to the end of the list
void addLast(LIST *lp, void *item)
{
    assert(lp != NULL);
    NODE *pLast;
    pLast = malloc(sizeof(NODE));
    assert(pLast != NULL);
    pLast->data = item;
    lp->head->prev->next = pLast;
    pLast->next = lp->head;
    pLast->prev = lp->head->prev;
    lp->head->prev = pLast;                          
    lp->count++;                                    
    return;
}

// Removes and returns the first item from the list
void *removeFirst(LIST *lp)
{
    assert(lp != NULL);
    NODE *pDelFirst = lp->head->next;
    void *removeF = pDelFirst->data;
    lp->head->next = pDelFirst->next;
    pDelFirst->next->prev = lp->head;                    
    free(pDelFirst);                                    
    lp->count--;
    return removeF;
}

// Removes and returns the last item from the list
void *removeLast(LIST *lp)
{
    assert(lp != NULL);
    assert(lp->count > 0);
    NODE *pDelLast = lp->head->prev;
    void *removeL = pDelLast->data;
    lp->head->prev = pDelLast->prev;
    pDelLast->prev->next = lp->head;
    free(pDelLast);
    lp->count--;
    return removeL;
}

// Retrieves the first item without removing it
void *getFirst(LIST *lp)
{
    assert(lp != NULL);
    assert(lp->count > 0);
    return lp->head->next->data;
}

// Retrieves the last item without removing it
void *getLast(LIST *lp)
{
    assert(lp != NULL);
    assert(lp->count > 0);
    return lp->head->prev->data;
}

// Deletes a matching item from the list if found
void removeItem(LIST *lp, void *item)
{
    assert(lp != NULL);
    if(lp->count > 0)
    {
        NODE *pDel = lp->head->next;
        while(pDel != lp->head) {
            if((*lp->compare)(pDel->data, item) == 0) {
                pDel->prev->next = pDel->next;
                pDel->next->prev = pDel->prev;
                free(pDel);
                lp->count--;
                break;
            }
            else
            {
                pDel = pDel->next;
            }
        }
    }
    return;
}

// Searches for a matching item and returns it if found
void *findItem(LIST *lp, void *item)
{
    assert(lp != NULL);
    NODE *find;
    if(lp->count > 0)
    {
        find = lp->head->next;
        while(find != lp->head)
        {
            if((*lp->compare)(find->data,item) == 0)
            {  
                return find->data;
            }  
            else
            {
                find = find->next;
            }
        }
    }
    return NULL;
}  

// Copies all items from the list into a new array and returns it
void *getItems(LIST *lp)
{
    assert(lp != NULL);
    int i;
    void **get;
    NODE *item;
    item = lp->head->next;
    get = malloc(sizeof(void *)*lp->count);
    assert(get != NULL);
    while(i<lp->count && item != lp->head)
    {
        get[i] = item->data;
        item = item->next;
        i++;
    }
    return get;
}

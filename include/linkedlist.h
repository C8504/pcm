#ifndef H_LINKEDLIST
#define H_LINKEDLIST
#include "ORC.h"
typedef struct ORCLinkedNode {
    char               *elem;
    struct ORCLinkedNode *next;
    struct ORCLinkedNode *prev;
} ORCLinkedNode;

typedef struct ORCLinkedList{
    struct ORCLinkedNode *first;
    struct ORCLinkedNode *last;
} ORCLinkedList;

typedef ORCLinkedNode* ORCLinkedNode_p;
typedef ORCLinkedList* ORCLinkedList_p;

/* ORCLinkedNode functions */
void ORCNode_Free           (ORCLinkedNode **node);
int  ORCNode_Alloc_and_Init (ORCLinkedNode **node, const char* elem);

/* ORCLinkedList functions */
int  ORCLinkedList_Init   (ORCLinkedList **list);
int  ORCLinkedList_Clear  (ORCLinkedList *list);
int  ORCLinkedList_Free   (ORCLinkedList **list);

int  ORCLinkedList_Append (ORCLinkedList *list, const char* elem);
int  ORCLinkedList_Insert (ORCLinkedList *list, int pos, const char* elem);
int  ORCLinkedList_Pop    (ORCLinkedList *list, int flag);

int  ORCLinkedList_Length (ORCLinkedList *list);

int  ORCLinkedList_Output (ORCLinkedList *list, const char* sp);
#endif

#ifndef H_LINKEDLIST
#define H_LINKEDLIST
#include "C.h" 
typedef struct CLinkedNode {
    char               *elem;     
    struct CLinkedNode *next;
    struct CLinkedNode *prev;
} CLinkedNode;

typedef struct CLinkedList{
    struct CLinkedNode *first;
    struct CLinkedNode *last;
} CLinkedList;

typedef CLinkedNode* CLinkedNode_p;
typedef CLinkedList* CLinkedList_p;

/* CLinkedNode functions */
void CNode_Free           (CLinkedNode **node);
int  CNode_Alloc_and_Init (CLinkedNode **node, const char* elem);

/* CLinkedList functions */
int  CLinkedList_Init   (CLinkedList **list);
int  CLinkedList_Clear  (CLinkedList *list);
int  CLinkedList_Free   (CLinkedList **list);

int  CLinkedList_Append (CLinkedList *list, const char* elem);
int  CLinkedList_Insert (CLinkedList *list, int pos, const char* elem);
int  CLinkedList_Pop    (CLinkedList *list, int flag);

int  CLinkedList_Length (CLinkedList *list);

int  CLinkedList_Output (CLinkedList *list, const char* sp);
#endif

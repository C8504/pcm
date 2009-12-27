#ifndef H_LINKEDLIST
#define H_LINKEDLIST
#include "ORC.h"
typedef struct ORClinkednode {
    char               *elem;
    struct ORClinkednode *next;
    struct ORClinkednode *prev;
} ORClinkednode;

typedef struct ORClinkedlist{
    struct ORClinkednode *first;
    struct ORClinkednode *last;
} ORClinkedlist;

typedef ORClinkednode* ORClinkednodep;
typedef ORClinkedlist* ORClinkedlistp;

/* ORClinkednode functions */
void ORCnodefree           (ORClinkednode **node);
int  ORCnodeallocandinit (ORClinkednode **node, const char* elem);

/* ORClinkedlist functions */
int  ORClinkedlistinit   (ORClinkedlist **list);
int  ORClinkedlistclear  (ORClinkedlist *list);
int  ORClinkedlistfree   (ORClinkedlist **list);

int  ORClinkedlistappend (ORClinkedlist *list, const char* elem);
int  ORClinkedlistinsert (ORClinkedlist *list, int pos, const char* elem);
int  ORClinkedlistpop    (ORClinkedlist *list, int flag);

int  ORClinkedlistlength (ORClinkedlist *list);

int  ORClinkedlistoutput (ORClinkedlist *list, const char* sp);
#endif

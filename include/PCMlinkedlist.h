#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#ifdef __cplusplus
extern "C" {
#endif

#include "PCM.h"

   typedef struct PCMlinkednode {
      char               *elem;
      struct PCMlinkednode *next;
      struct PCMlinkednode *prev;
   } PCMlinkednode;

   typedef struct PCMlinkedlist{
      struct PCMlinkednode *first;
      struct PCMlinkednode *last;
   } PCMlinkedlist;

   typedef PCMlinkednode* PCMlinkednodep;
   typedef PCMlinkedlist* PCMlinkedlistp;

   /* PCMlinkednode functions */
   void PCMnodefree           (PCMlinkednode **node);
   int  PCMnodeallocandinit (PCMlinkednode **node, const char* elem);

   /* PCMlinkedlist functions */
   int  PCMlinkedlistinit   (PCMlinkedlist **list);
   int  PCMlinkedlistclear  (PCMlinkedlist *list);
   int  PCMlinkedlistfree   (PCMlinkedlist **list);

   int  PCMlinkedlistappend (PCMlinkedlist *list, const char* elem);
   int  PCMlinkedlistinsert (PCMlinkedlist *list, int pos, const char* elem);
   int  PCMlinkedlistpop    (PCMlinkedlist *list, enum PCMPOPTYPE type);

   int  PCMlinkedlistlength (PCMlinkedlist *list);

   int  PCMlinkedlistoutput (PCMlinkedlist *list, const char* sp);

#ifdef __cplusplus
}
#endif

#endif

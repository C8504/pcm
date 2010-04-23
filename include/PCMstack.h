#ifndef H_ORCSTACK
#define H_ORCSTACK


#ifdef __cplusplus
extern "C" {
#endif
   #include "ORC.h"
   typedef struct {
      int    top;
      void   **data;
      size_t size;
   } ORCstack;

   int   ORCstackcreate  (ORCstack **sp, size_t size);
   void  ORCstackfree    (ORCstack **sp, FREEFUNC freefunc);
   void* ORCstackpop     (ORCstack *s);
   int   ORCstackpush    (ORCstack *s, void *elem);
   int   ORCstackisempty (ORCstack *s);

#ifdef __cplusplus   
}
#endif

#endif

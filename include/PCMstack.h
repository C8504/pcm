#ifndef H_PCMSTACK
#define H_PCMSTACK


#ifdef __cplusplus
extern "C" {
#endif
   #include "PCM.h"
   typedef struct {
      int    top;
      void   **data;
      size_t size;
   } PCMstack;

   int   PCMstackcreate  (PCMstack **sp, size_t size);
   void  PCMstackfree    (PCMstack **sp, FREEFUNC freefunc);
   void* PCMstackpop     (PCMstack *s);
   int   PCMstackpush    (PCMstack *s, void *elem);
   int   PCMstackisempty (PCMstack *s);

#ifdef __cplusplus   
}
#endif

#endif

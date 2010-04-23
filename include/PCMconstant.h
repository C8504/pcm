#ifndef H_CONSTANT
#define H_CONSTANT

#ifdef __cplusplus
extern "C" {
#endif
   // POP type in ORCseqlist
   enum ORCPOPTYPE {ORCPOPQUEUE = 0, ORCPOPSTACK};

   #define ORCLISTINITSIZE    5
   #define ORCLISTINCREMENT   5

   #define ORCFILEMAXLINE         1000
   #define ORCFILENAME            20
   #define ORCCHAR                128 

   enum BOOL {
      FALSE,
      TRUE
   };
   // ERROR CODE
   enum ORCERR {
      ORCERRSTART = 10000,
      ORCERRNOMEMORY,
      ORCERRNOTVALIDINDEX,
      ORCERRNULLPOINTER,
      ORCERRELEMENTNOTFOUND,
      ORCERREMPTYLIST,
      ORCERRNOTSTACKANDQUEUE,
      ORCERRWRONGSORTALG,
      ORCERREND   = 20000
   };

   // Alg
   enum ORCSORTALG {ORCALGSORTSELECT = 80001,
                    ORCALGSORTBUBBLE,
                    ORCALGSORTQUICK,
                    ORCALGSORTSHELL};
   enum ORCSEARCHALG {ORCALGORIGINFIND = 90001,
                      ORCALGBINFIND};

   // function handle

   // free momery
   typedef void (*FREEFUNC) (void* p);


#ifdef __cplusplus
}
#endif

#endif


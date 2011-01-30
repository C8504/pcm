#ifndef H_CONSTANT
#define H_CONSTANT

#ifdef __cplusplus
extern "C" {
#endif
    // POP type in PCMseqlist
    enum PCMPOPTYPE {
        PCMPOPQUEUE = 0, PCMPOPSTACK
                  };

#define PCMLISTINITSIZE    5
#define PCMLISTINCREMENT   5

#define PCMFILEMAXLINE         1000
#define PCMFILENAME            256
#define PCMCHAR                128

    enum BOOL
    {
        FALSE,
        TRUE
    };
    // ERROR CODE
    enum PCMERR
    {
        PCMERRSTART = 10000,
        PCMERRNOMEMORY,
        PCMERRNOTVALIDINDEX,
        PCMERRNULLPOINTER,
        PCMERRELEMENTNOTFOUND,
        PCMERREMPTYLIST,
        PCMERRNOTSTACKANDQUEUE,
        PCMERRWRONGSORTALG,
        PCMERREND   = 20000
    };

    // Alg
    enum PCMSORTALG {PCMALGSORTSELECT = 80001,
                     PCMALGSORTBUBBLE,
                     PCMALGSORTQUICK,
                     PCMALGSORTSHELL,
                     PCMALGSORTINSERT
                    };
    enum PCMSEARCHALG {PCMALGORIGINFIND = 90001,
                       PCMALGBINFIND
                      };

    // function handle

    // free momery
    typedef void (*FREEFUNC) (void* p);

    // macros
#define THROW(function)  if ( error = function ) { \
                              printf ("In %s, line %d ;",__FILE__, __LINE__); \
                              goto TERMINATE;                  \
                            }

#define CALL(function) if ( error = function ) goto TERMINATE;

#define PCM_ALLOC(x,n,t)        do {                            \
      assert(x == NULL);                                           \
      x = malloc((n) * sizeof(t));                             \
      if ( x == NULL ) {                                           \
         THROW(PCMERRNOMEMORY);                                    \
      }                                                            \
   } while(0)

#define PCM_FREE(x)        do {        \
      if ( (x) != NULL) {                 \
         free (x);                        \
         (x) = NULL;                      \
      }                                   \
   } while(0)

#define DERROR int error = 0

#define RETURN TERMINATE:      \
                     return error

#define VER "1.0.0.0"


#ifdef __cplusplus
}
#endif

#endif


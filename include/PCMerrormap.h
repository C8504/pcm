#ifndef H_ERRORMAP
#define H_ERRORMAP

#ifdef __cplusplus
extern "C" {
#endif

   typedef struct {
      int        error;
      const char *str;
   } ErrorMap;

   static
      ErrorMap errorMap[] = {
         {ORCERRNOMEMORY,                "Out of memory "},
         {ORCERRNULLPOINTER,             "Null pointer for required data "},
         {ORCERRNOTVALIDINDEX,           "Not valid index"},
         {ORCERRELEMENTNOTFOUND,         "Element not found"},
         {ORCERREMPTYLIST,               "Empty list"},
         {ORCERRNOTSTACKANDQUEUE,        "Can not use pop in stack and queue"},
         {ORCERRWRONGSORTALG,            "Not this kind sort algorithm"},
      };

#ifdef __cplusplus
}
#endif

#endif

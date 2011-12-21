#ifndef H_ERRORMAP
#define H_ERRORMAP

#ifdef __cplusplus
extern "C" {
#endif

   typedef struct
   {
      int        error;
      const char *str;
   } ErrorMap;

   static ErrorMap errorMap[] =
   {
      {PCMERRNOMEMORY,                "Out of memory "},
      {PCMERRNULLPOINTER,             "Null pointer for required data "},
      {PCMERRNOTVALIDINDEX,           "Not valid index"},
      {PCMERRELEMENTNOTFOUND,         "Element not found"},
      {PCMERREMPTYLIST,               "Empty list"},
      {PCMERRNOTSTACKANDQUEUE,        "Can not use pop in stack and queue"},
      {PCMERRWRONGSORTALG,            "Not this kind sort algorithm"},
   };

#ifdef __cplusplus
}
#endif

#endif

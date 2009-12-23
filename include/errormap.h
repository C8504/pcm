#ifndef H_ERRORMAP
#define H_ERRORMAP
typedef struct {
   int        error;
   const char *str;
} ErrorMap;

static
ErrorMap errorMap[] = {
   {CERR_NO_MEMORY,                "Out of memory "},
   {CERR_NULL_POINTER,             "Null pointer for required data "},
   {CERR_NOTVALID_INDEX,           "Not valid index"},
   {CERR_ELEMENT_NOT_FOUND,        "Element not found"},
   {CERR_EMPTY_LIST,               "Empty list"},
   {CERR_NOT_STACK_AND_QUEUE,      "Cannot use pop in stack and queue"},
};
#endif

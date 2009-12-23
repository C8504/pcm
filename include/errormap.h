#ifndef H_ERRORMAP
#define H_ERRORMAP
typedef struct {
   int        error;
   const char *str;
} ErrorMap;

static
ErrorMap errorMap[] = {
   {ORCERR_NO_MEMORY,                "Out of memory "},
   {ORCERR_NULL_POINTER,             "Null pointer for required data "},
   {ORCERR_NOTVALID_INDEX,           "Not valid index"},
   {ORCERR_ELEMENT_NOT_FOUND,        "Element not found"},
   {ORCERR_EMPTY_LIST,               "Empty list"},
   {ORCERR_NOT_STACK_AND_QUEUE,      "Cannot use pop in stack and queue"},
};
#endif

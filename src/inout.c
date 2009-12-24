/* inout by John Cui
   scanf("%d%d", &a, &b);
   如果a和b都被成功读入，那么scanf的返回值就是2
   如果只有a被成功读入，返回值为1
   如果a和b都未被成功读入，返回值为0
   如果遇到错误或遇到end of file，返回值为EOF。
   */
#include "inout.h"
#include "seqlist.h"

int inout()
{
   int error = 0;
   int num = 0;

   int max = 0;
   int count = 0;
   int sum = 0;

   ORCSeqList *list = NULL;
   error = ORCSeqList_Init(&list);
   if ( error )  goto TERMINATE;

   printf("Please input intergers:\n");

   while (1 == scanf ("%d", &num)) {
      error = ORCSeqList_Insert(list, count, num);
      if ( error )  goto TERMINATE;
      sum += num;

      if ( 0 == count ) {
         max = num;
      }
      else {
         if ( max < num ) {
            max = num;
         }
      }
      count++;
   }

   error = ORCSeqList_Sort (list, list->length, ORC_ALG_SORT_SELECT);
   if ( error )  goto TERMINATE;

   //error = ORCSeqList_Sort (list, list->length, ORC_ALG_SORT_BUBBLE);
   //if ( error )  goto TERMINATE;

   // error = ORCSeqList_Sort (list, list->length, 0);
   //if ( error )  goto TERMINATE;

   error = ORCSeqList_Output (list);
   if ( error )  goto TERMINATE;

   error = ORCSeqList_Free (&list);
   if ( error )  goto TERMINATE;

   printf ("You have input %d integers\n", count);
   printf ("The max one is %d\n"         , max);
   printf ("The sum of them is %d\n"     , sum);

TERMINATE:
   return error;
} /* End of inout */

/* inout by John Cui
   scanf("%d%d", &a, &b);
      如果a和b都被成功读入，那么scanf的返回值就是2
      如果只有a被成功读入，返回值为1
      如果a和b都未被成功读入，返回值为0
      如果遇到错误或遇到end of file，返回值为EOF。
   */
#include "PCMarray.h"

int inout()
{
   int error = 0;
   int num = 0;

   int max = 0;
   int count = 0;
   int sum = 0;

   PCMarray *list = NULL;
   CALL(PCMarrayinit(&list));

   printf("Please input intergers:\n");

   while (1 == scanf ("%d", &num)) {
      CALL(PCMarrayinsert(list, count, num));
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

   CALL(PCMarraysort (list, list->length, PCMALGSORTSELECT));

   //CALL(PCMarraysort (list, list->length, PCMALGSORTBUBBLE));
   //if ( error )  goto TERMINATE;

   // CALL(PCMarraysort (list, list->length, 0));
   //if ( error )  goto TERMINATE;

   CALL(PCMarrayoutput (list));

   CALL(PCMarrayfree (&list));

   printf ("You have input %d integers\n", count);
   printf ("The max one is %d\n"         , max);
   printf ("The sum of them is %d\n"     , sum);

TERMINATE:
   return error;
} /* End of inout */

   int
main (void)
{
   int i = 0;
   int error = 0;

   CALL(inout());

TERMINATE:

   PCMcheckerror (error);
   return 0;
}


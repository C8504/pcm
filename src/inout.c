/* inout by John Cui
   scanf("%d%d", &a, &b);
   ���a��b�����ɹ����룬��ôscanf�ķ���ֵ����2
   ���ֻ��a���ɹ����룬����ֵΪ1
   ���a��b��δ���ɹ����룬����ֵΪ0
   ����������������end of file������ֵΪEOF��
   */
#include "inout.h"
#include "ORCseqlist.h"

int inout()
{
   int error = 0;
   int num = 0;

   int max = 0;
   int count = 0;
   int sum = 0;

   ORCseqlist *list = NULL;
   error = ORCseqlistinit(&list);
   if ( error )  goto TERMINATE;

   printf("Please input intergers:\n");

   while (1 == scanf ("%d", &num)) {
      error = ORCseqlistinsert(list, count, num);
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

   error = ORCseqlistsort (list, list->length, ORCALGSORTSELECT);
   if ( error )  goto TERMINATE;

   //error = ORCseqlistsort (list, list->length, ORCALGSORTBUBBLE);
   //if ( error )  goto TERMINATE;

   // error = ORCseqlistsort (list, list->length, 0);
   //if ( error )  goto TERMINATE;

   error = ORCseqlistoutput (list);
   if ( error )  goto TERMINATE;

   error = ORCseqlistfree (&list);
   if ( error )  goto TERMINATE;

   printf ("You have input %d integers\n", count);
   printf ("The max one is %d\n"         , max);
   printf ("The sum of them is %d\n"     , sum);

TERMINATE:
   return error;
} /* End of inout */

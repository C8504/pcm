#include <stdio.h>

union u{
   struct {
      int type;
   } s;
   struct {
      int type;
      int intval;
   } si;
   struct {
      int type;
      float floatval;
   } sf;
};

int main(void)
{
   union u myu;
   myu.sf.type = 4;
   myu.sf.floatval = 2.2;

   printf("%d\n", myu.si.type);
   printf("%d", myu.si.intval);

   return 0;
}

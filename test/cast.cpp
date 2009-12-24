#include <iostream>
#include <cstring>
using namespace std;

class Base
{
   public:
      void m1()
      {
         cout << "m1" << endl;
      }
};

class Derived:public Base
{
   public:
      void m2()
      {
         cout << "m2" << endl;
      }
};

void fun(Base* base)
{
   //Derived* derived = static_cast<Derived*>(base);
   Derived* derived = static_cast<Derived*>(base);
   if(derived)
   {
      derived->m2();
   }
}
int main()
{
   Base base;
   fun(&base);
   return 0;
}


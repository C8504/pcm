#include<iostream>
#include <list>

using namespace std;

int main()
{
   cout<<"hello, STL\n";

   list<double>  l;
   l.push_back(9.0);

   cout<<"l1"<<endl;
   for (list<double>::iterator itr = l.begin(); itr != l.end(); ++itr)
   {
      cout<<*itr;
   }

   list<double> l2(l);

   list<double>::iterator itr1 = l2.end();
   itr1--;
   l2.erase(itr1);

   cout<<endl<<"l2"<<endl;
   for (list<double>::iterator itr = l2.begin(); itr != l2.end(); ++itr)
   {
      cout<<*itr;
   }
   cout<<endl<<"push elements to l2"<<endl;
   l2.push_back(8.0);
   l2.push_front(1.0);

   for (list<double>::iterator itr = l2.begin(); itr != l2.end(); ++itr)
   {
      cout<<*itr;
   }
   cout<<endl;

   list<double>::iterator itr2 = l2.begin(); itr2++;
   list<double>::iterator itr3 = l2.end(); itr3--;

   l2.erase(itr2, itr3);

   for (list<double>::iterator itr = l2.begin(); itr != l2.end(); ++itr)
   {
      cout<<*itr;
   }

   //cout<<v[0]<<endl;
   //cout<<l.size()<<endl;
   //cout<<l.back();

   return 0;
}

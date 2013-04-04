#include<iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
   cout<<"hello, STL\n";
   vector<int> v(10);
   list<double>  l(10);
   l.push_back(9.0);
   cout<<v[0]<<endl;
   cout<<l.size()<<endl;
   cout<<l.back();
   return 0;
}

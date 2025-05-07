#include <iostream>
#include<deque>
using namespace std;

void reset(deque<int>&q, int n)
{
    for(int i=1; i<=n; i++) q.push_back(i);
}

int main() {
   int n;
   cin>>n;
   deque<int>q;
   
   reset(q,n);
   
   while(q.size()!=1)
   {
       q.pop_front();
       q.push_back(q.front());
       q.pop_front();
   }
   cout<<q.front();
   return 0;
}
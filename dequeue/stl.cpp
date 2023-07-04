#include<bits/stdc++.h>
using namespace std;
int main()
{
deque<int>dq={1,2,3};
dq.push_front(0);
dq.push_back(4);
for(auto x : dq){
 cout<<x<<" ";
}
cout<<endl<<dq.front()<<" "<<dq.back()<<endl;
auto it = dq.begin();
dq.insert(it,20);
dq.pop_back();
dq.pop_front();

return 0;
}
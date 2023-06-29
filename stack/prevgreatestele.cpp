#include<bits/stdc++.h>
using namespace std;
void prevgreatest(vector<int>v){
 stack<int>s;
 s.push(0);
 cout<<-1<<" ";
 for (int i = 1; i < v.size(); i++)
 {
  /* code */
  while(s.empty() == false && v[s.top()] <= v[i]){ //jb tk stack elements chhote h tb tk unhe pop krte jao
   s.pop(); 
  }
  //jese hi bda element mila ya stack empty hua
  int span = s.empty() ? -1 : v[s.top()];
  cout<<span<<" ";
  s.push(i);
 }
 
}
int main()
{
int n;
cin>>n;
vector<int> v(n);
for (int i = 0; i < n; i++)
{
cin >> v[i];
}
prevgreatest(v);
return 0;
}
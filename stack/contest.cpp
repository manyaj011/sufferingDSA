#include<bits/stdc++.h>
using namespace std;
int conte(string s){
 stack<int>st;
 st.push(s[0]);
 int count = 0;
 for (int i = 1; i < s.length(); i++)
 {
  if(s[i] != st.top() && s[i] != s[i+1]){
   count++;
  }
  else{
   
  }
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
return 0;
}
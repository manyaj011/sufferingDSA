#include<bits/stdc++.h>
using namespace std;
void generate(string d1 , string d2 , int n){
 queue<string>q;
 q.push(d1);
 q.push(d2);
 for(int count = 0; count < n ; count++){
  string x = q.front();
  cout<<x<<" ";
  q.pop();
  q.push(x + d1);
  q.push(x + d2);
 }
}
int main()
{
 string d1 , d2;
 int n;
 cout<<"enter digit-1 and digit-2"<<endl;
 cin>>d1>>d2;
 cout<<"enter the number n ";
 cin>>n;
 generate(d1, d2, n);
return 0;
}
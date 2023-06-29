// #include<bits/stdc++.h>
// using namespace std;
// int evaluation(string s){
//  stack<int>st;
//  int res = 0;
//  for(int i = 0;i<s.length() ;i ++){
//   if(isdigit(s[i]) == 1){ //isdigit funtions returns the ascii value so to return the actual numerical value subtract it with the ascii value of 0 
//    st.push(s[i] - '0');
//   }
//   else{
//    int val1 = st.top();
//    st.pop();
//    int val2 = st.top();
//    st.pop();
   
//    // int x1 = st.pop() - '0';
//    // int x2 = st.pop() - '0';
//    switch(s[i]){
//     case '+':
//      res = val2 + val1;
//      break;
//     case '-':
//      res = val2 - val1;
//      break;
//     case '*':
//      res = val2 * val1;
//      break;
//     case '/':
//      res = val2 / val1;
//      break;
//     case '^':
//      res = pow(val2 ,val1);
//      break;
//    }
//    st.push(res);
//   }
//  }
//  return st.top();
// }
// int main()
// {

// string s;;
// cin >> s;

// cout<<evaluation(s);
// return 0;
// }
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluation(string s)
{
 stack<int> st;
 int res = 0;
 for (int i = 0; i < s.length(); i++)
 {
  if (isdigit(s[i]))
  {
   st.push(s[i] - '0');
  }
  else
  {
   int val1 = st.top();
   st.pop();
   int val2 = st.top();
   st.pop();

   switch (s[i])
   {
   case '+':
    res = val2 + val1;
    break;
   case '-':
    res = val2 - val1;
    break;
   case '*':
    res = val2 * val1;
    break;
   case '/':
    res = val2 / val1;
    break;
   case '^':
    res = pow(val2, val1);
    break;
   }
   st.push(res);
  }
 }
 return st.top(); // Return the final result from the stack
}

int main()
{
 int n;
 cin >> n;
 string s;
 cin >> s;
 cout << evaluation(s);
 return 0;
}

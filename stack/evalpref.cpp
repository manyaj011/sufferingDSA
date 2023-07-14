// this is the code of evaluation of prefix expression
#include <bits/stdc++.h>
using namespace std;
int evaluation(string s)
{
 stack<int> st;
 int res = 0;
 for (int i = s.length() - 1; i >= 0; i--)
 {
  if (isdigit(s[i]))
  { // isdigit function returns the ASCII value of the character so to return the numerical value subtract the ASCII value of 0
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
    res = val1 + val2;
    break;
   case '-':
    res = val1 - val2;
    break;
   case '*':
    res = val1 * val2;
    break;
   case '/':
    res = val1 / val2;
    break;
   case '^':
    res = pow(val1, val2);
    break;
   }
  }
  st.push(res);
 }
 return st.top();
}
int main()
{
 string s;
 cin>>s;
 cout<<evaluation(s);
 return 0;
}
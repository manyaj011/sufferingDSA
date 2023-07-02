#include <bits/stdc++.h>
using namespace std;
void generate(string d1, string d2, string d3, string d4, string d5, string d6, string d7, string d8, string d9, int n)
{
 queue<string> q;
 q.push(d1); //when a string is already in a variable no need to put it into commas
 q.push(d2);
 q.push(d3);
 q.push(d4);
 q.push(d5);
 q.push(d6);
 q.push(d7);
 q.push(d8);
 q.push(d9);
 for (int count = 0; count < n; count++)
 {
  string x = q.front();
  cout << x << " ";
  q.pop();
  q.push(x + "0"); //single as well as dbl both can be used 
  q.push(x + '1');//+ is used to concatnate this sme syntax is in js also
  q.push(x + '2');
  q.push(x + '3');
  q.push(x + '4');
  q.push(x + '5');
  q.push(x + '6');
  q.push(x + '7');
  q.push(x + '8');
  q.push(x + '9');
 }
}
int main()
{

 // cin >> d1 >> d2 >>d3;
 int n;
 cout << "enter the number n ";
 cin >> n;
 generate("1", "2", "3", "4", "5", "6", "7", "8", "9", n); //this structure is imp -->instead of single inverted double inverted commas will be used
 //-->the other method to initialize is 
 //string d1,,,d9 as 1,,,9
 //generate(d1,,,d9,n);
 return 0;
}
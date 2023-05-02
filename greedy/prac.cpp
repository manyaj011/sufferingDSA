#include <iostream>
using namespace std;

int main()
{
  
  int alice,bob;
  cin>>alice>>bob;
  int days = 0;
  if (alice * 2 > bob && bob * 2 > alice)
    days++;

  cout << days << endl;
 
 return 0;
}

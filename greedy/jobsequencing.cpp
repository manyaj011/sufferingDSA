#include <bits/stdc++.h>
using namespace std;
class job
{
public:
 char id;    // job id
 int dead;   // deadiline of the job
 int profit; // profit if job is over before or on deadline
};
bool mycmp(job a, job b)
{
 return (a.profit > b.profit);
}
void jobsq(job arr[], int n)
{
 sort(arr, arr + n, mycmp);
 int result[n];          // to store result
 bool slot[n] = {false}; // to get track of free slots and initialise all slots to be free

 // iterate through all given jobs
 for (int i = 0; i < n; i++)
 {
  for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
  {
   if (slot[j] == false)
   {
    result[j] = i;  // add this job to result
    slot[j] = true; // make this slot occupied
    break;
   }
  }
 }
 for (int i = 0; i < n; i++)
 {
  if (slot[i])
  {
   cout << result[i] << " ";
  }
 }
 cout << endl;
 // print the result
 int s = 0;
 for (int i = 0; i < n; i++)
 {
  if (slot[i]) // result n  size ka h lekin zaruri nhi h saare full ho isliye vhi elements liye jinke slots full h
  {
   cout << arr[result[i]].id << " ";
   s += arr[result[i]].profit;
  }
 }
 cout << endl;
 cout << "the maximum profit is-" << s;
}
int main()
{
 int n;
 cin >> n;
 job arr[n] = {{'a', 2, 100},
               {'b', 1, 50},
               {'c', 2, 10},
               {'d', 1, 20},
               {'e', 3, 30}}; // how to write pair<char,int,int>arr[]
 cout << "following is the maximum profit sequence of the job - ";
 jobsq(arr, n);
 return 0;
}

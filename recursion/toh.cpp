 #include<bits/stdc++.h>
 using namespace std;

 long long toh(int N, int from, int to, int aux) {
        if(N==1) 
        {
            cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1,aux,to,from);
        return (pow(2,N)-1);
    }
int main()
{
    cout<<"enter no of plates-"; int N; cin>>N;
    cout<<"the process is -"<<endl<<toh(N,1,3,2);
}
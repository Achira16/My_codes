#include<bits/stdc++.h>
using namespace std;
void toh(int n,char s,char d,char aux)
{
    if(n == 1)
    {
        cout<<"Move disk 1 from "<<s<<"-->"<<d<<endl;
        return;
    }
    toh(n-1,s,aux,d);
    cout<<"Move disk "<<n<<" from "<<s<<"-->"<<d<<endl;
    toh(n-1,aux,d,s);
}
int main()
{
    int n;
    cin >> n;
    toh(n,'a','c','b');
}
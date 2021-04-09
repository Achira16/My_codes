#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int curr = 0;
    int n;
    cin>>n;
    while(n--)
    {
        int d;
        cin>>d;
        a.push_back(d);
        int s = a.size();
        if(s >1 && (s&1)){
            curr++;
        }
        cout<<a[curr]<<endl;
    }
}
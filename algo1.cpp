#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    IOS;
    int n,m,a,b,ans;
    cin>>n>>m;
    ans = n;
    vector<int*> planets(n);
    for(int i=0;i<m;i++)
    {   
        cin>>a>>b;
        if(a!=b)
        {
           if(!planets[a] && !planets[b])  //if both are not merged
           {
               int *x = new int(a);
               planets[a] = planets[b] = x;  //merge them to the same
               ans--;
           }
           else if (planets[a] && planets[b])  //if both are merged to some planet
           {
               if((*planets[a]) != (*planets[b]))  //if both are merged but into different planets
               {
                   *planets[b] = *planets[a];  //merge into same planet by changing one of their planet's name
                   ans--; 
               }
           }
           else
           {
               (planets[a] && !planets[b])?(planets[b] = planets[a]):(planets[a] = planets[b]); /*if one of them is not merged to any planet...make
               the unmerged one point to the merged one's planet*/ 
               ans--;
           }
        }
        cout<<ans<<" ";
    }
}
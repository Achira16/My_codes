#include<bits/stdc++.h>
#include<vector>
using namespace std;
int gcd(int a,int b)
{
    if(a == 0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int b;
    vector<int> a;
    for(int i=0;i<=5;i++)
    {
        cin >> b;
        a.push_back(b);
    }
    int f_gcd = a[0];
    int lcm=a[0];
    for(int i=1;i<=5;i++){
        f_gcd=gcd(a[i],f_gcd);
    }
    for(int i=0;i<=5;i++)
    {
        lcm=(lcm*a[i])/gcd(lcm,a[i]);
    }
        cout << f_gcd << endl << lcm;

}



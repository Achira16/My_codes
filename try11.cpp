#include<bits/stdc++.h>
using namespace std;

class a
{
    
    public:
    static int x;
    a(){cout<<x;}
    void print()
    {
        cout<<"x="<<x;
    }
};
int a::x = 1;
int main()
{
    // string s;
    // s.resize(5);
    // s[4] = 'e';
    // s[3] = 'a';
    // cout<<s;
    a ob;
    cout<<a::x;
    // a::print();
}
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
    // a ob;
    // cout<<a::x;
    // a::print();
    queue<int> q;
    q.push(2);
    queue<int> q1 = q;
    q1.push(3);
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    while(!q1.empty())
    {
        cout<<q1.front();
        q1.pop();
    }
}
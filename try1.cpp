#include<bits/stdc++.h>
using namespace std;

class a
{
    int ans;
    public:
    int calc()
    {
        return ++ans;
    }
    int aux()
    {
        ans = 0;
        return this->calc();
    }
};
int main()
{
    a ob;
    int a = ob.aux();
    cout<<a;
    a = ob.aux();
    cout<<a;
}
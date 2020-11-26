#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"A";
    }
    ~A()
    {
        cout<<"-A";
    }
};
class B
{
    public:
    B()
    {
        cout<<"B";
    }
    ~B()
    {
        cout<<"-B";
    }
};
class C:public B,public A
{
    public:
    C()
    {
        cout<<"C";
    }
    ~C()
    {
        cout<<"-C";
    }
};
int main()
{
    C ob;
}

#include<bits/stdc++.h>
using namespace std;

class base
{
    int a;
    public:
    base(int x)
    {
        a = x+1;
    }
    base(const base& ob)
    {
        a = ob.a;
    }
    virtual void show()
    {
        cout<<"Base show";
    }
    void set(int x)
    {
        a = x;
    }
    int get()
    {
        return a;
    }
};
class der:public base
{
    int b;
    public:
    der(int x):base(x)
    {
        b = x;
    }
    void create()
    {
        cout<<base(*this).get();
        // ob2.set(8);
        cout<<base::get();
        // cout<<ob2.get();
    }
    void show()
    {
        cout<<"der show";
    }
    void set(int x)
    {
        b = x;
    }
    int get()
    {
        return b;
    }
};
int main()
{
    der ob(3);
    base ob1(4);
    ob.create();
    cout<<ob1.get();
}
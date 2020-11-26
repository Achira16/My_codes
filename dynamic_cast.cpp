#include<bits/stdc++.h>
using namespace std;

class Base
{
    public:
    virtual void func() = 0;
};
class Derived1:public Base
{
    public:
    void func()
    {
        cout<<"Derived1"<<endl;
    }
};
class Derived2:public Base
{
    public:
    void func()
    {
        cout<<"Derived2"<<endl;
    }
};
int main()
{
    Derived1 d1;
    Base *b = static_cast<Base*>(&d1);
    Derived1 *d2 = dynamic_cast<Derived1*>(b);
    if(d2 == NULL)
        cout<<"NULL";
    else 
        cout<<"Not null";
    try
    {
        Derived2 &r = dynamic_cast<Derived2&>(d1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
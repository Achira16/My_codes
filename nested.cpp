#include<bits/stdc++.h>
using namespace std;
class A
{
    // int x;
    
    public:
    int x;
    void print(){cout<<"hi";}
    class B
    {
        // int i;
        public:
        B(A ob)
        {
            // ob.x = 2;
            // cout<<ob.x;
            ob.print();
        }
    };
    A()
    {
        B b(*this);
        // i = 1;
    }
};
int main()
{
    A a;
}
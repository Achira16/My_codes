#include<bits/stdc++.h>
using namespace std;

class a;
class b
{
    int x;
    public:
    b(int c):x(c){}
    int get(){return x;}
    friend b foo(b& obj,a &ob);
};
class a
{
    int y;
    public:
    a(int c):y(c){}
    friend b foo(b& obj,a &ob);
};
b foo(b& obj,a &ob)
{
    obj.x = ob.y;
    return obj;
}
int main()
{
    b ob(7);
    a obj(10);
    ob = foo(ob,obj);
    cout<<ob.get();
}
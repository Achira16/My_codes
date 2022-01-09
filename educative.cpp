#include<bits/stdc++.h>
using namespace std;

class A{
    protected:
    int a;
    public:
    A():a(1){}
    void print(){
        cout<<a<<endl;
    }
};
class B:virtual public A{
    int b;
    public:
    B():b(2){}
    void print_b(){
        cout<<b<<endl;
    }
};
class C:virtual public A{
    int c;
    public:
    C():c(3){}
    void print_c(){
        cout<<c<<endl;
    }
};
class D:public B,public C{
    int d;
    public:
    D():d(4){}
};

int main(){
    D obj;
    obj.print();
}

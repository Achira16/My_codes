#include<iostream>
using namespace std;
 
class A
{
  public:
    virtual void show() { cout<<"In A"<<endl; }
};
 
class B: public A
{
  public:
    void show() { cout<<"In B"<<endl; }
};

class C: public B
{
  public:
    void show() { cout<<"In C"<<endl; }
};
 
int main(void)
{
    B b;
    A* a = &b;
    a->show();
 
    C c; 
    a = &c;
    a->show();
}
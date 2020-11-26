#include<bits/stdc++.h>
using namespace std;

class Int
{
    int x;
    public:
    Int(int x=0):x(x){
        cout<<"conversion constructor";
    }
    operator string()
    {
        cout<<"conversion operator";
        return to_string(x);
    }
};
class Base {};
class Derived:private Base{};
class Base2{};
class der1:public Base2{};
class der2:public Base2{};
int main()
{
    /*//Static cast
    float f = 5.34;
    int a;
    a = f;
    a = static_cast<int>(f);// Both are same but this one is easy to search for in a big code and it explicitly mentions it is typecasting in compile time(static)
    cout<<a;*/
    Int obj(30);
    string s1 = obj;
    obj = 20;
    //instead of this use static_cast
    string s2 = static_cast<string>(obj);
    obj = static_cast<Int>(20); 
    /*If we cast char* to int* in C-style, it will compile successfully...however it is very dangerous as we char* points to 1 byte
    memory location while int* points to 4byte memory location so if we assign any value through deferencing...a 4-byte value will
    be copied at that location which may give segmentation fault...hence static_cast doesnt allow this type of casting*/
    char c = 'a';
    int* p = (int*)(&c);
    *p = 5;
    //int* p1 = static_cast<int*>(&c);
    Derived d;
    Base *b1 = (Base*)(&d);
    //Base *b2 = static_cast<Base*>(&d);
    //Use for all upcasts but not for confused downcast as no compile time error occurs
    der1 d1;
    der2 d2;
    Base2 *bp1 = static_cast<Base2*>(&d1);
    Base2 *bp2 = static_cast<Base2*>(&d2);
    der1 *d1p = static_cast<der1*>(bp2);
    der2 *d2p = static_cast<der2*>(bp1);//These two are wrong as we r typecasting bp2 which points to der2 object to der1
}   
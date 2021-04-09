#include<bits/stdc++.h>
using namespace std;

int main()
{
    //const_cast: removing constness but remember the referenced variable/object should be non-const otherwise we will get undefined behaviour
    const int a = 10;
    const int* b = &a;
    int* d = const_cast<int*>(b);
    *d = 15;
    cout<<a<<" "<<*d<<endl;
    //undefined... as compiler replaces the const 'a' evrywhere with 10 however its value has been changed

    int a1 = 10;
    const int* b1 = &a1;
    int* d1 = const_cast<int*>(b1);
    *d1 = 15;
    cout<<a1<<" "<<*d1;//Valid
}
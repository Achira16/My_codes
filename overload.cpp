#include<bits/stdc++.h>
using namespace std;


const void fun(long a) 
{
    cout<<"static";
}
void fun(long a)
{
    cout<<"long: "<<a;
}
// void fun(double b)
// {
//     cout<<"double: "<<b;
// }
int main()
{
    char a = 'a';
    fun(a);
}
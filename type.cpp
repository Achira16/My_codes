#include<bits/stdc++.h>
using namespace std;

char* func()
{
    char name[] = "ach";
    return name;
}
int main()
{
    // auto i = 0;
    // cout<<typeid(i).name();
    // string s = "a0";
    // if(s[0] > s[1])
    //     cout<<1;
    char *s = func();
    printf("%p",&s);
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<string> s1,s2;
    s1.insert({"G","C","Left"});
    s2.insert({"C","G","Left"});
    if(s1 == s2)
        cout<<"Yes";
}
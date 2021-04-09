#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ofstream out("names.txt",ios::app);
    // string s;
    // while(out)
    // {
    //     cin>>s;
    //     if(s == "#")
    //         break;
    //     out<<s<<endl;
    // }
    // out.close();
    // ifstream in("names.txt");
    // // string s;
    // while(getline(in,s))
    // {
    //     // getline(in, s);
    //     cout<<s<<endl;
    // }
    // in.close();
    fstream inout("names.txt",ios::in|ios::out|ios::trunc);
    string s;
    while(inout)
    {
        cin>>s;
        if(s=="#")
            break;
        inout<<s<<endl;
    }
    
    while(getline(inout,s))
    {
        cout<<s<<endl;
    }
    inout.close();
}
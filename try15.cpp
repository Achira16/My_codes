#include<bits/stdc++.h>
using namespace std;
// #include <stdio.h>
// #include <stdlib.h>

struct s{
        int a,b;
        s(int a,int b):a(a),b(b){}
        pair<int,int> operator+(s &x)
        {
            return {a+x.a,b+x.b};
        }
    };
struct node {
    int val;
    node* next;
};
int main()
{
    
    // struct s *ptr = (struct s*)malloc(sizeof(struct s));
    // printf("%s",ptr->a);
    // printf("%d",ptr->x);
    // cout<<sizeof(s);
    // s ob1(4,3),ob2(5,6);
    // pair<int,int> ans = ob1+ob2;
    // cout<<ans.first<<" "<<ans.second;
    // string s1 = "ach";
    // string s2 = s1;
    // s2[2] = 'd';
    // cout<<s1<<" "<<s2;
    // cout<<sizeof(long long *);
    // long a = ~0;
    // unsigned int b = -1;
    // if(a == b)
    // {
    //     cout<<"yes";
    // }
    // unsigned char ch = 0;
    // int count = 0,x=255;
    // while(++ch <= x)
    // {
    //     cout<<ch;
    //     count++;
    // }
    // cout<<count;
    // char *a = "hello";
    // char *b = "world";
    // a = b;
    // printf("%s %s",a,b);
    unordered_map<node*,int> mp;
}
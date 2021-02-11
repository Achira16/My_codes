#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value,y;
    node(int v,int y):value(v),y(y){}
};
struct mycompare
{
    bool operator()(node const& a,node const& b)
    {
        return (a.y < b.y)||(a.y == b.y && a.value > b.value);
    }
};
int main()
{
    priority_queue<node,vector<node>,mycompare> pq;
    pq.push(node(1,0));
    pq.push(node(6,-2));
    pq.push(node(5,-2));
    pq.push(node(3,-3));
    pq.push(node(2,-3));
    pq.push(node(5,-3));
    while(!pq.empty())
    {
        cout<<pq.top().value;
        pq.pop();
    }
}
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1,s2;
    public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop_costly();
    void push_costly(int );
    int pop()
    {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    bool empty()
    {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
    bool empty2()
    {
        if(s1.empty())
            return true;
        return false;
    }
};
int Queue::pop_costly()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int temp = s2.top();
    s2.pop();
    return temp;
}
void Queue::push_costly(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    Queue q;
    int n;
    cin>>n;
    while(n--)
    {
        int i;
        cin>>i;
        q.push_costly(i);
    }
    while(!q.empty2())
    {
        cout<<q.pop();
    }
}
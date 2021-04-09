#include<bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1,q2;
    public:
    void push(int );
    int pop(); 
    bool empty()
    {
        if(q1.empty())
            return true;
        return false;
    }
    bool empty1()
    {
        if(q2.empty())
            return true;
        return false;
    }
    void push_costly(int );
    int pop_const()
    {
        int temp = q2.front();
        q2.pop();
        return temp;
    }
};
void Stack::push(int x)
{
    q1.push(x);
}
int Stack::pop()
{
    while(q1.size()>1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int temp = q1.front();
    q1.pop();
    queue<int> q = q2;
    q2 = q1;
    q1 = q;
    return temp;
}
void Stack::push_costly(int x)
{
    q1.push(x);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    queue<int> q = q2;
    q2 = q1;
    q1 = q;
}
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    cout<<st.pop();
    st.push(3);
    st.push(4);
    cout<<st.pop()<<st.pop()<<st.pop();
}
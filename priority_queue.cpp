#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int s = 1e5;
class p_q_as_arr
{
    int front = 0,rear = -1;
    int p_q[s];
    public:
    p_q_as_arr();
    void enqueue(int );
    int dequeue();
};
int p_q_as_arr::dequeue()
{
    if(front > rear)
        return -1;
    int max = front;
    for(int i = front+1;i <= rear;i++)
    {
        if(p_q[i] > p_q[max])
            max = i;
    }
    if(max == front)
    {
        return p_q[front++];
    }
    int item = p_q[max];
    for(int i=max;i<=rear-1;i++)
    {
        p_q[i] = p_q[i+1];
    }
    rear--;
    return item;
}
void p_q_as_arr::enqueue(int ele)
{
    if(rear >= s)
        return;
    p_q[++rear] = ele;
}
p_q_as_arr::p_q_as_arr()
{
    //considering the values of elements as priority...highest value -> highest priority
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        this->enqueue(ele); //insertion in unordered array ...so O(1)
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<this->dequeue()<<endl; //deletion from unordered array....so O(n)
    }
}
class pq_as_ll
{
    typedef struct node
    {
        int d;
        node * next;
    }node;
    node *front = NULL,*rear = NULL;
    public:
    pq_as_ll();
    void enqueue(int );
    int dequeue();
};
void pq_as_ll::enqueue(int e)
{
    node *temp = new node();
    temp->d = e;
    if(!front && !rear)
        front = rear = temp;
    else
    {
        if(temp->d > front->d)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            node *t = front;
            while(t->next && temp->d <= t->next->d)
            {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }
    }
}
int pq_as_ll::dequeue()
{
    int item = -1;
    if(front)
    {
        node *temp = front;
        item = temp->d;
        front = front->next;
        free(temp);
    }
    return item;
}
pq_as_ll::pq_as_ll()
{
    int n,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        this->enqueue(e);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<this->dequeue()<<" ";
    }
}
int main()
{
    pq_as_ll ob;
    
}
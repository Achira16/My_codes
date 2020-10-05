#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& p_q,int index)
{
    int max = index,i,n = p_q.size();
    do
    {
        i = max;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l<n && p_q[l]>p_q[max])
            max = l;
        if(r<n && p_q[r]>p_q[max])
            max = r;
        swap(p_q[i],p_q[max]);
    } while (i!=max);
}
void print(vector<int>& p_q)
{
    for(int i=0;i<p_q.size();i++)
        cout<<p_q[i]<<" ";
}
void dequeue(vector<int>& p_q,int e)
{
    int ind = -1;
    for(int i=0;i<p_q.size();i++)
    {
        if(e == p_q[i])
            ind = i;
    }
    if(ind == -1)
        return;
    swap(p_q[ind],p_q[p_q.size()-1]);
    p_q.pop_back();
    heapify(p_q,ind);
}
int dequeue(vector<int>& p_q)
{
    int n = p_q.size() - 1;
    swap(p_q[0],p_q[n]);
    int item = p_q[n];
    p_q.pop_back();
    heapify(p_q,0);
    return item;
}
void enqueue(vector<int>& p_q,int d)
{
    p_q.push_back(d);
    if(p_q.size()>1)
    {
        for(int i=p_q.size()/2 - 1;i>=0;i--)
        {
            heapify(p_q,i);
        }
    }
}
int main()
{
    vector<int> p_q;
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        enqueue(p_q,d);
    }
    print(p_q);
    cout<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<dequeue(p_q)<<" ";
    }
    cout<<endl;
    print(p_q);
    cout<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        dequeue(p_q,d);
    }
    print(p_q);
}
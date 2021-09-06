#include<bits/stdc++.h>
using namespace std;
void heapify_up(vector<int>& p_q,int index)
{
    int p;
    while(index>0)
    {
        p = (index-1)/2;
        if(p_q[index]>p_q[p])
            swap(p_q[index],p_q[p]);
        else 
            break;  
        index = p;
    }
}
void heapify_down(vector<int>& p_q,int index)
{
    int max = index;
    do
    {
        index = max;
        int l = 2*index+1;
        int r = 2*index+2;
        if(l<p_q.size() && p_q[l]>p_q[max])
            max = l;
        if(r<p_q.size() && p_q[r]>p_q[max])
            max = r;
        if(max!=index)
            swap(p_q[index],p_q[max]);
    } while (max!=index);
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
    heapify_down(p_q,ind);
}
int dequeue(vector<int>& p_q)
{
    int n = p_q.size() - 1;
    swap(p_q[0],p_q[n]);
    int item = p_q[n];
    p_q.pop_back();
    heapify_down(p_q,0);
    return item;
}
void enqueue(vector<int>& p_q,int d)
{
    p_q.push_back(d);
    heapify_up(p_q,p_q.size()-1);
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
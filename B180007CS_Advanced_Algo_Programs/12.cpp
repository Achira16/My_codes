//Graham's scan
#include<bits/stdc++.h>
using namespace std;

void swap(pair<int,int>& p1, pair<int,int>& p2)
{
    int temp = p1.first;
    p1.first = p2.first;
    p2.first = temp;
    temp = p1.second;
    p1.second = p2.second;
    p2.second = temp;
}
int polar_compare(pair<int,int>& p0,pair<int, int>& p1,pair<int, int>& p2)
{
    pair<int,int> x1 = make_pair(p1.first - p0.first,p1.second - p0.second);
    pair<int,int> x2 = make_pair(p2.first - p0.first,p2.second - p0.second);
    return x1.first*x2.second - x2.first*x1.second;
}
void heapify(vector<pair<int, int>>& Q,pair<int, int>& p0)
{
    int n = Q.size()-1,max;
    for(int i=n/2-1;i>=0;i--)
    {
        max = i;
        do
        {
            i = max;
            int l = 2*i+1,r = 2*i+2;
            if(l<=n && (polar_compare(p0,Q[i],Q[l]) > 0))
                max = l;
            if(r<=n && (polar_compare(p0,Q[max],Q[r]) > 0))
                max = r;
            swap(Q[i],Q[max]);
        }while(max!=i);
    }
}
int heapsort(vector<pair<int,int>>& Q,pair<int,int>& p0)
{
    heapify(Q,p0);
    int n = Q.size()-1,start = n;
    while(n>=0)
    {
        swap(Q[0],Q[n]);
        if(start<Q.size()-1 && (polar_compare(p0,Q[n],Q[start+1]) == 0))
        {
            if(Q[n].first>Q[start+1].first || (Q[n].first == Q[start+1].first && Q[n].second>Q[start+1].second))
            {
                swap(Q[n],Q[start+1]);
            }
        }
        else
        {
            swap(Q[n],Q[start]);
            start--;
        }
        n--;
        int max = 0,i;
        do
        {
            i = max;
            int l = 2*i+1,r = 2*i+2;
            if(l<=n && (polar_compare(p0,Q[i],Q[l]) > 0))
                max = l;
            if(r<=n && (polar_compare(p0,Q[max],Q[r]) > 0))
                max = r;
            swap(Q[i],Q[max]);
        }while(max!=i);  
    }
    return start+1;
}
pair<int,int> next_to_top(stack<pair<int,int>>& st)
{
    pair<int,int> top = st.top();
    st.pop();
    pair<int,int> n_top = st.top();
    st.push(top);
    return n_top;
}
void grahamScan(vector<pair<int,int>>& Q)
{
    int n = Q.size();
    pair<int,int> p0;
    int min_y = INT32_MAX,min_x = INT32_MAX;
    //find point p0 with minimum y-coordinate(in case of conflict choose the one with lower x coordinate)
    for(int i=0;i<n;i++)
    {
        if(Q[i].second < min_y)
        {
            min_y = Q[i].second;
            min_x = Q[i].first;
        }
        else if(Q[i].second == min_y && Q[i].first < min_x)
        {
            min_x = Q[i].first;
            min_y = Q[i].second;
        }
    }
    p0 = make_pair(min_x,min_y);
    bool flag = false;
    for(int i=0; i<n-1; i++)
    {
        if(Q[i] == p0)
        {
            Q[i] = Q[i+1];
            flag = true;
        }
        else if(flag)
        {
            Q[i] = Q[i+1];
        }
    }
    Q.resize(n-1);
    //sort the rest of the points according to the polar angle with p0
    int start = heapsort(Q,p0);
    stack<pair<int,int>> st;
    st.push(p0);
    st.push(Q[start]);
    st.push(Q[start+1]);
    for(int i=start+2;i<Q.size();i++)
    {
        pair<int,int> n_to_top = next_to_top(st);
        while(polar_compare(n_to_top,st.top(),Q[i]) < 0)
        {
            st.pop();
            n_to_top = next_to_top(st);
        }
        st.push(Q[i]);
    }
    cout<<"Convex hull: ";
    while(!st.empty())
    {
        cout<<"("<<st.top().first<<","<<st.top().second<<") ";
        st.pop();
    }
}
int main()
{
    int n;
    cout<<"Enter number of points: ";
    cin>>n;
    if(n<3)
    {
        cout<<"No polygon possible";
    }
    else
    {
        vector<pair<int,int>> Q(n);
        int x,y;
        cout<<"Enter the points: ";
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            Q[i] = make_pair(x,y);
        }
        grahamScan(Q);
    }
}
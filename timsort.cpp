#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int compute_minrun(int n)
{
    int minrun = n;
    int rem_length = floor(log2(n))-5;
    if(rem_length > 0)
    {
        minrun = minrun>>rem_length;
        int mask = 1<<rem_length - 1;
        if((n&mask) > 0)
            minrun+=1;
    }
    return minrun;
}
int bsearch(vector<int>& arr,int l,int h,int e)
{
    while(l<h)
    {
        int mid = (l+h)/2;
        if(e < arr[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    if(arr[l] > e)
        return l;
    return l+1;
}
int bsearch_desc(vector<int>& arr,int l,int h,int e)
{
    while(l<h)
    {
        int mid = (l+h)/2;
        if(e >= arr[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    if(arr[l] <= e)
        return l;
    return l+1;
}
void force_merge(vector<int>& arr,vector<pi>& mystack)
{
    while(mystack.size()>=2)
    {
        int n = mystack.size()-1;
        if(mystack.size() == 2)
        {
            if(mystack[n].first > mystack[n-1].first)
            {
                pi run = merge(mystack[n],mystack[n-1],arr);
                mystack[n-1] = run;
                mystack.pop_back();
            }
        }
        if(mystack[n-2].first > mystack[n-1].first+mystack[n].first)
        {
            if(mystack[n].first > mystack[n-1].first)
            {
                pi run = merge(mystack[n],mystack[n-1],arr);
                mystack[n-1] = run;
                mystack.pop_back();
            }
            else
                break;
        }
        else
        {
            if(mystack[n]<=mystack[n-2])
            {
                pi run = merge(mystack[n],mystack[n-1],arr);
                mystack[n-1] = run;
                mystack.pop_back();
            }
            else
            {
                pi run = merge(mystack[n-1],mystack[n-2],arr);
                mystack[n-2] = run;
                mystack[n-1] = mystack[n];
                mystack.pop_back();
            }
        }
    }
}
void make_runs_with_insertion_sort(vector<pi>& mystack,vector<int>& arr,int minrun)
{
    int start = 0,bool asc = true;
    for(int i=1;i<arr.size();i++)
    {
        if(i == start+1)
        {
            if(arr[i] < arr[i-1])
                asc = false;
            else
                asc = true;
        }
        else
        {
            if(asc && arr[i] < arr[i-1])
            {
                if(i-start >= minrun)
                {
                    mystack.push_back(make_pair(i-start,start));
                    force_merge(arr,mystack)
                    start = i;
                }
                else
                {
                    int pos = bsearch(arr,start,i-1,e);
                    int key = arr[i];
                    for(int j=i;j>pos;j--)
                        arr[j]=arr[j-1];
                    arr[pos] = key;                                                           
                }
            }
            else if(!asc && arr[i]>=arr[i-1])
            {
                if(i-start >= minrun)
                {
                    mystack.push_back(make_pair(i-start,start));
                    force_merge(arr,mystack);
                    start = i;
                }
                else
                {
                    int pos = bsearch_desc(arr,start,i-1,e);
                    int key = arr[i];
                    for(int j=i;j>pos;j--)
                        arr[j]=arr[j-1];
                    arr[pos] = key;  
                }
            }
        }
    }
    mergeall(mystack,arr);
}
void timsort(vector<int>& arr)
{
    int minrun = compute_minrun(arr.size());
    vector<pi> mystack;
}
int main()
{

}
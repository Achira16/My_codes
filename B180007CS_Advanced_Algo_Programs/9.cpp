//1.5 and 2-approx algorithm for Incependent Task Scheduling Problem
#include<bits/stdc++.h>
using namespace std;

void approx_ids2(vector<int>& et,int m)
{
    int n = et.size();
    vector<int> ct(m,0);
    for(auto i=et.begin();i!=et.end();i++)
    {
        int min_index = 0;
        for(int j=1;j<m;j++)
        {
            if(ct[j]<ct[min_index])
                min_index = j;
        }
        ct[min_index] += *i;
    }
    cout<<"Makespan for 2approx algo = "<<*max_element(ct.begin(),ct.end())<<endl;
}
void approx_ids1(vector<int>& et,int m)
{
    int n = et.size();
    vector<int> ct(m,0);
    //sort the execution time array in descending order
    sort(et.begin(),et.end());
    //assign the task with largest execution time to machine with smallest completion time
    for(auto i=et.rbegin();i!=et.rend();i++)
    {
        int min_index = 0;
        for(int j=1;j<m;j++)
        {
            if(ct[j]<ct[min_index])
                min_index = j;
        }
        ct[min_index] += *i;
    }
    cout<<"Makespan for 1.5approx algo = "<<*max_element(ct.begin(),ct.end())<<endl;
}
int main()
{
    int n,m,e;
    cout<<"Enter no of tasks: ";
    cin >> n;
    cout<<"Enter no. of machines: ";
    cin>>m;
    vector<int> et(n);
    for(int i=0;i<n;i++)
        cin>>et[i];
    approx_ids1(et,m);
    approx_ids2(et,m);
}
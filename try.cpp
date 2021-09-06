#include<bits/stdc++.h>
using namespace std;

struct node
{
    unordered_set<int> s;
    node(int n)
    {
        for(int i=0; i<n; i++)
            s.insert(i);
    }
};
void unlock(node *temp,int i)
{
    temp->s.erase(i);
}
int main()
{
    // int **a = (int**)malloc(2*sizeof(int*));
    // for(int i=0;i<2;i++)
    // {
    //     a[i] = (int*)malloc(2*sizeof(int));
    // }
    // cout<<a<<" "<<" "<<*a<<" "<<a[0]<<" "<<a[1]<<" "<<&a[0][0]<<" "<<&a[0][1]<<" "<<&a[1][0]<<" "<<&a[1][1]<<endl;
    // cout<<*(*(a+1)+1);
    // cout<<sizeof(a[1]);
    // free(a);
    node *root = new node(4);
    unordered_set<int> d = root->s;
    for(auto it=d.begin();it!=d.end();it++)
    {
        // cout<<*it<<" ";
        unlock(root,*it);
    }
    for(auto it=root->s.begin();it!=root->s.end();it++)
    {
        cout<<*it<<" ";
        // unlock(root,*it);
    }
}
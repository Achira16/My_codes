#include<bits/stdc++.h>
using namespace std;

class fenwickTree
{
    vector<int> tree;
    public:
    fenwickTree(vector<int>& arr)
    {
        tree.push_back(0);
        for(auto i:arr)
        {
            tree.push_back(i);
        }
        for(int i=1;i<tree.size();i++)
        {
            int parent = i+lsb(i);
            if(parent<tree.size())
                tree[parent]+=tree[i];
        }
    }
    int lsb(int i)
    {
        return i&(-i);
    }
    int prefixSum(int );
    int rangeSum(int ,int );
    void add(int ,int );
    void set(int ,int );
};
int fenwickTree::prefixSum(int i)
{
    int sum = 0;
    while(i!=0)
    {
        sum+=tree[i];
        i &= ~lsb(i);
    }
    return sum;
}
int fenwickTree::rangeSum(int i,int j)
{
    return prefixSum(j)-prefixSum(i-1);
}
void fenwickTree::add(int i,int k)
{
    while(i<tree.size())
    {
        tree[i]+=k;
        i += lsb(i);
    }
}
void fenwickTree::set(int i,int v)
{
    int value = rangeSum(i,i);
    add(i,v-value);
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    fenwickTree tree(arr);
    cout<<tree.rangeSum(1,5);
}
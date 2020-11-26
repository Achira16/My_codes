#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef struct node
{
    int d;
    node *l,*r;
}node;
node* Newnode(int d)
{
    node *temp = new node();
    temp->d = d;
    temp->l = temp->r = NULL;
    return temp;
}
int ans = 0;
void goodnodes(node* root,int max)
{
    if(!root)
        return;
    if(root->d>=max)
    {
        ans++;
        max = root->d;
    }
    goodnodes(root->l,max);
    goodnodes(root->r,max);
}
int main()
{
    vector<int> bintree;
    int level;
    cin>>level;
    int a;
    for(int i=0;i<exp2(level)-1;i++)
    {
        cin>>a;
        bintree.push_back(a);
    }
    queue<node*> q;
    node *root = Newnode(bintree[0]);
    if(bintree[1]>=0)
        root->l = Newnode(bintree[1]);
    else
        root->l = NULL;
    if(bintree[2]>=0)
        root->r = Newnode(bintree[2]);
    else
        root->r = NULL;
    q.push(root->l);
    q.push(root->r);
    for(int i=1;i<=bintree.size()/2-1;i++)
    {
        node* temp = q.front();
        q.pop();
        if(temp){
        if(bintree[2*i+1]>=0)
            temp->l = Newnode(bintree[2*i+1]);
        else
            temp->l = NULL;
        if(bintree[2*i+2]>=0)
            temp->r = Newnode(bintree[2*i+2]);
        else
            temp->r = NULL;
        }
        q.push(temp->l);
        q.push(temp->r);
    }
    goodnodes(root,root->d);
    cout<<ans;
}
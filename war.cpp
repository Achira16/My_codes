#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

typedef struct node
{
    int id;
    bool vis;
    node *l,*r,*parent;
    node(int x):id(x),vis(false),l(NULL),r(NULL),parent(NULL){}
    node(int x,node *par):id(x),vis(false),l(NULL),r(NULL),parent(par){}
}node;

void bfs(node *root)
{
    if(!root)
        return;
    queue<node*> q;
    q.push(root);
    root->vis = true;
    cout<<root->id<<endl;
    vector<int> s;
    int n;
    while(!q.empty())
    {
        n = q.size();
        s.clear();
        while(n)
        {
            node *temp = q.front();
            q.pop();
            if(temp->l && !temp->l->vis)
            {
                temp->l->vis = true;
                q.push(temp->l);
                s.push_back(temp->l->id);
            }
            if(temp->r && !temp->r->vis)
            {
                temp->r->vis = true;
                q.push(temp->r);
                s.push_back(temp->r->id);
            }
            if(temp->parent && !temp->parent->vis)
            {
                temp->parent->vis = true;
                q.push(temp->parent);
                s.push_back(temp->parent->id);
            }
            n--;
        }
        priority_queue<int,vector<int>,greater<int>> pq(s.begin(), s.end());
        n = pq.size();
        while(!pq.empty())
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        if(n)
            cout<<endl;
    }
}
int main()
{
    IOS;
   int d;
        cin>>d;
        node *root;
        queue<node*> q;
        if(d)
        {
          root = new node(d);
          q.push(root);
        }
        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();
            cin>>d;
            if(d!=-1){
                temp->l = new node(d,temp);
                q.push(temp->l);
            }
            cin>>d;
            if(d!=-1){
                temp->r = new node(d,temp);
                q.push(temp->r);
            }
        }
        int tar;
        cin>>tar;
        if(root->id == tar)
            bfs(root);
        else
        {
            queue<node*> f;
            f.push(root);
            while(!f.empty())
            {
                node *t = f.front();
                f.pop();
                if(t->l)
                {
                    if(t->l->id == tar)
                    {
                        bfs(t->l);
                        break;
                    }
                    else
                        f.push(t->l);
                }
                if(t->r)
                {
                    if(t->r->id == tar)
                    {
                        bfs(t->r);
                        break;
                    }
                    else
                        f.push(t->r);
                }
            }
        }
}
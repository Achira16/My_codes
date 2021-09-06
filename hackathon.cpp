#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pi pair<node*,int>

struct node
{
    string val;
    node *parent;
    int id;
    atomic_int count;
    atomic_int dirty,unlock_dirty;
    atomic_bool locked;
    node(string v)
    {
        val = v;
        parent = NULL;
        id = -1;
        dirty.store(0);
        unlock_dirty.store(0);
        locked.store(0);
    }
    node(string v,node *par)
    {
        val = v;
        parent = par;
        id = -1;
        dirty.store(0);
        unlock_dirty.store(0);
        locked.store(0);
    }
};

void lock1(node *temp,int uid,promise<bool>* res)
{
    cout<<temp->val<<" getting locked\n";
    if(++temp->dirty > 1)
    {
        res->set_value(0);
        return;
    }
    if(temp->locked)
    {
        temp->dirty.store(0);
        res->set_value(0);
        return;
    }
    temp->locked.store(true);
    if(temp->count.load() > 0)
    {
        temp->locked.store(false);        
        temp->dirty.store(0);
        res->set_value(0);
        return;
    }
    node *t = temp->parent;
    while(t)
    {
        t->count++;
        if(t->locked)
        {
            t->count--;
            node *par = temp->parent;
            while(par != t)
            {
                par->count--;
                par = par->parent;
            }
            temp->locked.store(0);
            res->set_value(0);
            return;
        }
        t = t->parent;
    }
    temp->id = uid;
    cout<<temp->val<<" locked\n";
    temp->dirty.store(0);
    res->set_value(1);
    return;
}
void unlock(node *temp,int uid,promise<bool>* res)
{
    cout<<temp->val<<" unlocking\n";
    int cur_id = temp->id;
    if(cur_id == -1 || cur_id !=uid)
    {
        res->set_value(0);
        return;
    }
    if(++temp->unlock_dirty > 1)
    {
        res->set_value(0);
        return;
    }
    node *par = temp->parent;
    while(par)
    {
       par->count--;
       par = par->parent;
    }
    temp->id = -1;
    temp->locked.store(0);
    temp->unlock_dirty.store(0);
    cout<<temp->val<<" unlocked\n";
    res->set_value(1);
    return;
}

int main()
{
    IOS;
    int N,m,Q;
    cin>>N>>m>>Q;
    unordered_map<string,node*> tree;
    string s;
    cin>>s;
    int count = 1;
    node *root = new node(s);
    queue<node*> q;
    q.push(root);
    tree[s] = root;
    while(!q.empty() && count<N)
    {
        node *par = q.front();
        q.pop();
        int n = N-count;
        if(n >= m)
        {
            for(int i=0;i<m;i++)
            {
                cin>>s;
                count++;
                tree[s] = new node(s,par);
                q.push(tree[s]);
                
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cin>>s;
                count++;
                tree[s] = new node(s,par);
                q.push(tree[s]);
            }
        }
    }
    vector<pi> arguments(Q);
    vector<int> types(Q);
    string val;
    int op,uid;
    for(int i=0;i<Q;i++)
    {
        cin>>op>>val>>uid;
        arguments[i] = {tree[val],uid};
        types[i] = op;
    }
    vector<promise<bool>> res(Q);
    vector<future<bool>> futureobj(Q);
    for(int i=0;i<Q;i++)
    {
        futureobj[i] = res[i].get_future();
    }
    vector<thread> th(Q);
   
    for(int i=0;i<Q;i++)
    {
        if(types[i] == 1)
            th[i] = thread(lock1,arguments[i].first,arguments[i].second,&res[i]);
        else 
            th[i] = thread(unlock,arguments[i].first,arguments[i].second,&res[i]);
    }

    for(int i=0;i<Q;i++)
    {
        cout<<futureobj[i].get()<<" ";
        th[i].join();
    }
    
}
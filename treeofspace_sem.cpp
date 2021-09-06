#include<bits/stdc++.h>
#include<semaphore.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pi pair<node*,int>

class Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startpoint; 
    public:
    Timer()
    {
        m_startpoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        Stop();
    }
    void Stop()
    {
        auto endpoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startpoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endpoint).time_since_epoch().count();
        auto duration = end-start;
        double ms = duration*0.001;
        cout<<duration<<"us ("<<ms<<"ms)\n";  
    }
};
struct node 
{
    sem_t main_lock,desc,set_update,unlocking;
    int no_of_desc;
    char val;
    bool islocked;
    int id;
    unordered_set<node*> des_locked;
    node *parent;
    node(char v)
    {
        val = v; 
        islocked = false;
        sem_init(&main_lock,0,1);
        sem_init(&desc,0,1);
        sem_init(&set_update,0,1);
        sem_init(&unlocking,0,1);
        no_of_desc = 0;
        parent = NULL;
        id = -1;
    }
    node(char v,node *par)
    {
        val = v;
        islocked = false;
        parent = par;
        sem_init(&main_lock,0,1);
        sem_init(&desc,0,1);
        sem_init(&set_update,0,1);
        sem_init(&unlocking,0,1);
        no_of_desc = 0;
        id = -1;
    }
    ~node()
    {
        sem_destroy(&main_lock);
        sem_destroy(&desc);
        sem_destroy(&set_update);
        sem_destroy(&unlocking);
    }
};
void lock1(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    printf("(%c) Trying to lock\n",temp->val);
    sem_wait(&(temp->main_lock));
    sem_wait(&(temp->unlocking));
    if( temp->des_locked.size() > 0 || temp->islocked )
    {
        res->set_value(0);
        printf("(%c) ends(cant lock)\n",temp->val);
        sem_post(&(temp->unlocking));
        sem_post(&(temp->main_lock));
        return;
    }
    node *par = temp->parent;
    while(par)
    {
        sem_wait(&(par->desc));
        par->no_of_desc++;
        if(par->no_of_desc == 1)
            sem_wait(&(par->main_lock));
        sem_post(&(par->desc));
        par = par->parent;
    }
    node *t = temp->parent;
    while(t)
    {
        if(t->islocked)
        {
            res->set_value(0);
            par = temp->parent;
            while(par)
            {
                sem_wait(&(par->desc));
                par->no_of_desc--;
                if(par->no_of_desc == 0)
                    sem_post(&(par->main_lock));
                sem_post(&(par->desc));
                par = par->parent;
            }
            printf("(%c) ends(cant lock)\n",temp->val);
            sem_post(&(temp->unlocking));
            sem_post(&(temp->main_lock)); 
            return;
        }
        t = t->parent;
    }
    //Critical section starts
    temp->islocked = 1;
    temp->id = uid;
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->set_update));
        t->des_locked.insert(temp);
        sem_post(&(t->set_update));
        t = t->parent;
    }
    //Critical section ends
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->no_of_desc--;
        if(t->no_of_desc == 0)
            sem_post(&(t->main_lock));
        sem_post(&(t->desc));
        t = t->parent;
    }
    res->set_value(1);
    printf("(%c) ends(locked)\n",temp->val);
    sem_post(&(temp->unlocking));
    sem_post(&(temp->main_lock));
    return;
}
void unlock(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    printf("Trying to unlock (%c) \n",temp->val);
    sem_wait(&(temp->unlocking));
    if(!temp->islocked || temp->id != uid)
    {
        res->set_value(0);
        printf("(%c) ends(cant unlock) because its not locked or uid doesnt match\n",temp->val);
        sem_post(&(temp->unlocking));
        return;
    }
    node *t = temp->parent;
    while(t)
    {
        sem_wait(&(t->set_update));
        t->des_locked.erase(temp);
        sem_post(&(t->set_update));
        t = t->parent;
    }
    temp->islocked = 0;
    temp->id = -1;
    res->set_value(1);
    printf("(%c) ends(unlocked)\n",temp->val);
    sem_post(&(temp->unlocking));
    return;
}
void upgrade(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    printf("(%c) Trying to upgrade\n",temp->val);
    sem_wait(&(temp->main_lock));
    if(temp->islocked || temp->des_locked.size() == 0)
    {
        res->set_value(0);
        printf("(%c) Cant upgrade (either locked or no descendant)\n",temp->val);
        sem_post(&(temp->main_lock));
        return;
    }
    unordered_set<node*> children_locked = temp->des_locked;
    bool ans = 0;
    for(auto it = children_locked.begin(); it != children_locked.end();it++)
    {
        int cur_id = (*it)->id;
        if(cur_id != -1)
        {
            if(cur_id != uid)
            {   
                res->set_value(0);
                printf("(%c) Cant upgrade (uid doesnt match)\n",temp->val);
                sem_post(&(temp->main_lock));
                return;
            }
            else
                ans = 1;
        }
    }
    if(!ans)
    {
        res->set_value(0);
        sem_post(&(temp->main_lock));
        return;
    }
    node *par = temp->parent;
    while(par)
    {
        sem_wait(&(par->desc));
        par->no_of_desc++;
        if(par->no_of_desc == 1)
            sem_wait(&(par->main_lock));
        sem_post(&(par->desc));
        par = par->parent;
    }
    ans = 0;
    for(auto it = children_locked.begin(); it != children_locked.end();it++)
    {
        promise<bool> obj;
        future<bool> fobj = obj.get_future();
        unlock({*it,uid},&obj);
        ans |= fobj.get();
    }
    if(!ans)
    {
        par = temp->parent;
        while(par)
        {
            sem_wait(&(par->desc));
            par->no_of_desc--;
            if(par->no_of_desc == 0)
                sem_post(&(par->main_lock));
            sem_post(&(par->desc));
            par = par->parent;
        }       
        res->set_value(0);
        printf("(%c) Cant upgrade (already unlocked or upgraded)\n",temp->val);
        sem_post(&(temp->main_lock));
        return;
    }
    temp->islocked = 1;
    temp->id = uid;
    node *t = temp->parent;
    while(t)
    {
        sem_wait(&(t->set_update));
        t->des_locked.insert(temp);
        sem_post(&(t->set_update));
        t = t->parent;
    }
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->no_of_desc--;
        if(t->no_of_desc == 0)
            sem_post(&(t->main_lock));
        sem_post(&(t->desc));
        t = t->parent;
    }
    res->set_value(1);
    printf("(%c) Upgraded\n",temp->val);
    sem_post(&(temp->main_lock));
    return;
}
int main()
{
    int N,m,Q;
    cin>>N>>m>>Q;
    unordered_map<char,node*> tree;
    char s;
    cin>>s;
    tree[s] = new node(s);
    queue<node*> q;
    q.push(tree[s]);
    int count = 1;
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
                tree[s] = new node(s,par);
                q.push(tree[s]);
                count++;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cin>>s;
                tree[s] = new node(s,par);
                q.push(tree[s]);
                count++;
            }
        }
    }
    vector<pi> arguments(Q);
    vector<int> types(Q);
    char val;
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
    thread th[Q];
    {
        Timer timer;
        for(int i=0;i<Q;i++)
        {
            if(types[i] == 1)
                th[i] = thread(lock1,arguments[i],&res[i]);
            else if(types[i] == 2)
                th[i] = thread(unlock,arguments[i],&res[i]);
            else
                th[i] = thread(upgrade,arguments[i],&res[i]);
        }
    
        for(int i=0;i<Q;i++)
        {
            cout<<futureobj[i].get()<<" ";
            th[i].join();
        }
    }
}

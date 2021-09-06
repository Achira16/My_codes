#include<bits/stdc++.h>
#include<unistd.h>
#include<semaphore.h>
#include<atomic>
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
    sem_t desc;
    int no_of_desc,count;
    char val;
    atomic_bool lockable,upgrading;
    //bool islocked;
    atomic_int id;
    unordered_set<node*> des_locked;
    node *parent;
    node(char v)
    {
        val = v;
        //islocked = 0;
        lockable.store(true);
        upgrading.store(false);
        sem_init(&desc,0,1);
        no_of_desc = 0;
        count = 0;
        parent = NULL;
        id.store(-1);
    }
    node(char v,node *par)
    {
        val = v;
        //islocked = 0;
        lockable.store(true);
        upgrading.store(false);
        parent = par;
        sem_init(&desc,0,1);
        no_of_desc = 0;
        count = 0;
        id.store(-1);
    }
    ~node()
    {
        sem_destroy(&desc);
    }
};
void lock1(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    printf("Trying to lock (%c)\n",temp->val);
    bool expected = true;
    if(!atomic_compare_exchange_strong(&(temp->lockable),&expected,false))
    {
        res->set_value(0);
        printf("(%c) ends(cant lock)\n",temp->val);
        return;
    }
    node *par = temp->parent;
    while(par)
    {
        sem_wait(&(par->desc));
        par->count++;
        if(par->count == 1)
        {
            bool exp = false;
            if(!atomic_compare_exchange_strong(&(par->upgrading),&exp,true))
            {
                par->count--;
                sem_post(&(par->desc));
                res->set_value(0);
                node *par_temp = temp->parent;
                while(par_temp != par)
                {
                    sem_wait(&(par_temp->desc));
                    par_temp->no_of_desc--;
                    par_temp->count--;
                    if(par_temp->count == 0)
                    {
                        par_temp->upgrading.store(false);
                        par_temp->upgrading.notify_one();
                    }
                    if(par_temp->no_of_desc == 0)
                        par_temp->lockable.store(true);
                    sem_post(&(par_temp->desc));
                    par_temp = par_temp->parent;
                }
                temp->lockable.store(true);
                printf("(%c) ends (cant lock)\n",temp->val);
                return;
            }
        }
        par->no_of_desc++;
        if(par->no_of_desc == 1)
        {
            if(!atomic_compare_exchange_strong(&(par->lockable),&expected,false))
            {
                par->count--;
                if(par->count == 0)
                {
                    par->upgrading.store(false);
                    par->upgrading.notify_one();
                }
                par->no_of_desc--;
                sem_post(&(par->desc));
                res->set_value(0);
                node *par_temp = temp->parent;
                while(par_temp != par)
                {
                    sem_wait(&(par_temp->desc));
                    par_temp->no_of_desc--;
                    par_temp->count--;
                    if(par_temp->count == 0)
                    {
                        par_temp->upgrading.store(false);
                        par_temp->upgrading.notify_one();
                    }
                    if(par_temp->no_of_desc == 0)
                        par_temp->lockable.store(true);
                    sem_post(&(par_temp->desc));
                    par_temp = par_temp->parent;
                }
                temp->lockable.store(true);
                printf("(%c) ends (cant lock)\n",temp->val);
                return;
            }
        }
        sem_post(&(par->desc));
        par = par->parent;
    }
    node *t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->des_locked.insert(temp);
        sem_post(&(t->desc));
        t = t->parent;
    }
    temp->id.store(uid);
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->count--;
        if(t->count == 0)
        {
            t->upgrading.store(false);
            t->upgrading.notify_one();
        }
        sem_post(&(t->desc));
        t = t->parent;
    }
    res->set_value(1);
    printf("(%c) ends(locked)\n",temp->val);
    return;
}
void unlock(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    printf("Trying to unlock (%c) \n",temp->val);
    int cur_id = temp->id.load();
    if( cur_id == -1 || cur_id != uid)
    {
        res->set_value(0);
        printf("(%c) ends(cant unlock) because its uid doesnt match\n",temp->val);
        return;
    }
    if(!atomic_compare_exchange_strong(&(temp->id),&cur_id,-1))
    {
        res->set_value(0);
        printf("(%c) ends(cant unlock)\n",temp->val);
        return;
    }
    node *t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->des_locked.erase(temp);
        sem_post(&(t->desc));
        t = t->parent;
    }
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->no_of_desc--;
        if(t->no_of_desc == 0)
            t->lockable.store(true);
        sem_post(&(t->desc));
        t = t->parent;
    }
    temp->lockable.store(true);
    res->set_value(1);
    printf("(%c) ends(unlocked)\n",temp->val);
    return;
}
void upgrade(pi arg,promise<bool>* res)
{
    node *temp = arg.first;
    int uid = arg.second;
    bool expected = false;
    printf("(%c) Trying to upgrade\n",temp->val);
    while(!atomic_compare_exchange_strong(&(temp->upgrading),&expected,true))
        temp->upgrading.wait(true);
    if(temp->des_locked.size() == 0)
    {
        res->set_value(0);
        temp->upgrading.store(false);
        temp->upgrading.notify_one();
        printf("(%c) Cant upgrade (no locked descendant)\n",temp->val);
        return;
    }
    unordered_set<node*> children_locked = temp->des_locked;
    bool ans = 0;
    for(auto it = children_locked.begin(); it != children_locked.end();it++)
    {
        int cur_id = (*it)->id.load();
        if(cur_id!=-1)
        {
            if(cur_id != uid)
            {
                res->set_value(0);
                temp->upgrading.store(false);
                temp->upgrading.notify_one();
                printf("(%c) Cant upgrade (uid doesnt match)\n",temp->val);
                return;
            }
            else
                ans = 1;
        }
    }
    if(!ans)
    {
        res->set_value(0);
        temp->upgrading.store(false);
        temp->upgrading.notify_one();
        printf("(%c) Cant upgrade (no locked descendant)\n",temp->val);
        return;
    }
    sem_wait(&(temp->desc));
    temp->no_of_desc++;
    if(temp->no_of_desc == 1)
    {
        res->set_value(0);
        temp->no_of_desc--;
        sem_post(&(temp->desc));
        temp->upgrading.store(false);
        temp->upgrading.notify_one();
        printf("(%c) Cant upgrade (no locked descendant)\n",temp->val);
        return;
    }
    sem_post(&(temp->desc));
    node *par = temp->parent;
    while(par)
    {
        sem_wait(&(par->desc));
        par->no_of_desc++;
        par->count++;
        if(par->count == 1)
        {
            bool exp = false;
            while(!atomic_compare_exchange_strong(&(par->upgrading),&exp,true))
                  par->upgrading.wait(true);
        }
        if(par->no_of_desc == 1)
        {
            par->count--;
            par->no_of_desc--;
            if(par->count == 0)
            {
                par->upgrading.store(false);
                par->upgrading.notify_one();
            }
            sem_post(&(par->desc));
            node *par_temp = temp->parent;
            while(par_temp!=par)
            {
                sem_wait(&(par_temp->desc));
                par_temp->no_of_desc--;
                par_temp->count--;
                if(par_temp->count == 0)
                {
                    par_temp->upgrading.store(false);
                    par_temp->upgrading.notify_one();
                }
                if(par_temp->no_of_desc == 0)
                    par_temp->lockable.store(true);
                sem_post(&(par_temp->desc));
            }
            sem_wait(&(temp->desc));
            temp->no_of_desc--;
            if(temp->no_of_desc == 0)
                temp->lockable.store(true);
            sem_post(&(temp->desc));
            temp->upgrading.store(false);
            temp->upgrading.notify_one();
            res->set_value(0);
            printf("(%c) cant upgrade\n",temp->val);
            return;
        }
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
            par->count--;
            if(par->count == 0)
            {
                par->upgrading.store(false);
                par->upgrading.notify_one();
            }
            if(par->no_of_desc == 0)
                par->lockable.store(true);
            sem_post(&(par->desc));
            par = par->parent;
        }     
        sem_wait(&(temp->desc));
        temp->no_of_desc--;
        if(temp->no_of_desc == 0)
            temp->lockable.store(true);
        sem_post(&(temp->desc));
        temp->upgrading.store(false);
        temp->upgrading.notify_one();
        res->set_value(0);
        printf("(%c) Cant upgrade (already unlocked or upgraded)\n",temp->val);
        return;
    }
    node *t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->des_locked.insert(temp);
        sem_post(&(t->desc));
        t = t->parent;
    }
    temp->id.store(uid);
    t = temp->parent;
    while(t)
    {
        sem_wait(&(t->desc));
        t->count--;
        if(t->count == 0)
        {
            t->upgrading.store(false);
            t->upgrading.notify_one();
        }
        sem_post(&(t->desc));
        t = t->parent;
    }
    sem_wait(&(temp->desc));
    temp->no_of_desc--;
    sem_post(&(temp->desc));
    temp->upgrading.store(false);
    temp->upgrading.notify_one();
    res->set_value(1);
    printf("(%c) Upgraded\n",temp->val);
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
    vector<thread> th(Q);
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

/*
    Constraints in dependency task scheduling:
    1. We should follow the topological ordering
    2. Suppose a-->b (b can start executing only after a's completion). We cannot assign 'b' to a machine whose completion
    time is lower than completion time of the machine to which 'a' was assigned before. Therefore, we can directly assign 'b'
    to a machine whose completion time is equal to its arrival time.

    Algo: 
    s = set of jobs
    while s is not empty do
       A = set of jobs with indegree 0
       for each job in A do
            decrement the indegree of jobs connected to job by 1
       sort A in decreasing order on the basis of execution time
       for each job in A do
            flag = false
            for i=1 to m do
                if machine i satisfies constraint 2
                    flag = true
                    CT[i] = CT[i] + execution time of job
                    break
            if(!flag)
                find machine with min CT and assign job to it and update its CT accordingly
    makespan = max(CT)
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int et,indeg,at;
    node(int x):et(x),indeg(0),at(0){}
}node;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
void scheduling(queue<int>& q,vector<vector<int>>& dag,vector<node*>& process,vector<int>& ct)
{
    int q_size, m = ct.size();
    //main algorithm starts here
    auto start = std::chrono::steady_clock::now();
   while(!q.empty())
    {
        q_size = q.size();
        vector<pair<int,int>> v; //this while loop will take overall O(V+E) time...O(V) for enqueing and dequeing each vertex and O(E) overall for traversing the adjacency list once
        while(q_size)    //for getting all the independent jobs together                            
        {
            v.push_back(make_pair(q.front(),process[q.front()]->et));
            for(auto it:dag[q.front()])    //decrement the dependent jobs' indegree
            {
                process[it]->indeg--;
                if(!process[it]->indeg)
                    q.push(it);
            }
            q.pop();
            q_size--;
        }
        //sorting will take overall O(V^2logV) time
        sort(v.begin(),v.end(),sortbysec);  //sort the jobs according to execution time
        //the for loop below will take overall O(Vm + E) time
        for(auto it=v.rbegin();it!=v.rend();it++)  //access the vector from behind(decreasing order)
        {  
            int min = 0;
            bool found = false;
            for(int i=0;i<m;i++)
            {
                if(process[it->first]->at == ct[i])  //as soon as we find CT of a machine equal to its arrival time..we know that will be the min
                {
                    found = true;
                    ct[i] += process[it->first]->et;
                    // update the arrival time of dependent jobs
                    for(auto child:dag[it->first])
                    {
                        process[child]->at = max(process[child]->at, ct[i]);
                    } 
                    break;
                }
                if(ct[i] < ct[min])  //if we dont find such CT, simply find the min one and we'll update it accordingly
                    min = i;
            }
            if(!found)
            {
                if(ct[min] < process[it->first]->at)   //if CT of machine is less than the job's arrival time then it should wait until its arrival
                    ct[min] = process[it->first]->at + process[it->first]->et; 
                else
                    ct[min] += process[it->first]->et;
                //update arrival time
                for(auto child:dag[it->first])
                {
                    process[child]->at = max(process[child]->at, ct[min]);
                }
            } 
             
        }
        //Overall time complexity can be given as O(V^2logV + V+E + Vm+E) which is polynomial
        for(int i=0;i<m;i++)
        {
            cout<<"("<<ct[i]<<")";
        }
        cout<<endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    int makespan = *max_element(ct.begin(),ct.end());
    cout<<makespan<<endl;
    cout<<elapsed_seconds.count()<<"s"<<endl;
}
int main()
{
    int n,m;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    vector<vector<int>> dag(n);
    vector<node*> process(n);
    int e,a,b,t;
    cout<<"Enter the execution time for each job: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        process[i] = new node(t);
    }
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges: "<<endl;
    while(e)
    {
        cin>>a>>b;
        dag[a].push_back(b);
        process[b]->indeg++;
        e--;
    }
    cout<<"Enter the number of machines: ";
    cin>>m;
    vector<int> ct(m,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(!process[i]->indeg)  //push all jobs with indegree 0 into the queue
            q.push(i);
    }
   scheduling(q,dag,process,ct);
}
/*
Since the algorithm giving optimal sol. should follow topological order, the conflict can come in the case of scheduling jobs with indegree 0 at an instant.
Let W[i] be the maximum completion time.
Let 'j' be the last task assigned to machine 'i'.
Let I be the smallest instance of the problem where the algorithm conflicts the optimal solution.
Therefore, t[j]<=OPT(I).
Before assigning j to i, its CT was W[i]-t[j].
Now, W[i]-t[j]<=OPT(I)
     W[i]<=OPT(I)+t[j]
     W[i]<=2OPT(I)
*/
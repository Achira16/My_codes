#include<bits/stdc++.h>
using namespace std;


queue<pair<vector<bool>,vector<bool>>> open;
vector<pair<vector<bool>,vector<bool>>> closed;
set<vector<bool>> vis;
pair<vector<bool>,vector<bool>> state;

bool goalTest(vector<bool>& v)
{
    if(v[0] && v[1] && v[2] && !v[3])
        return true;
    return false;
}
bool check(vector<bool>& v)
{
    //lion n goat or goat n cabbage are together on the side where boat isnt there
    if((!v[0]&&!v[1])||(!v[1]&&!v[2]))
        return false;
    return true;
}
pair<vector<bool>,vector<bool>> findChild(vector<bool>& v)
{
    for(auto it=closed.begin();it!=closed.end();it++)
    {
        if(v == it->first)
            return *it;
    }
}
void reconstructPath(pair<vector<bool>,vector<bool>>& st)
{
    vector<vector<bool>> path;
    path.push_back(st.first);
    do
    {
        path.push_back(st.second);
        st = findChild(st.second);
    }while(!st.second.empty());
    for(auto it=path.begin();it!=path.end();it++)
    {
        for(bool x:*it)
        {
            cout<<x;
        }
        cout<<endl;
    }
}
void moveGen(vector<bool>& s)
{
    //complement the state to get a new state
    vector<bool> n_s(4);
    for(int i=0;i<s.size();i++)
    {
        n_s[i] = 1-s[i];
    }
    //check whether it is a valid state or not
    if(check(n_s) && vis.find(n_s)==vis.end())
    {
        open.push(make_pair(n_s,s));
        vis.insert(n_s);
    }
    //try to add each other entity n check whether the resulting state is valid or not
    for(int i=0;i<3;i++)
    {
        if(!n_s[i])
        {
            n_s[i] = 1;
            if(check(n_s) && vis.find(n_s)==vis.end())
            {
                open.push(make_pair(n_s,s));
                vis.insert(n_s);
            }
            n_s[i] = 0;
        }
    }
}
void bfs()
{
    pair<vector<bool>,vector<bool>> st;
    while (!open.empty())
    {
        st = open.front();
        if(goalTest(st.first))
        {
            reconstructPath(st);
        }
        open.pop();
        closed.push_back(st);
        moveGen(st.first);
    }
}
int main()
{
    //Initial state
    vector<bool> s(4),p;
    for(int i=0;i<s.size();i++)
        s[i] = 1;
    state = make_pair(s,p);
    open.push(state);
    vis.insert(state.first);
    bfs();
}
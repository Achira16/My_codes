//approx algo for set cover problem
#include<bits/stdc++.h>
using namespace std;

void setCover(vector<int>& U,set<vector<int>>& F)
{
    vector<vector<int>> res;
    bool flag = true;
    while(!U.empty())
    {
        int max_match = INT32_MIN;
        set<vector<int>>::iterator set_it;
        //finding the subset S which maximises the intersection with U
        for(auto i=F.begin();i!=F.end();i++)
        {
            vector<int> v(min(U.size(),i->size()));
            vector<int>::iterator it;
            it = set_intersection(U.begin(),U.end(),i->begin(),i->end(),v.begin());
            v.resize(it-v.begin());
            int temp = v.size();
            if(temp > max_match)
            {
                max_match = temp;
                set_it = i;
            }
        }
        vector<int> temp;
        for(auto i : *set_it)
        {
            temp.push_back(i);
        }
        res.push_back(temp);
        vector<int>::iterator it;
        //U = U-S
        it = set_difference(U.begin(),U.end(),set_it->begin(),set_it->end(),U.begin());
        U.resize(it-U.begin());
        F.erase(set_it);
        if(F.empty() && !U.empty())
        {
            cout<<"No set cover possible";
            flag = false;
            break;
        }
    }
    if(flag)
    {
         int s = 1;
        for(auto i:res)
        {
            cout<<"S"<<s<<": ";
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
            s++;
        }
    }
}
int main()
{
    int n,f,d;
    cout<<"Enter the number of elements in U: ";
    cin >> n;
    vector<int> U(n);
    cout<<"Enter the elements in U: ";
    for(int i=0;i<n;i++)
    {
       cin>>U[i];
    }
    sort(U.begin(),U.end());
    cout<<"Enter the number of sets in F: ";
    cin>>f;
    set<vector<int>> F;
    for(int i=0;i<f;i++)
    {
        int m,d;
        cout<<"Enter the size of the subset: ";
        cin >> m;
        vector<int> temp(m);
        for(int j=0;j<m;j++)
        {
            cin >> temp[j];
        }
        sort(temp.begin(), temp.end());
        F.insert(temp);
    }
    setCover(U,F);
}
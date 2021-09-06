#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string s;
float w,e,x;
float fun(int i,float sum,vector<float> probs,vector<int> count,)
{
    if(i > 60)
        return sum/60;
    s.push_back('R');
    vector<int> ncount(count.begin(),count.end());
    ncount[0]++;
    vector<float> nprobs(probs.begin(),probs.end());
    nprobs[1] = ncount[0]/i;
    float avg = fun(i+1,sum+probs[2]*w+probs[0]*e,nprobs,ncount);
    if(avg >= x)
        return avg;
    s.pop_back();
    s.push_back('P');
    vector<int> ncount(count.begin(),count.end());
    ncount[1]++;
    vector<float> nprobs(probs.begin(),probs.end());
    nprobs[2] = ncount[1]/i;
    avg = fun(i+1,sum+probs[0]*w+probs[1]*e,nprobs,ncount);
    if(avg >= x)
        return avg;
    s.pop_back();
    s.push_back('S');
    vector<int> ncount(count.begin(),count.end());
    ncount[2]++;
    vector<float> nprobs(probs.begin(),probs.end());
    nprobs[0] = ncount[2]/i;
    avg = fun(i+1,sum+probs[1]*w+probs[2]*e,nprobs,ncount);
    return avg;
}
int main()
{
    int t;
    cin>>t;
    cin>>x;
    for(int i=1;i<=t;i++)
    {
        cin>>w>>e;
        cout<<"Case #"<<i<<": "<<fun(x,w,e)<<"\n";
    }
}
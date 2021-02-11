//Line segment intersection
#include<bits/stdc++.h>
using namespace std;

int direction(pair<int,int> pi,pair<int,int> pj,pair<int,int> pk)
{
    pair<int,int> p1,p2;
    p1 = make_pair(pk.first-pi.first,pk.second-pi.second);
    p2 = make_pair(pj.first-pi.first,pj.second-pi.second);
    return p1.first*p2.second-p2.first*p1.second;
}
bool on_segment(pair<int,int>& pi,pair<int,int>& pj,pair<int,int>& pk)
{
    if(((pk.first>=min(pi.first,pj.first)) && (pk.first<=max(pi.first,pj.first))) && ((pk.second>=min(pi.second,pj.second)) && (pk.second<=max(pi.second,pj.second))))
        return true;
    return false;
}
bool segment_intersect(pair<int,int>& p1,pair<int,int>& p2,pair<int,int>& p3,pair<int,int>& p4)
{
    int d1,d2,d3,d4;
    d1 = direction(p3,p4,p1);
    d2 = direction(p3,p4,p2);
    d3 = direction(p1,p2,p3);
    d4 = direction(p1,p2,p4);
    if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0)))
        return true;
    else if (d1 == 0 && on_segment(p3,p4,p1))
        return true;
    else if (d2 == 0 && on_segment(p3,p4,p2))
        return true;
    else if (d3 == 0 && on_segment(p1,p2,p3))
        return true;
    else if (d4 == 0 && on_segment(p1,p2,p4))
        return true;
    return false;
}
int main()
{
    pair<int,int> p1,p2,p3,p4;
    int x1, y1, x2, y2, x3, y3,x4, y4;
    cout<<"Enter the co-ordinates of line 1: ";
    cin>>x1>>y1>>x2>>y2;
    p1 = make_pair(x1,y1);
    p2 = make_pair(x2,y2);
    cout<<"Enter the co-ordinates of line 2: ";
    cin>>x3>>y3>>x4>>y4;
    p3 = make_pair(x3,y3);
    p4 = make_pair(x4,y4);
    bool ans = segment_intersect(p1,p2,p3,p4);
    if(ans)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
}
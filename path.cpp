#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>>& h,int e)
{
    int m = h.size(),n = h[0].size();
    vector<vector<bool>> vis(m,vector<bool> (n,0));
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vis[0][0] = true;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        int cur_i = temp.first,cur_j = temp.second;
        for(int i=0;i<4;i++)
        {
            int next_i = cur_i + dir[i][0];
            int next_j = cur_j + dir[i][1];
            if(next_i>=0 && next_i<m && next_j>=0 && next_j<n && !vis[next_i][next_j])
            {
                if(abs(h[cur_i][cur_j]-h[next_i][next_j]) <= e)
                {
                    if(next_i == m-1 && next_j == n-1)
                        return true;
                    q.push(make_pair(next_i,next_j));
                    vis[next_i][next_j] = true;
                }     
            }
        }
    }
    return false;
}
int solve(vector<vector<int>>& heights)
{ 
    int max_height = INT32_MIN, min_height = INT32_MAX;
    int m = heights.size(),n = heights[0].size();
    if(m==1 && n==1)
        return 0;
    for(int i = 0; i < heights.size();i++)
    {
        for(int j=0;j<heights[i].size();j++)
        {
            if(i<m-1 && j<n-1)
            {
                max_height = max(max_height,max(abs(heights[i][j]-heights[i][j+1]),abs(heights[i][j]-heights[i+1][j])));
                min_height = min(min_height,min(abs(heights[i][j]-heights[i][j+1]),abs(heights[i][j]-heights[i+1][j])));
            }
            else if(i == m-1 && j<n-1)
            {
                max_height = max(max_height,abs(heights[i][j]-heights[i][j+1]));
                min_height = min(min_height,abs(heights[i][j]-heights[i][j+1]));
            }
            else if(j == n-1 && i<m-1)
            {
                max_height = max(max_height,abs(heights[i][j]-heights[i+1][j]));
                min_height = min(min_height,abs(heights[i][j]-heights[i+1][j]));
            }
        }
    }
    int low = min_height,high = max_height;
    int effort = INT32_MAX;
    while(low<=high)
    {
        int mid = (low+high)/2;
        bool ans = search(heights,mid);
        if(ans)
        {
            high = mid-1;
            effort = min(effort,mid);
        }
        else
            low = mid+1;
    }
    return effort;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<solve(mat);
}
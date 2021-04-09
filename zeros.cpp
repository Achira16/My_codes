#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        if(n == 1)
            return 1;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<vector<bool>> vis(n,vector<bool> (n,0));
        vis[0][0] = true;
        int dir[][2] = {{1,0},{0,1},{1,1},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1}};
        int level = 0;
        while(!q.empty())
        {  
            level++;
            int s = q.size();
            for(int i =0 ;i< s;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == grid.size()-1 && y==grid[0].size()-1)
                    return level;
                for(int j=0;j<8;j++)
                {
                    int newx = x+dir[j][0];
                    int newy = y+dir[j][1];
                    if(newx<0 || newx>=grid.size() || newy<0 || newy>=grid.size() || grid[newx][newy] == 1)
                        continue;
                    if(!vis[newx][newy])
                    {
                        q.push(make_pair(newx,newy));
                        vis[newx][newy]=1;
                    } 
                }
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    int b;
    vector<vector<int>> grid;
    for(int i =0;i < 2;i++)
    {
        vector<int> a;
        for(int j = 0;j<2;j++)
        {
            cin >> b;
            a.push_back(b);
        }
        grid.push_back(a);
    }
    cout << s.shortestPathBinaryMatrix(grid);

}
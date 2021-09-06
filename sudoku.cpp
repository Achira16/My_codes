#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(isdigit(board[i][j]))
                {
                    for(int k=i+1;k<9;k++)
                    {
                        if(board[k][j] == board[i][j])
                        {
                            cout<<k<<j;
                            return 0;
                        }
                    }
                    for(int k=j+1;k<9;k++)
                    {
                        if(board[i][k] == board[i][j])
                        {
                            cout<<i<<k;
                            return 0;
                        }
                    }
                    int c = 0;
                    for(int k=i/3*3;k<i/3*3+3;k++)
                    {
                        for(int l=j/3*3;l<j/3*3+3;l++)
                        {
                            if(board[k][l] == board[i][j])
                                c++;
                        }
                    }
                    if(c > 1)
                        return 0;  
                }
            }
        }
        return 1;
    }
};
int main()
{
    vector<vector<char>> board(9,vector<char> (9));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }
    Solution obj;
    cout<<obj.isValidSudoku(board);
}
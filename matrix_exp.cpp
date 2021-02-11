#include<bits/stdc++.h>
using namespace std;

void multiply(vector<vector<int>>& F,vector<vector<int>>& M){
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0]; 
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1]; 
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; 
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1]; 
      
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
}
void power(vector<vector<int>>& F,int n){
    if(n == 0||n == 1)
        return;
    power(F,n/2);
    multiply(F,F);
    vector<vector<int>> M = {{1,1},{1,0}};
    if(n&1)
        multiply(F,M);
}
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    vector<vector<int>> F = {{1,1},{1,0}};
    power(F,n-1);
    return F[0][0];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
}
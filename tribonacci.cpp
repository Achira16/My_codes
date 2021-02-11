#include<bits/stdc++.h>
using namespace std;
#define ll long long

void multiply(vector<vector<ll>>& F,vector<vector<ll>>& M){
    int mod = 1000000007;
    vector<vector<ll>> temp(3,vector<ll> (3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                temp[i][j] += ((F[i][k]%mod)*(M[k][j]%mod))%mod;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            F[i][j] = temp[i][j];
        }
    }
}
void power(vector<vector<ll>>& T,int n){
    if(n == 0||n == 1)
        return;
    power(T,n/2);
    multiply(T,T);
    vector<vector<ll>> M = {{1,1,1},{1,0,0},{0,1,0}};
    if(n&1)
        multiply(T,M);
}
int trib(ll n){
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    if(n==2)
        return 4;
    vector<vector<ll>> T = {{1,1,1},{1,0,0},{0,1,0}};
    power(T,n-2);
    return (T[0][0]*4 + T[0][1]*2 + T[0][2])%1000000007;
}
int main(){
    ll n = 1e18;
    cout<<trib(n);
}
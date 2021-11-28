#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if((a+b) & 1){
            cout<<-1<<" "<<-1<<endl;
        }
        else{
            if(a >= b){
                int x = (a-b)/2;
                int y = (a+b)/2 - x;
                cout<<x<<" "<<y<<endl;
            }
            else{
                int y = (b-a)/2;
                int x = (a+b)/2 - y;
                cout<<x<<" "<<y<<endl;
            }
        }
    }
}
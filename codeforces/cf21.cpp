#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    int t;
    cin>>t;
    while (t--){
        int x1,p1,x2,p2;
        cin>>x1>>p1>>x2>>p2;
        string n1 = to_string(x1);
        string n2 = to_string(x2);
        int d1 = n1.size() + p1;
        int d2 = n2.size() + p2;
        if(d1 > d2)
            cout<<">\n";
        else if(d1 < d2)
            cout<<"<\n";
        else{
            int i=0;
            int eq = 0;
            while(i < min(n1.size(),n2.size())){
                if(n1[i] > n2[i]){
                    eq = 1;
                    break;
                }
                else if(n2[i] > n1[i]){
                    eq = 2;
                    break;
                }
                i++;
            }
            if(eq == 0){
                while(i < n1.size()){
                    if(n1[i] > '0'){
                        eq = 1;
                        break;
                    }
                    i++;
                }
                while(i < n2.size()){
                    if(n2[i] > '0'){
                        eq = 2;
                        break;
                    }
                    i++;
                }
            }
            if(eq == 0) cout<<"=\n";
            else if(eq == 1) cout<<">\n";
            else cout<<"<\n";
        }
    }
    
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    double sum = 0;
    for(int i=l;i<=r;i++){
        sum += log10(i);
    }
    int dig = floor(sum)+1;
    cout<<dig<<endl;
    double dec = sum - floor(sum);
    cout<<pow(10,dec)<<endl;
}

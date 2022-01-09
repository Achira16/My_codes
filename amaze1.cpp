#include<bits/stdc++.h>
using namespace std;

int counting(string s){
    int zcnt = 0,ocnt = 0;
    int i = 0;
    char prev;
    if(s[i] == '0'){
        while(i<s.size() && s[i++] == '0') zcnt++;
        prev = '0';
    }
    else{
        while(i<s.size() && s[i] == '1') ocnt++;
        prev = '1';
    }
    while(i < s.size()){
        
    }
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<simpleCipher(s,k);
}
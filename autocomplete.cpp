#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pi pair<int,string>

struct Trie{
    int degree;
    Trie *next[27];
    Trie():degree(0){}
};
bool isSmaller(string& a,string b){
    int i = 0,j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]!=b[j]){
            if(a[i]<b[j])
                return 1;
            else 
                return 0;
        }
        i++;j++;
    }
    if(i < a.size())
        return 0;
    return 1;
}
struct compare{
    bool operator()(pi& a,pi& b){
        if(a.first == b.first)
            return isSmaller(a.second,b.second);
        return a.first > b.first;
    }
};
class AutocompleteSystem{
    Trie *root,*prev;
    priority_queue<pi,vector<pi>,compare> pq;
    string word;
    
    public:

    void insert(Trie *root,string& s,int time){
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                if(!root->next[26])
                    root->next[26] = new Trie();
                root = root->next[26];
            }
            else{
                if(!root->next[s[i]-'a'])
                    root->next[s[i]-'a'] = new Trie();
                root = root->next[s[i]-'a'];
            }
        }
        root->degree += time;
    }
    void dfs(Trie* root){
        for(int i=0;i<27;i++){
            if(root->next[i]){
                char letter = (i == 26)?' ':i+'a';
                word.push_back(letter);
                dfs(root->next[i]);
                word.pop_back();
            }
        }
        if(root->degree != 0){
            if(pq.size() < 3)
                pq.push({root->degree,word});
            else if(pq.size() == 3){
                if(root->degree > pq.top().first || root->degree == pq.top().first && isSmaller(word,pq.top().second)){
                    pq.pop();
                    pq.push({root->degree,word});
                }
            }
        }
    }
    AutocompleteSystem(vector<string> sentences,vector<int> times){
        root = new Trie();
        for(int i=0;i<times.size();i++){
            insert(root, sentences[i],times[i]);
        }
        prev = root;
    }
    vector<string> input(char c){
        if(c == '#'){
            prev = root;
            insert(root,word,1);
            return {};
        }
        if(c == '@'){
            word.push_back(' ');
            if(prev->next[26]){
                prev = prev->next[26];
                dfs(prev);
            }
        }
        else{
            word.push_back(c);
            if(prev->next[c-'a']){
                prev = prev->next[c-'a'];
                dfs(prev);
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    IOS;
    vector<string> sentences;
    vector<int> times;
    string s,t;
    getline(cin,s);
    cin>>t;
    int i = 0;
    while(i < s.size()){
        string word;
        while(i<s.size() && s[i]!=','){
            word.push_back(s[i]);
            i++;
        }
        i++;
        sentences.push_back(word);
    }
    i = 0;
    while(i < t.size()){
        int num = 0;
        while(i<t.size() && t[i]!=','){
            num  = num*10 + t[i]-'0';
            i++;
        }
        i++;
        times.push_back(num);
    }
    int n;
    cin>>n;
    AutocompleteSystem *obj = new AutocompleteSystem(sentences, times);
    
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        // cout<<ch;
        vector<string> ans = obj->input(ch);
        for(auto &str:ans){
            cout<<str<<"  ";
        }
        cout<<endl;
    }
}
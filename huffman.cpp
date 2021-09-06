#include<bits/stdc++.h>
using namespace std;

struct node
{
    char ch;
    int freq;
    node *left,*right;
    node(int f):ch('$'),freq(f),left(NULL),right(NULL){}
    node(char c,int f):ch(c),freq(f),left(NULL),right(NULL){}
};
void heapify_up(vector<node*>& p_q,int index)
{
    int p;
    while(index>0)
    {
        p = (index-1)/2;
        if(p_q[index]<p_q[p])
            swap(p_q[index],p_q[p]);
        else 
            break;
        index = p;
    }
}
void heapify_down(vector<node*>& p_q,int index)
{
    int min = index;
    do
    {
        index = min;
        int l = 2*index+1;
        int r = 2*index+2;
        if(l<p_q.size() && p_q[l]->freq < p_q[min]->freq)
            min = l;
        if(r<p_q.size() && p_q[r]->freq < p_q[min]->freq)
            min = r;
        if(min!=index)
            swap(p_q[index],p_q[min]);
    } while (min!=index);
}
void heapify(vector<node*>& pq,int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify_down(pq,i);
}
node* dequeue(vector<node*>& p_q)
{
    int n = p_q.size();
    swap(p_q[0],p_q[n-1]);
    node* item = p_q[n-1];
    p_q.pop_back();
    heapify_down(p_q,0);
    return item;
}
void enqueue(vector<node*>& p_q,node* d)
{
    p_q.push_back(d);
    heapify_up(p_q,p_q.size()-1);
}
node* huffman(vector<node*>& pq)
{
    while(pq.size()!=1)
    {
        node* a = dequeue(pq);
        node* b = dequeue(pq);
        node* c = new node(a->freq+b->freq);
        c->left = a;
        c->right = b;
        enqueue(pq,c);
    }
    return dequeue(pq);
}
void func(node *root,string& s,vector<string>& ans)
{
    if(!root->left && !root->right)
        ans.push_back(s);
    if(root->left)
    {
        s.push_back('0');
        func(root->left,s,ans);
        s.pop_back();
    }
    if(root->right)
    {
        s.push_back('1');
        func(root->right,s,ans);
        s.pop_back();
    }
}
int main()
{
    string s;
    int n;
    cin>>s>>n;
    vector<int> freq(n);
    for(int i=0;i<n;i++)
        cin>>freq[i];
    vector<node*> minheap(n);
    for(int i=0;i<n;i++)
        minheap[i] = new node(s[i],freq[i]);
    heapify(minheap,n);
    node *root = huffman(minheap);
    vector<string> ans;
    string temp;
    func(root,temp,ans);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    // queue<node*> q;
    // q.push(root);
    // while(!q.empty())
    // {
    //     cout<<q.front()->freq<<" ";
    //     q.pop();
    //     if(root->left)
    //         q.push(root->left);
    //     if(root->right)
    //         q.push(root->right);
    // }
}
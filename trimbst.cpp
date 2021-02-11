#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* search(TreeNode *root,int low,int high)
    {
        if(!root)
            return NULL;
        if(root->val == low)
            root->left = NULL;
        else if(root->val < low)
        {
            root = root->right;
            root = search(root,low,high);
            return root;
        }
        else if(root->val == high)
            root->right = NULL;
        else if(root->val > high)
        {
            root = root->left;
            root = search(root,low,high);
            return root;
        }
        root->left = search(root->left,low,high);
        root->right = search(root->right,low,high);
        return root;
    }
TreeNode* insert(TreeNode *root,int data)
{
    if(!root)
        return new TreeNode(data);
    if(data < root->val)
        root->left = insert(root->left,data);
    else if(data > root->val)
        root->right = insert(root->right,data);
    return root;
}
void levelorder(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    cout<<root->val<<" ";
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
            cout<<temp->left->val<<" ";
        }
        else
        {
            cout<<"null ";
        }
        if(temp->right)
        {
            q.push(temp->right);
            cout<<temp->right->val<<" ";
        }
        else
        {
            cout<<"null ";
        }
    }
}
int main()
{
    TreeNode *root;
    int n;
    cin>>n;
    while(n--)
    {
        int d;
        cin>>d;
        root = insert(root,d);  
    }
   int l,h;
   cin>>l>>h;
    //levelorder(root);
   root = search(root,l,h);
   levelorder(root);
}
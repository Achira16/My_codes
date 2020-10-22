#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  }TreeNode;
vector<int> split(string& s)
{
    string temp = "";
    vector<int> tree;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'n')
            tree.push_back(-1);
        else if(s[i] == ',')
        {
            if(s[i-1]!='n')
            {
                tree.push_back(stoi(temp));
                temp = "";
            }
        }
        else 
        {
            temp += s[i];
        }
    }
    return tree;
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "n";
        string s = "";
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(!temp)
            {
                s+="n";
                s+=",";
            }
            else
            {
                s+=to_string(temp->val);
                s+=",";
                q.push(temp->left);
                q.push(temp->right);
            } 
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> tree = split(data);
        for(auto& it:tree)
            cout<<it<<" ";
        if(tree[0] == -1)
            return NULL;
        TreeNode* root = new TreeNode(tree[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        TreeNode *temp;
        while(!q.empty() && i<tree.size())
        {
            temp = q.front();
            q.pop();
            if(tree[i]!=-1)
            {
                temp->left = new TreeNode(tree[i]);
                q.push(temp->left);
            }
            i++;
            if(tree[i]!=-1)
            {
                temp->right = new TreeNode(tree[i]);
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string s = serialize(root);
    root = deserialize(s);
    cout<<root->val<<" "<<root->left->val<<" "<<root->right->val;
}
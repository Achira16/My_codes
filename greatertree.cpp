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
class Solution {
public:
    int find_sum(TreeNode *root)
    {
        if(!root)
            return 0;
        int sum = root->val;
        sum += find_sum(root->left);
        sum += find_sum(root->right);
        return sum;
    }
    int change(TreeNode *root,int sum)
    {
        if(!root)
            return sum;
        sum = change(root->left,sum);
        int temp = root->val;
        root->val = sum;
        sum -= temp;
        sum = change(root->right,sum);
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        int sum = find_sum(root);
        change(root,sum);
        return root;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    Solution ob;
    int sum = ob.find_sum(root);
    cout<<ob.change
}


template <typename T>
class BinaryTreeNode {
    public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int leftmost(BinaryTreeNode<int> *root)
{
    if(!root->left && !root->right)
        return root->val;
    if(root->left)
        return leftmost(root->left);
    return leftmost(root->right);
}
void search(BinaryTreeNode<int> *root,BinaryTreeNode<int> *prev,int m,int& ans)
{
    if(!root)
        return;
    if(root->val == m)
    {
        if(!prev)
            ans = -1;
        else if(prev->right == root || prev->left == root && !prev->right)
            ans = prev->val;
        else if(prev->left == root && prev->right)
        {
            ans = leftmost(prev->right);
        }
    }
    else{
        search(root->left,root,m,ans);
    	search(root->right,root,m,ans);
    }
}
int solve(BinaryTreeNode<int> *root, int node)
{
    int ans = -1;
    search(root,NULL,node,ans);
    return ans;
}
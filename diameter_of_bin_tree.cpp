#include<bits/stdc++.h>
using namespace std;

int ans = 0;
typedef struct node
{
    int d;
    node *left,*right;
}node;
node* Newnode(int d)
{
    node *temp = new node();
    temp->d = d;
    temp->left = temp->right = NULL;
    return temp;
}
int calc(node *root)
{
    if(!root)
        return 0;
    int l_h = calc(root->left);
    int r_h = calc(root->right);
    ans = max(ans,l_h+r_h);
    return (max(l_h,r_h)+1);
}
int main()
{
    node *root = Newnode(1);
    root->left = Newnode(2);
    root->right = Newnode(3);
    root->left->left = Newnode(4);
    root->left->right = Newnode(5);
    root->left->left->left = Newnode(6);
    root->left->left->right = Newnode(7);
    root->left->left->right->left = Newnode(8);
    root->left->left->right->left->right = Newnode(9);
    root->left->right->right = Newnode(10);
    root->left->right->right->left = Newnode(11);
    root->left->right->right->right = Newnode(12);
    root->left->right->right->right->left = Newnode(13);
    calc(root);
    cout<<ans;
}
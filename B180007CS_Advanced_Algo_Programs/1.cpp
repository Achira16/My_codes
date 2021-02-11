//AVL insertion
#include<bits/stdc++.h>
using namespace std;

class avl
{
    int val;
    avl *left,*right;
    int bal_fac;
    int height;
    public:
    avl():val(0),left(NULL),right(NULL),bal_fac(0),height(0){}
    avl(int d):val(d),left(NULL),right(NULL),bal_fac(0),height(0){}
    int get_height(avl *root)
    {
        if(!root) return -1;
        return root->height;
    }
    avl* insert(avl* , int );
    avl* LL(avl* ,avl* );
    avl* RR(avl* ,avl* );
    avl* LR(avl* ,avl* );
    avl* RL(avl* ,avl* );
    void levelOrder(avl *root);
};
avl* avl::LL(avl* a,avl* b)
{
    a->left = b->right;
    b->right = a;
    a->height = 1 + max(get_height(a->left),get_height(a->right));
    b->height = 1 + max(get_height(b->left),get_height(b->right));
    a->bal_fac = get_height(a->left) - get_height(a->right);
    b->bal_fac = get_height(b->left) - get_height(b->right);
    return b;
}
avl* avl::RR(avl* a,avl* b) 
{
    a->right = b->left;
    b->left = a;
    a->height = 1 + max(get_height(a->left),get_height(a->right));
    b->height = 1 + max(get_height(b->left),get_height(b->right));
    a->bal_fac = get_height(a->left) - get_height(a->right);
    b->bal_fac = get_height(b->left) - get_height(b->right);
    return b;
}
avl* avl::LR(avl* a,avl* b)
{
    a->left = RR(b,b->right);
    return LL(a,a->left);
}
avl* avl::RL(avl* a,avl* b)
{
    a->right = LL(b,b->left);
    return RR(a,a->right);
}
avl* avl::insert(avl* root,int val)
{
    if(!root)
    {
        return new avl(val);
    }
    else if(val<root->val)
        root->left = insert(root->left,val);
    else if(val>root->val)
        root->right = insert(root->right,val);
    root->height = 1 + max(get_height(root->left),get_height(root->right));
    root->bal_fac = get_height(root->left) - get_height(root->right);
    if(root->bal_fac > 1 && val < root->left->val)
    {
        return LL(root,root->left);
    }
    else if(root->bal_fac > 1 && val > root->left->val)
    {
        return LR(root,root->left);
    }
    else if(root->bal_fac < -1 && val > root->right->val)
    {
        return RR(root,root->right);
    }
    else if(root->bal_fac < -1 && val < root->right->val)
    {
        return RL(root,root->right);
    }
    return root;
}
void avl::levelOrder(avl *root)
{
    if(!root)
        return;
    queue<avl*> q;
    cout<<root->val<<" ";
    q.push(root);
    while(!q.empty())
    {
        avl *temp = q.front();
        q.pop();
        if(temp->left)
        {
            cout<<temp->left->val<<" ";
            q.push(temp->left);
        }
        else
        {
            cout<<"null ";
        }
        if(temp->right)
        {
            cout<<temp->right->val<<" ";
            q.push(temp->right);
        }
        else
        {
            cout<<"null ";
        }
    }
}
int main()
{
    avl *root,obj;
    int n,d;
    cout<<"Enter the no. of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        root = obj.insert(root,d);
    }    
    obj.levelOrder(root);
}
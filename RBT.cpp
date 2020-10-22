#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int d;
    node *p,*l,*r;
    bool color;
    node(int x):d(x),p(NULL),l(NULL),r(NULL),color(1){}
}node;
node *root = NULL;

void left_rotate(node* a)
{
    node* b = a->r;
    a->r = b->l;
    if(b->l!=NULL)
        b->l->p = a;
    b->p = a->p;
    if(a->p == NULL)
        root = b;
    else if(a == a->p->r)
        a->p->r = b;
    else 
        a->p->l = b;
    b->l = a;
    a->p = b;
}
void right_rotate(node* a)
{
    node *b = a->l;
    a->l = b->r;
    if(b->r != NULL)
        b->r->p = a;
    else if(a == a->p->r)
        a->p->r = b;
    else
        a->p->l = b;
    b->r = a;
    a->p = b;
}
void insert_fixup(node *z)
{
    while (z->p!=NULL && z->p->color == 1)
    {
        if(z->p == z->p->p->l)
        {
            node *y = z->p->p->r;
            if(!y || y->color == 0)
            {
                if(z = z->p->r)
                {
                    z = z->p;
                    left_rotate(z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                right_rotate(z->p->p);
            }
            else 
            {
                y->color = 0;
                z->p->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            }
        }
        else
        {
            node *y = z->p->p->l;
            if(!y || y->color == 0)
            {
                if(z = z->p->l)
                {
                    z = z->p;
                    right_rotate(z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                left_rotate(z->p->p);
            }
            else 
            {
                y->color = 0;
                z->p->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            }   
        }
    }
    root->color = 0;
}
void insert(node *z)
{
    node* y = NULL;
    node* x = root;
    while (x!=NULL)
    {
        y = x;
        if(z->d>x->d)
            x = x->r;
        else
            x = x->l;
    }
    z->p = y;
    if(y == NULL)
        root = z;
    else if(z->d>y->d)
        y->r = z;
    else
        y->l = z;
    insert_fixup(z);
}
void preorder(node *root)
{
    if(!root)
        return;
    cout<<root->d<<" ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(node *root)
{
    if(!root)
        return;
    inorder(root->l);
    cout<<root->d<<" ";
    inorder(root->r);
}
int main()
{
    int n;
    cin>>n;
    while(n)
    {
        int x;
        cin>>x;
        node *temp = new node(x);
        insert(temp);
        n--;
    }
    inorder(root);
    cout<<endl;
    preorder(root);
}
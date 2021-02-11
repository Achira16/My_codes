#include <bits/stdc++.h> 
using namespace std; 
  
typedef struct Node 
{ 
    int data; 
    bool color; 
    Node *left, *right, *parent; 
    Node(int data) : data(data),color(1),left(NULL),right(NULL),parent(NULL){}
}Node; 
  
// Class to represent Red-Black Tree 
class RBTree 
{ 
private: 
    Node *root; 
protected: 
    void rotateLeft(Node *&, Node *&); 
    void rotateRight(Node *&, Node *&); 
    void insertFixup(Node *&, Node *&); 
public: 
    RBTree() { root = NULL; } 
    void insert(const int &n); 
    void inorder(); 
    void levelOrder(); 
}; 
  
// A recursive function to do inorder traversal 
void inorderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    inorderHelper(root->left); 
    cout << root->data << "  "; 
    inorderHelper(root->right); 
} 
  
/* A utility function to insert  
    a new node with given key 
   in BST */
Node* BSTInsert(Node* root, Node *pt) 
{ 
    /* If the tree is empty, return a new node */
    if (root == NULL) 
       return pt; 
  
    /* Otherwise, recur down the tree */
    if (pt->data < root->data) 
    { 
        root->left  = BSTInsert(root->left, pt); 
        root->left->parent = root; 
    } 
    else if (pt->data > root->data) 
    { 
        root->right = BSTInsert(root->right, pt); 
        root->right->parent = root; 
    } 
  
    /* return the (unchanged) node pointer */
    return root; 
} 
  
// Utility function to do level order traversal 
void levelOrderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    queue<Node *> q; 
    q.push(root); 
    cout << root->data << "("<<root->color<<") "; 
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop(); 
  
        if (temp->left) 
        {
            cout << temp->left->data << "("<<temp->left->color<<") "; 
            q.push(temp->left);
        }
        else
        {
            cout<<"Null ";
        }
        if (temp->right) 
        {
            cout << temp->right->data << "("<<temp->right->color<<") "; 
            q.push(temp->right); 
        }
        else
        {
            cout<<"Null "; 
        }
        
    } 
} 
  
void RBTree::rotateLeft(Node *&root, Node *&a) 
{ 
    Node *b = a->right; 
  
    a->right = b->left; 
  
    if (a->right != NULL) 
        a->right->parent = a; 
  
    b->parent = a->parent; 
  
    if (a->parent == NULL) 
        root = b; 
  
    else if (a == a->parent->left) 
        a->parent->left = b; 
  
    else
        a->parent->right = b; 
  
    b->left = a; 
    a->parent = b; 
} 
  
void RBTree::rotateRight(Node *&root, Node *&a) 
{ 
    Node *b = a->left; 
  
    a->left = b->right; 
  
    if (a->left != NULL) 
        a->left->parent = a; 
  
    b->parent = a->parent; 
  
    if (a->parent == NULL) 
        root = b; 
  
    else if (a == a->parent->left) 
        a->parent->left = b; 
  
    else
        a->parent->right = b; 
  
    b->right = a; 
    a->parent = b; 
} 
  
// This function fixes violations  
// caused by BST insertion 
void RBTree::insertFixup(Node *&root, Node *&pt) 
{ 
    Node *parent_pt = NULL; 
    Node *grand_parent_pt = NULL; 
    while ((pt != root) && (pt->color != 0) && (pt->parent->color == 1)) 
    { 
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child  
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Node *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt && uncle_pt->color ==  1) 
            { 
                grand_parent_pt->color = 1; 
                parent_pt->color = 0; 
                uncle_pt->color = 0; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root, parent_pt); 
                    pt = parent_pt;
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                parent_pt->color = 0;
                grand_parent_pt->color = 1;
                rotateRight(root, grand_parent_pt); 
                pt = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of pt is right child  
           of Grand-parent of pt */
        else
        { 
            Node *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 1)) 
            { 
                grand_parent_pt->color = 1; 
                parent_pt->color = 0; 
                uncle_pt->color = 0; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                parent_pt->color = 0;
                grand_parent_pt->color = 1;
                rotateLeft(root, grand_parent_pt); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = 0; 
} 
  
// Function to insert a new node with given data 
void RBTree::insert(const int &data) 
{ 
    Node *pt = new Node(data); 
  
    // Do a normal BST insert 
    root = BSTInsert(root, pt); 
  
    // fix Red Black Tree violations 
    insertFixup(root, pt); 
} 
  
// Function to do inorder and level order traversals 
void RBTree::inorder()     {  inorderHelper(root);} 
void RBTree::levelOrder()  {  levelOrderHelper(root); } 
  
// Driver Code 
int main() 
{ 
    RBTree tree; 
    int n,x;
    cin >>n;
    while (n)
    {
        cin>>x;
        tree.insert(x);
        n--;
    }
    cout << "Inoder Traversal of Created Tree\n"; 
    tree.inorder(); 
  
    cout << "\n\nLevel Order Traversal of Created Tree\n"; 
    tree.levelOrder(); 
  
    return 0; 
}
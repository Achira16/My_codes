#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    node *next;
    node(int x) : val(x),next(NULL){}
}node;

void merge(vector<node*>& arr,int a,int b)
{
    node *t1 = arr[a],*t2 = arr[b],*prev = NULL,*temp;
    if(!t1)
    {
        arr[a] = arr[b];
        return;
    }
    while(t1 && t2)
    {
        if(t1->val < t2->val)
        {
            prev = t1;
            t1 = t1->next;
        }
        else
        {
            temp = t2;
            t2 = t2->next;
            temp->next = t1;
            if(!prev)
                arr[a] = temp;
            else
                prev->next = temp;
            prev = temp;
        }
    }
    while(t2)
    {
        prev->next = t2;
        t2 = t2->next;
        prev = prev->next;
    }
}
void mergesort(vector<node*>& arr,int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid+1);
    }
}
node* mergeKLists(vector<node*>& lists) {
        int k = lists.size();
        if(!k)
            return NULL;
        bool flag = 1;
        for(int i=0;i<k;i++)
        {
            if(lists[i])
                flag = 0;
        }
        if(flag)
            return NULL;
        mergesort(lists,0,k-1);
        return lists[0];
    }
int main()
{
    int k = 1;
    vector<node*> arr(k);
    arr[0] = NULL;
    // arr[0] = new node(1);
    // arr[0]->next = new node(2);
    // arr[0]->next->next = new node(4);
    // arr[1] = new node(5);
    // arr[1]->next = new node(6);
    // arr[1]->next->next = new node(7);
    // arr[2] = new node(2);
    // arr[2]->next = new node(6);
    
    node *ans = mergeKLists(arr);
    if(ans)
    {
        node *temp = ans;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
    
}
 #include<bits/stdc++.h>
 using namespace std;
 typedef struct ListNode
 {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;
 ListNode* insert(int x,ListNode *head)
 {
     ListNode *temp = new ListNode(x);
     if(head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
 }
 ListNode* partition(ListNode** l,ListNode* pi,ListNode** prev,ListNode** tail,ListNode** head)
    {
        ListNode* cur = *l;
        while(cur!=pi)
        {
            if(cur->val > pi->val)
            {
                if(cur == (*head))
                    (*head) = (*head)->next;
                if(cur == *l)
                    (*l) = (*l)->next;
                if(*prev)
                    (*prev)->next = cur->next;
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = (*tail)->next;
                (*tail)->next = temp;
                (*tail) = temp;
            }
            else
            {
                (*prev) = cur;
                cur = cur->next;
            }
        }
        return pi;
    }
    ListNode* quicksort(ListNode* l,ListNode* u,ListNode* prev,ListNode *head)
    {
        if(l!=u)
        {
            ListNode* tmp_prev = prev;
            ListNode *tail = u;
            ListNode* pi = partition(&l,u,&prev,&tail,&head);
            if(tmp_prev!=prev && l!=pi)
            {
                ListNode* tmp = l;
                while(tmp->next!=pi)
                {
                    tmp = tmp->next;
                }
                head = quicksort(l,tmp,tmp_prev,head);
            }
            if(tail!=u)
            {
                head = quicksort(pi->next,tail,pi,head);
            }
        }
        return head;
    }
    
ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        bool sorted = 1;
        ListNode* temp = head;
        while(temp->next!=NULL)
        {
            if(temp->val > temp->next->val)
            {
                sorted = 0;
                break;
            }
            temp = temp->next;
        }
        if(sorted)
            return head;
        else
        {
            ListNode* last = head;
            while(last->next!=NULL)
            {
                last = last->next;
            }
            head = quicksort(head,last,NULL,head);
        }
        return head;
}
int main()
{
    ListNode *head = NULL;
    int n;
    cin>>n;
    while(n)
    {
        int x;
        cin>>x;
        head = insert(x,head);
        n--;
    }
    head = sortList(head);
    ListNode *tmp = head;
    while (tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    
}
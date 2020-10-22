#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache:public Cache
{
    public:
    LRUCache(int c)
    {
        cp = c;
    }
    void set(int ,int );
    int get(int );
};
void LRUCache::set(int k,int val)
{
    if(cp == 0)
        return;
    if(mp.find(k) == mp.end())
    {
        Node *temp = new Node(k,val);
        if(!head && !tail)
            head = tail = temp;
        else
        { 
            temp->next = head;
            head->prev = temp;
            head = temp;
            if(mp.size() == cp)
            {
                Node *t = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete t;
            }
        }
        mp[k] = temp;
    }
    else
    {
        Node *temp = mp[k];
        temp->value = val;
        if(temp!=head)
        {
            temp->prev->next = temp->next;
            if(temp->next)
                temp->next->prev = temp->prev;
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
    }
}
int LRUCache::get(int k)
{
    if(mp.find(k)!=mp.end())
        return mp[k]->value;
    return -1;
}
int main() {
    IOS;
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

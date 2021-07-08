#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int _key, int _val) : key(_key), val(_val){}

    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end())
        {
            node* resnode = mp[key];
            int res = resnode->val;

            mp.erase(key);

            deleteNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return res;    
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node* exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        }

        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key] = head->next;
    }
};


int main()
{
    LRUCache* obj = new LRUCache(3);

    obj->put(1,1);
    obj->put(2,2);
    obj->put(3,3);
    obj->put(4,4);
    int res = obj->get(1);
    obj->put(5,5);
    res = obj->get(3);

}
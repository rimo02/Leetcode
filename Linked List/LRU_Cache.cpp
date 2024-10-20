#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v)
    {
        key = k;
        val = v;
    }
};
class LRUCache
{
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addToHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node)
    {
        Node *prevv = node->prev;
        Node *nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            int result = node->val;
            removeNode(node);
            addToHead(node);
            return result;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            removeNode(node);
            mp.erase(key);
            delete node;
        }
        if (mp.size() == cap)
        {
            Node *lru = tail->prev;
            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
        Node *newNode = new Node(key, value);
        addToHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
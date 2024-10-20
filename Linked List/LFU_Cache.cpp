#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int val;
    int cnt;
    Node *prev;
    Node *next;
    Node(int k, int v)
    {
        key = k;
        val = v;
        cnt = 1;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void add_first(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void remove(Node *node)
    {
        Node *prevv = node->prev;
        Node *nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    bool is_empty()
    {
        return head->next == tail;
    }
};
class LFUCache
{
public:
    unordered_map<int, Node *> mp1;
    unordered_map<int, List *> mp2;
    int cap;
    int minCount;
    LFUCache(int capacity)
    {
        cap = capacity;
        minCount = 0;
    }
    void update_frequency(Node *node)
    {
        int count = node->cnt;
        mp2[count]->remove(node);
        if (mp2[count]->is_empty() && count == minCount)
        {
            minCount++;
        }
        node->cnt++;
        count++;

        if (mp2.find(count) == mp2.end())
        {
            mp2[count] = new List();
        }
        mp2[count]->add_first(node);
    }
    int get(int key)
    {
        if (cap == 0 || mp1.find(key) == mp1.end())
        {
            return -1;
        }
        Node *node = mp1[key];
        int val = node->val;
        update_frequency(node);
        return val;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        if (mp1.find(key) != mp1.end()) // if found then increase its freqiency and update the value;
        {
            Node *node = mp1[key];
            node->val = value;
            update_frequency(node);
        }
        else
        {
            if (mp1.size() == cap)
            {
                List *list = mp2[minCount]; // get a track of most frequenty used and then remove it
                mp1.erase(list->tail->prev->key);
                list->remove(list->tail->prev);

                if (list->is_empty())
                {
                    mp1.erase(minCount);
                }
            }
            Node *node = new Node(key, value);
            minCount = 1;
            if (mp2.find(minCount) == mp2.end())
            {
                mp2[minCount] = new List();
            }
            mp2[minCount]->add_first(node);
            mp1[key] = node;
        }
    }
};
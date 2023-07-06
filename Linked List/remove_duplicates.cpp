#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertNode(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    Node *deleteDuplicates(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr && curr->next)
        {
            if (curr->data == curr->next->data)
            {
                Node *temp = curr;
                while (temp != nullptr && temp->data == curr->data)
                {
                    temp = temp->next;
                }
                prev->next = temp;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
    void duplicates()
    {
        head = deleteDuplicates(head);
        display();
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    // list.insertNode(2);
    // list.insertNode(2);
    list.insertNode(3);
    list.insertNode(3);
    // list.insertNode(4);
    list.insertNode(4);
    list.insertNode(5);
    list.insertNode(5);
    list.display();
    list.duplicates();
}
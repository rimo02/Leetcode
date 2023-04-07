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
    char ch;
    int num;
    cout << "Enter the number:";
    cin >> num;
    list.insertNode(num);
    cout << "Do you want to continue?";
    cin >> ch;
    while (ch == 'Y' || ch == 'y')
    {
        cout << "Enter 1 to insert, 2 to display: ";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number:";
            int num;
            cin >> num;
            list.insertNode(num);
            break;
        case 2:
            list.display();
            break;
        default:
            cout << "Wrong case";
            break;
        }
        cout << "Do you want to continue?";
        cin >> ch;
    }
}
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteByValue(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reversePrint(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    reversePrint(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;
    
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original queue: ";
    display(head);

    deleteByValue(head, 30);

    cout << "After deleting 30: ";
    display(head);
    cout << "Forward traversal: ";
    display(head);
    cout << "Reverse printing: ";
    reversePrint(head);

    cout << endl;

    return 0;
}

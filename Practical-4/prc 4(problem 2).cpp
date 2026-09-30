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

// Insert at end
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

// Delete node by value
void deleteByValue(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    // If first node contains the value
    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    // Find node before the node to delete
    while (temp->next != NULL &&
           temp->next->data != value)
    {
        temp = temp->next;
    }

    // Value not found
    if (temp->next == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    // Delete the node
    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}

// Forward traversal
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

// Reverse printing using recursion
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

    // Create queue
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original queue: ";
    display(head);

    // Delete patient 30
    deleteByValue(head, 30);

    cout << "After deleting 30: ";
    display(head);

    // Forward traversal
    cout << "Forward traversal: ";
    display(head);

    // Reverse printing
    cout << "Reverse printing: ";
    reversePrint(head);

    cout << endl;

    return 0;
}
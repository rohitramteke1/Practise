#include <iostream>
using namespace std;

// Circular Singly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkedList
{
    Node *head;
    public:
    CircularLinkedList() : head(NULL) {}
    void insertAtHead(int);
    void insertAtTail(int);
    void insertNode(int);
    void deleteNode(int);
    void traverse();
};

void CircularLinkedList::insertNode(int data){
    Node *newNode = new Node(data);
     
    // Because it's is first Node
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}

void CircularLinkedList::traverse(){
    if (head == NULL)
    {
        cout << "Linked list is empty: " << endl ;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << ' ';
        temp = temp->next;
    } while (temp != head);
}


int main() {
    CircularLinkedList cl;
    cl.insertNode(10);
    cl.insertNode(11);
    cl.insertNode(12);
    cl.insertNode(13);
    cl.insertNode(14);
    cl.traverse();

    return 0;
}
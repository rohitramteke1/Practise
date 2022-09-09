#include <iostream>
using namespace std;

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

class DoublyLinkedList
{
    Node *head;
    public:

    DoublyLinkedList() : head(NULL) {}
    void insertNode(int);
    void deleteNode(int);
    void traverse();
};

void DoublyLinkedList::insertNode(int data){
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        // cout << head->data << '\n';
        return;
    }
    
    // case -1
    // Node *temp = head, *temp2;
    // if (head != NULL)
    // {
    //     head->prev = newNode;
    // }
    // head = newNode;
    
    // case -2
    Node *temp = head, *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    // newNode->next = NULL; No need
    // newNode->data = data; No need
    // cout << newNode->data << endl;
}

// Delete in between
void DoublyLinkedList::deleteNode(int nodeOffset){
    Node *ptr = head;
    Node *ptr2;
    int ListLen = 1;

    // Check if the list is empty or not
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    // Count the List length
    if (ptr != NULL)
    {
        ListLen++;
        ptr = ptr->next;
        cout << "List Len: " << ListLen << endl;
    }
    // Check the Index of element
    if (nodeOffset > ListLen)
    {
        cout << "Index of out of range" << endl;
        return;
    }
    // reset ptr;
    ptr = head;
    // Delete head or nodeOffset == 1
    if (nodeOffset == 1)
    {
        head = head->next;
        head->prev = NULL;
        delete ptr;
    }
    // Delete element other than head or nodeOffset != 1
    while (nodeOffset-- > 1)
    {
        ptr2 = ptr;
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr2->next = ptr->next;
    // (ptr->next)->prev = ptr2;
    temp->prev = ptr2;
    delete ptr;
}

void DoublyLinkedList::traverse(){
    Node *ptr = head;
    if (head == NULL)
    {
        cout << "Linked List is Empty: " << endl;
        return;
    }
    
    while (ptr != NULL)
    {
        cout << ptr->data << '\t';
        ptr = ptr->next;
    }
}

int main()
{
    DoublyLinkedList dll;
    dll.insertNode(10);
    dll.insertNode(20);
    dll.insertNode(30);
    dll.insertNode(40);
    
    dll.traverse();
    dll.deleteNode(2);
    dll.traverse();

    return 0;
}
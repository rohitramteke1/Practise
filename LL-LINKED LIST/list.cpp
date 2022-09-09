/****************************************************************
 * NAME: ROHIT MAROTI RAMTEKE
 * CLASS: 2nd Year
 * BRANCH: S3
 * AIM: Linked List and its operation
 ****************************************************************/
#include <iostream>
using namespace std;

// Time Complexity : O(N)
// Auxiliary Space Complexity : O(N)
class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(NULL) {}
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
    LinkedList() : head(NULL) {}
    // same as insert at last
    void insertNode(int);
    void insertInBetween(int, int);
    void insertAtFirst(int);

    void deleteNode(int);
    void traverseList();
};

// Insert a node at First or Before head
void LinkedList::insertAtFirst(int data)
{
    cout << "Insert at first: " << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty...!" << endl;
        return;
    }
    // Linked the newNode to head and change the head to newNode
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// insert node in between in Linked list
void LinkedList::insertInBetween(int nodeOffset, int data)
{
    cout << "Inserting a Node at " << nodeOffset << " and data is " << data << endl;
    Node *temp = head;
    Node *newNode = new Node(data);
    int lengthCounter = 0;

    while (temp != NULL)
    {
        lengthCounter++;
        temp = temp->next;
    }
    if (lengthCounter < 2)
    {
        cout << "You can't insert A Node in Between...!" << endl;
        return;
    }
    // Reset temp
    temp = head;
    int i = 1;
    // while(nodeOffset-- > 1)
    while (i++ < nodeOffset)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert a node at last / or new Node
void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);
    // newNode->next = NULL; | it is done by constructor of Class-Node

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Here index is starting from the 1
void LinkedList::deleteNode(int nodeOffset)
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL)
    {
        cout << "List is empty...!" << endl;
        return;
    }

    // Calculate the length of List
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset)
    {
        cout << "Index out of range...!" << endl;
    }
    // Set temp1 = head again
    temp1 = head;
    if (nodeOffset == 1)
    {
        head = head->next;
        delete temp1;
    }
    while (nodeOffset-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;

    delete temp1;
}

void LinkedList::traverseList()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "\nLinked list is Empty...!";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << '\t';
        temp = temp->next;
    }
    cout << endl;
    return;
}

// command line argument
int main(int argc, char **argv)
{
    LinkedList list;
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);
    list.insertNode(50);

    list.traverseList();

    list.deleteNode(2);
    list.insertInBetween(2, 20);
    list.insertAtFirst(1000);
    list.traverseList();

    return 0;
}
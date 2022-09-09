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
int list_length_counter = 0;
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
    // Linked the newNode to head and change the head to newNode
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    list_length_counter++;
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
    list_length_counter++;
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
    list_length_counter++;
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

void __LIST__main(){
    LinkedList list;
    int choice, data, index;
    char ch;
    do{
        cout << "\n-----------Menu-----------\n" << endl;
        cout << "1.Insert at front " << endl;
        cout << "2.Insert at the end" << endl;
        cout << "3.Insert at Middle" << endl;
        cout << "4.Delete at front" << endl;
        cout << "5.Delete at end" << endl;
        cout << "6.Delete at middle" << endl;
        cout << "7.Display linked list " << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice ;
        switch(choice)
        {
        case 1:
            cout << "\nEnter the data: ";
            list.insertAtFirst(data);
            cin >> data;
            break;
        case 2:
            cout << "\nEnter the data: ";
            list.insertNode(list_length_counter);
            cin >> data;
            break;
        case 3:
            cout << "\nEnter the index and data: ";
            cin >> index >> data;
            list.insertInBetween(index, data);
            break;
        case 4:
            list.deleteNode(0);
            break;
        case 5:
            list.deleteNode(list_length_counter);
            break;
        case 6:
            cout << "\nEnter the index: ";
            cin >> index;
            list.deleteNode(index);
            break;
        case 7:
            cout << endl;
            list.traverseList();
            break;
        case 0:
            exit(0);
            break;
        }
        cout << "\nWant to Re-enter(y/Y): \n";
        cin >> ch ;
    }while(ch == 'y' || ch == 'Y');
}

// command line argument
int main(int argc, char **argv)
{
    // LinkedList list;
    // list.insertAtFirst(10);
    // list.insertNode(10);
    // list.insertNode(20);
    // list.insertNode(30);
    // list.insertNode(40);
    // list.insertNode(50);

    // list.traverseList();

    // list.deleteNode(list_length_counter);
    // // list.insertInBetween(2, 20);
    // // list.insertAtFirst(1000);
    // list.traverseList();
    __LIST__main();
    return 0;
}
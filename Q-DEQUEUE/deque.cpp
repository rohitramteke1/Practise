#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
        Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DeQueue{
    Node *head;
    public:
    DeQueue() : head(NULL) {}    
    void enQueue_front(int);
    void enQueue_back(int);

    void deQueue_front();
    void deQueue_back();
    void show();
};
// enQueue from back
void DeQueue::enQueue_back(int data){
    Node *newNode = new Node(data);
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
    // set previous
    newNode->prev = temp;

    // set next
    temp->next = newNode;
}

// enQueue from front
void DeQueue::enQueue_front(int data){
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void DeQueue::deQueue_front(){
    if (head == NULL)
    {
        cout << " Queue is empty: " << endl ;
        return;
    }
    Node *temp = head;
    // change the head
    head = head->next;

    // if there is only one Node
    if (head == temp)
    {
        cout << " Deleting head : " << endl ;
        cout << " deQueue_front->data: " << temp->data << endl;
        head = NULL;
        delete temp;
        return;
    }
    head->prev = NULL;
    cout << " deQueue_front->data: " << temp->data << endl;
    
    delete temp;
}

void DeQueue::deQueue_back(){
    if (head == NULL)
    {
        cout << " Queue is empty: " << endl ;
        return;
    }
    Node *temp = head;
    Node *temp2 = head->next;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    // if there is only one Node
    if (head == temp)
    {
        cout << " deQueue_back->data: " << temp->data << endl;
        head = NULL;
        delete temp;
        return;
    }
    temp2->next = NULL;
    cout << " deQueue_back->data: " << temp->data << endl;
    delete temp;
}

void DeQueue::show(){
    Node *temp = head;
    cout << "In Display function: " << endl ;
    if (head == NULL)
    {
        cout << "The Linked List is empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    // cout << endl ;
    // while (temp->prev != NULL)
    // {
    //     temp = temp->prev;
    //     cout << temp->data << ' ';
    // }
    cout << endl ;
}

int main()
{
    DeQueue dq;

    dq.enQueue_back(10);
    dq.enQueue_back(20);
    dq.enQueue_back(30);
    dq.enQueue_back(40);
    dq.enQueue_back(50);
    dq.enQueue_back(60);
    dq.show();

    dq.enQueue_front(70);
    dq.enQueue_front(80);
    dq.show();

    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_front();
    dq.deQueue_back();
    dq.show();

    return 0;
}
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

class DoublyCircularLinkedList{
    Node *head;
    public:
    DoublyCircularLinkedList() : head(NULL) {}
    void insertNode(int);
    void deleteNode(int);
    void traverse();
};

void DoublyCircularLinkedList::insertNode(int data){
    Node *newNode = new Node(data);
    Node *temp;
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }
    // set temp to head
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    // set next links
    newNode->next = head; // temp->next;
    temp->next = newNode;
    
    // set previous
    newNode->prev = temp;
    head->prev = newNode;
}

void DoublyCircularLinkedList::deleteNode(int nodeOffset){
    Node *temp = head ;
    Node *temp2 = head;
    int ListLen = 0;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp->next != head)
    {
        ++ListLen;
        temp = temp->next;
    }

    // cout << "ListLen: " << ListLen << endl;
    if (nodeOffset > ListLen+1)
    {
        cout << "Index of out range" << endl;
        return;
    }
    
    temp = head;
    temp2 = head;
    if (nodeOffset == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        head->prev = temp;
        delete temp2;
    }
    while (--nodeOffset > 1)
    {
        temp = temp->next;
    }
    temp2 = (temp->next)->next;
    temp->next = temp2;
    temp2->prev = temp; 
}


void DoublyCircularLinkedList::traverse(){
    Node *temp = head;
    if (head == NULL)
    {
        cout << "The List is empty: " << endl ;
        return;
    }
    do 
    {
        // temp = temp->prev;
        cout << temp->data << ' ';
        temp = temp->next;
    }while(temp != head);
    cout << endl ;
}

int main(){
    DoublyCircularLinkedList dl;

    dl.insertNode(1);
    dl.insertNode(2);
    dl.insertNode(3);
    dl.insertNode(4);
    dl.insertNode(5);
    dl.traverse();
    dl.deleteNode(5);
    dl.traverse();
    dl.deleteNode(5);
    dl.traverse();
    // dl.deleteNode(4);
    
    return 0;
}
#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node *head;
    public:
    Queue() : head(NULL) {}
    void push(int);
    void pop(); // int pop()
    void front(); // int front()
    void rear(); // int rear()
    void size(); // int size()
    void show();
};

void Queue::push(int data){
    Node *newNode = new Node(data);
    Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Queue::pop(){
    Node *temp = head;
    head = head->next;
    cout << temp->data << ' ' << endl ;
    delete temp;
}

void Queue::front(){
    cout << "front: " << head->data << ' ' << endl ;
}

void Queue::rear(){
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Rear: " << temp->data << ' ' << endl ;
}

void Queue::size(){
    Node *temp = head;
    int ListLen = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        ListLen++;
    }
    cout << "Size of list: " << ListLen << endl ;
}

void Queue::show(){
    Node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "List is empty: " << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << ' ' ;
        temp = temp->next;
    }
}
    

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.show();
    cout << endl ;

    q.pop();
    q.show();
    cout << endl ;

    q.pop();
    q.show();
    cout << endl ;
    
    q.front();
    q.rear();
    q.size();

    return 0;
}
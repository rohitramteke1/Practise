#include <iostream>
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

class Stack{
    Node *top;
    public:
    Stack() : top(NULL) {}
    void push(int);
    void pop();
    void show();
    void top_element();
};

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    if (top == NULL)
    {
        top = newNode;
        return;
    }
    // Node *temp = top;
    newNode->next = top;
    top = newNode;
}

void Stack::pop(){
    Node *temp = top;
    top = top->next;
    delete temp;
}
 
void Stack::show(){
    Node *temp = top;
    if (temp == NULL)
    {
        cout << "Stack Underflow...!!!" << endl ;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << '\n' ;
        temp = temp->next;
    }
}

void Stack::top_element(){
    cout << "Stack->top : " << top->data << '\n' ;
}

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.show();

    s.pop();
    cout << endl;
    s.show();
    s.top_element();
    return 0;
}
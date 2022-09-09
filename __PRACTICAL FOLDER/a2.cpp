#include <iostream>
#include <stdlib.h>
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
    void top_element();
    void show();
};

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    if (top == NULL)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void Stack::pop(){
    if (this->top != NULL)
    {
        Node *temp = top;
        top = top->next;
        cout << "  Stack->data: " << temp->data << " popped out" << endl;
        delete temp;
    }
    else
        cout << "Stack is Underflow..." << endl;
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

//
void __STACK__main(){
    Stack s;
    int choice, data;
    char ch;
    do{
        cout <<"\n------------------STACK-MENU------------------\nEnter the choice";
        cout << "\n  1.Push\n  2.Pop \n  3.Stack->top\n  4.Show\n  5.Exit()\n";
        cin >> choice ;
        switch(choice)
        {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top_element();
                break;
            case 4:
                s.show();
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong choice\n";
                break;
        }
        cout << "\nWant to enter more(y/Y)\n";
        cin >> ch ;
    }while(ch == 'y' || ch == 'Y');
}

int main(){
    __STACK__main();
    return 0;
}
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

struct Node* createNode(int data)  
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(Node *root){
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left); 
        preOrder(root->right);
    }
}

void postOrder(Node *root){
    if (root != NULL)
    {
        postOrder(root->left); 
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Node *root){
    if (root != NULL)
    {
        inOrder(root->left); 
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("PreOrder Traversal: ");
    preOrder(p);
    printf("\nPostOrder Traversal: ");
    postOrder(p);
    printf("\nInOrder Traversal: ");
    inOrder(p);

    return 0;
}
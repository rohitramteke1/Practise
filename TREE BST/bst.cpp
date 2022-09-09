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

bool isBST(Node *root){
    static Node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0; // false
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;// false
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
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
    Node *p = createNode(5);
    Node *p1 = createNode(3);
    Node *p2 = createNode(6);
    Node *p3 = createNode(1);
    Node *p4 = createNode(4);

    //      BST
    //      5
    //     / \
    //    3   6
    //   / \  
    //  1   4  

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("InOrder Traversal: ");
    inOrder(p);
    printf("\n%d", isBST(p));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    char color;
    struct node* left, * right, * parent;
} node;

typedef struct tree {
    node* root, * Nil;
} tree;

node* newNode(int data) {
    node* Node = (node*)malloc(sizeof(node));
    Node->data = data;
    Node->color = 'R';
    Node->left = NULL;
    Node->right = NULL;
    Node->parent = NULL;
    return Node;
}

void checkSwitch(tree* binaryTree, node* checkNode) {
    node* child = (node*)malloc(sizeof(node));
    child = checkNode->left;
    checkNode->left = child->right;
    if (checkNode->left != binaryTree->Nil)
        checkNode->left->parent = checkNode;

    child->parent = checkNode->parent;
    if (checkNode == checkNode->parent->left)
        checkNode->parent->left = child;
    else if (checkNode == checkNode->parent->right)
        checkNode->parent->right = child;
    else
        binaryTree->root = child;
    
    child->right = checkNode;
    checkNode->parent = child;
}

void check(tree* binaryTree, node* checkNode) {
    node* uncle = (node*)malloc(sizeof(node));
    node* child = (node*)malloc(sizeof(node));
    while (checkNode->parent->color == 'R') {
        if (checkNode->parent == checkNode->parent->parent->left) {
            uncle = checkNode->parent->parent->right;
            if (uncle->color == 'B') {
                if (checkNode == checkNode->parent->right) {
                    checkNode = checkNode->parent;
                    child = checkNode->right;
                    checkNode->right = child->left;
                    if (checkNode->right != binaryTree->Nil)
                        checkNode->right->parent = checkNode;

                    child->parent = checkNode->parent;
                    if (checkNode == checkNode->parent->left)
                        checkNode->parent->left = child;
                    else if (checkNode == checkNode->parent->right)
                        checkNode->parent->right = child;
                    else
                        binaryTree->root = child;

                    child->left = checkNode;
                    checkNode->parent = child;
                }
                checkNode->parent->color = 'B';
                checkNode->parent->parent->color = 'R';
                checkSwitch(binaryTree, checkNode->parent->parent);
            }
            else {
                uncle->color = 'B';
                checkNode->parent->color = 'B';
                checkNode->parent->parent->color = 'R';
                checkNode = checkNode->parent->parent;
            }
        }
        else {
            uncle = checkNode->parent->parent->left;
            if (uncle->color == 'B') {
                if (checkNode == checkNode->parent->left) {
                    checkNode = checkNode->parent;
                    child = checkNode->left;
                    checkNode->left = child->right;
                    if (checkNode->left != binaryTree->Nil)
                        checkNode->left->parent = checkNode;

                    child->parent = checkNode->parent;
                    if (checkNode == checkNode->parent->left)
                        checkNode->parent->left = child;
                    else if (checkNode == checkNode->parent->right)
                        checkNode->parent->right = child;
                    else
                        binaryTree->root = child;

                    child->right = checkNode;
                    checkNode->parent = child;
                }
                checkNode->parent->color = 'B';
                checkNode->parent->parent->color = 'R';
                checkNode->parent->parent->right = child->left;
                if (checkNode->parent->parent->right != binaryTree->Nil)
                    checkNode->parent->parent->right->parent = checkNode->parent->parent;

                child->parent = checkNode->parent->parent->parent;
                if (checkNode->parent->parent == checkNode->parent->parent->parent->left)
                    checkNode->parent->parent->parent->left = child;
                else if (checkNode->parent->parent == checkNode->parent->parent->parent->right)
                    checkNode->parent->parent->parent->right = child;
                else
                    binaryTree->root = child;

                child->left = checkNode->parent->parent;
                checkNode->parent->parent->parent = child;
            }
            else {
                uncle->color = 'B';
                checkNode->parent->color = 'B';
                checkNode->parent->parent->color = 'R';
                checkNode = checkNode->parent->parent;
            }
        }
    }
    binaryTree->root->color = 'B';
}

void insert(tree* binaryTree, node* insertNode) {
    node* nullLeaf = (node*)malloc(sizeof(node));
    node* temp = (node*)malloc(sizeof(node));

    nullLeaf = binaryTree->Nil;
    temp = binaryTree->root;

    while (temp != binaryTree->Nil) {
        nullLeaf = temp;
        if (insertNode->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    insertNode->parent = nullLeaf;

    if (nullLeaf == binaryTree->Nil)
        binaryTree->root = insertNode;
    else if (insertNode->data < nullLeaf->data)
        nullLeaf->left = insertNode;
    else
        nullLeaf->right = insertNode;

    insertNode->color = 'R';
    insertNode->left = binaryTree->Nil;
    insertNode->right = binaryTree->Nil;
    check(binaryTree, insertNode);
}

void inorder(node* NIL, node* checkNode) {
    if (checkNode != NIL) {
        inorder(NIL, checkNode->left);
        printf("%2d-%c   ", checkNode->data, checkNode->color);
        inorder(NIL, checkNode->right);
    }
}

void preorder(node* NIL, node* checkNode) {
    if (checkNode != NIL) {
        printf("%2d-%c   ", checkNode->data, checkNode->color);
        preorder(NIL, checkNode->left);
        preorder(NIL, checkNode->right);
    }
}

void postorder(node* NIL, node* checkNode) {
    if (checkNode != NIL) {
        postorder(NIL, checkNode->left);
        postorder(NIL, checkNode->right);
        printf("%2d-%c   ", checkNode->data, checkNode->color);
    }
}

int main() {
    tree* result = (tree*)malloc(sizeof(tree));
    node* NIL = (node*)malloc(sizeof(node));

    NIL->data = 'null';
    NIL->color = 'B';
    NIL->left = NULL;
    NIL->right = NULL;
    NIL->parent = NULL;
    result->root = NIL;
    result->Nil = NIL;

    insert(result, newNode(41));
    insert(result, newNode(38));
    insert(result, newNode(31));
    insert(result, newNode(12));
    insert(result, newNode(19));
    insert(result, newNode(8));

    // inorder(result, result->root);
    printf("in-order traversal\n>> ");
    inorder(NIL, result->root);
    printf("\n\npre-order traversal\n>> ");
    preorder(NIL, result->root);
    printf("\n\npost-order traversal\n>> ");
    postorder(NIL, result->root);
    printf("\n");
    return 0;
}

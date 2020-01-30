#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    struct Node *left;
    struct Node *right;
} Node;

Node *head;

void push(int index) {
    Node *node = head;
    Node *prenode;
    if(head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->index = index;
        head->left = NULL;
        head->right = NULL;
        return;
    }
    
    while(node != NULL) {
        if(node->index < index) {
            prenode = node;
            node = node->right;
        } else if(node->index > index) {
            prenode = node;
            node = node->left;
        } else {
            printf("이미 존재하는 노드입니다.\n");
            return;
        }
    }
    if(prenode->index < index) {
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        prenode->right = node;
    } else if(node->index > index) {
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        prenode->left = node;
    }
}

void BinarySearch(int index) {
    Node *node = head;
    while(node->index == index || node != NULL) {
        if(node->index < index) {
            node = node->right;
        } else if(node->index > index) {
            node = node->left;
        }
    }
    if(node->index == index) {
        printf("%d값은 존재합니다.\n", index);
    } else {
        printf("%d값은 존재하지 않습니다.\n", index);
    }
}

void bs(Node *node, int index) {
    if(node->left != NULL)
        bs(node->left, index);
    if(node->right != NULL)
        bs(node->right, index);
    if(node->index == index) {
        printf("%d값은 존재합니다.\n", index);
    } else {
        printf("%d값은 존재하지 않습니다.\n", index);
    }
}

int main(void) {
    
    printf("%d push.\n", 3);
    push(3);
    printf("%d push.\n", 5);
    push(5);
    printf("%d push.\n", 7);
    push(7);
    // BinarySearch(5);
    // BinarySearch(4);
    bs(head, 5);
    bs(head, 4);
    
    system("pause");
    return 0;
}

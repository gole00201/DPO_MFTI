#include <stdio.h>
#include <stdlib.h>


typedef int datatype;
typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

/* Чисто чтобы стеком решить. Быстрее пишется*/
typedef struct levelNode {
    tree *node;
    int level;
} levelNode;

tree* newNode(datatype key) {
    tree *node = (tree *)malloc(sizeof(tree));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void btUpView(tree *root) {
    if (root == NULL) return;

    int maxLevel = 0;
    int levelSeen[1000] = {0};
    tree* rightMostNode[1000] = {NULL};
    levelNode stack[1000];
    int top = -1;
    stack[++top] = (levelNode){root, 0};
    while (top >= 0) {
        levelNode current = stack[top--];
        tree *node = current.node;
        int level = current.level;
        if (node == NULL) continue;

        if (level > maxLevel) {
            maxLevel = level;
        }
        rightMostNode[level] = node;
        levelSeen[level] = 1;
        if (node->right) {
            stack[++top] = (levelNode){node->right, level + 1};
        }
        if (node->left) {
            stack[++top] = (levelNode){node->left, level + 1};
        }
    }
    for (int i = 0; i <= maxLevel; i++) {
        if (levelSeen[i]) {
            printf("%d ", rightMostNode[i]->key);
        }
    }
    printf("\n");
}

// Пример
int main() {
    tree *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(13);
    root->right->right = newNode(18);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(6);

    btUpView(root);
    return 0;
}

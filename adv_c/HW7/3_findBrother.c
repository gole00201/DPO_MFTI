tree *findBrother(tree *root, int key) {
    if (root == NULL) return NULL;

    tree *target = NULL;
    tree *stack[100];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        tree *node = stack[top--];
        if (node->key == key) {
            target = node;
            break;
        }
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    if (target == NULL) return NULL;

    if (target->parent == NULL) return NULL;
    tree *parent = target->parent;
    if (parent->left == target) {
        return parent->right; // Брат 1
    } else {
        return parent->left; // Брат 2 ( так себе фильм ИМХО )
    }
}

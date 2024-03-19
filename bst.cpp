#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *left, *right;
};

struct node* init(int v){
    struct node* n = new struct node;
    n->value = v;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node* insert(struct node* node, int v){
    if (node == NULL)
        return init(v);

    if (v < node->value)
        node->left = insert(node->left, v);
    else  if (v > node->value)
        node->right = insert(node->right, v);

    return node;
}

struct node* search(struct node* root, int v)
{
    if (root == NULL || root->value == v)
        return root;

    if (root->value < v)
        return search(root->right, v);

    return search(root->left, v);
}

void inorder(struct node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void preorder(struct node* node) {
    if (node == NULL)
        return;

    cout << node->value << " ";
    preoder(node->left);
    preorder(node->right);
}

void postorder(struct node* node) {
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

int main(){
    return 0;
}


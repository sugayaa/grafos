#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *left, *right;
};

struct node* init(int v){
    struct node* n = new struct node();
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

struct node* deletenode(struct node* root, int v) {
    if (root == NULL) {
        return root;
    }

    if (root->value > v) {
        root->left = deletenode(root->left, v);
        return root;
    } else if (root->value < v) {
        root->right = deletenode(root->right, v);
        return root;
    }

    // found deletion node
    if (root->left == NULL) {
        struct node* tmp = root->right;
        delete root;
        return tmp;
    } else if (root->right == NULL) {
        struct node* tmp = root->left;
        delete root;
        return tmp;
    } else {
        struct node* succParent = root;

        struct node* succ =  root->right;
        // looking for the smaller value node
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root) {
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }

        // we swap the root value with the sucessor value
        // and delete the node where the sucessor was
        root->value = succ->value;

        delete succ;
        return root;
    }
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
    preorder(node->left);
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


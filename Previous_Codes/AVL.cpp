#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
    int height;
    Node(int value) {
        data = value;
        height = 0;
    }
};

int Height(Node* n) {
    if (!n) return -1;
    return n->height;
}

int balanceFactor(Node* n) {
    if (!n) return 0;
    return Height(n->left) - Height(n->right);
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(Height(x->left), Height(x->right));
    y->height = 1 + max(Height(y->left), Height(y->right));

    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(Height(y->left), Height(y->right));
    x->height = 1 + max(Height(x->left), Height(x->right));

    return x;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(Height(node->left), Height(node->right));
    int bf = balanceFactor(node);

    if (bf > 1 && key < node->left->data)
        return rightRotate(node);
    if (bf < -1 && key > node->right->data)
        return leftRotate(node);
    if (bf > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    root->height = 1 + max(Height(root->left), Height(root->right));
    int bf = balanceFactor(root);

    // Left Left
    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
    // Left Right
    if (bf > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Right
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);
    // Right Left
    if (bf < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void levelOrder2(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
            } else {
                break;
            }
            continue;
        }

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Level Order before deletion:\n";
    levelOrder2(root);

    root = deleteNode(root, 30);

    cout << "\n\nLevel Order after deleting 30:\n";
    levelOrder2(root);

    return 0;
}

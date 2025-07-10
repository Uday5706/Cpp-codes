#include <iostream>
#include <stack>
#include <cctype> // for isalpha or isdigit
using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Build expression tree from prefix string (no spaces)
Node* buildTreeFromPrefix(const string& prefix) {
    stack<Node*> st;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char token = prefix[i];
        Node* node = new Node(token);
        if (isOperator(token)) {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
        }
        st.push(node);
    }
    return st.top();
}

void inorder(Node* root) {
    if (!root) return;
    if (isOperator(root->val)) cout << "(";
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
    if (isOperator(root->val)) cout << ")";
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}

int main() {
    string prefix;
    cout << "Enter prefix expression (no spaces): ";
    cin >> prefix;

    Node* root = buildTreeFromPrefix(prefix);

    cout << "Inorder (Infix): ";
    inorder(root);
    cout << "\nPreorder (Prefix): ";
    preorder(root);
    cout << "\nPostorder (Postfix): ";
    postorder(root);
    cout << endl;

    return 0;
}

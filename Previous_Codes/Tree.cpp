#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;  
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if (preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node* root){
    if (root == NULL)return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if (root == NULL)return;
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}

void postOrder(Node* root){
    if (root == NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}

void levelOrder1(Node* root){
    queue<Node*> q;
    q.push(root);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();

        cout<< curr->data << endl;

        if(curr->left){
            q.push(curr->left);
        }
        if (curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

void levelOrder2(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();

        if (curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        
        cout<< curr->data << endl;

        if(curr->left){
            q.push(curr->left);
        }
        if (curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

int main(){
    vector<int> preorder = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7 ,-1,-1};
    Node* root = buildTree(preorder);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder1(root);
    return 0;
}
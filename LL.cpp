#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int value,Node* nextNode){
        data = value;
        next=nextNode;
    };
};

void trial(){
    Node x = Node(2,nullptr);
    Node* y =&x;
    //OR
    Node *newNode = new Node(2,nullptr);
    cout<<x.data<<" "<<y->data <<" "<< newNode->data;
}

int main() {
    trial();
    return 0;
}
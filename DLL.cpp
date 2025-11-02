#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    // Node (int value,Node* nextNode){
    //     data = value;
    //     next=nextNode;
    // };
    // Node (int value){
    //     data = value;
    //     next=nullptr;
    // };
    //OR
    Node(int value, Node* nextNode = nullptr, Node* prevNode = nullptr) : data(value), next(nextNode),prev(prevNode) {}
};

Node* cnvrtArrToDLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for ( int i=1; i<n;i++){
        Node* newNode= new Node(arr[i],NULL,prev);
        prev->next=newNode;
        prev=prev->next;
    }
    return head;
}

void Traverse(Node* head) {
    if (!head) return;
    Node* temp = head; //always make a copy of head
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseTraverse(Node* head) {
    if (!head) return;
    Node* temp = head; //always make a copy of head
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout << endl;
}

Node* deleteHead(Node* head){
    if (!head)return head;
    if (!head->next){
        delete head;
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->prev=NULL;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if (!head)return head;
    if (!head->next){
        delete head;
        return NULL;
    }
    Node* temp=head;
    while (temp->next){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    if (!head)return NULL;
    if (k==0) return deleteHead(head);
    int i=1;
    Node* temp = head->next;
    while (temp){
        if (i==k){
            if (temp->next){
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return head;
            }else{
                temp->prev->next=NULL;
                delete temp;
                return head;
            }
        }
        i++;
        temp=temp->next;
    }
    return head;
}

void deleteNode(Node*& head, Node* deletedNode){
    //Condition : we are not deleting head
    if (deletedNode->next){
        deletedNode->prev->next = deletedNode->next;
        deletedNode->next->prev=deletedNode->prev;
    }else  {
        deletedNode->prev->next = NULL; 
    }
    delete deletedNode;   
}

Node* insertHead(Node* head, int value){
    if (!head) return new Node(value,nullptr,nullptr);
    head->prev = new Node(value,head,nullptr);
    head=head->prev;
    return head;
}

Node* insertBeforeTail(Node* head, int value){
    if (!head) return new Node(value,nullptr,nullptr);
    Node* tail = head;
    while (tail->next){
        tail=tail->next;
    }
    if (tail->prev){
        Node* newNode = new Node(value,tail,tail->prev);
        tail->prev->next = newNode;
        tail->prev = newNode;
        return head;
    }else{
        tail->prev = new Node(value,tail,nullptr);
        head = tail->prev;
        return head;
    }
}

Node* insertBeforeKth(Node* head, int k, int value){
    if (k==0) return insertHead(head,value);
    Node* temp = head;
    int i=0;
    while (temp){
        if (i==k){
            Node* newNode = new Node(value,temp,temp->prev);
            temp->prev->next= newNode;
            temp->prev = newNode;
            return head;
        }
        i++;
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeNode(Node* head, Node* temp,int value){
    Node* prevNode = temp->prev;
    prevNode->next = new Node(value,temp,prevNode);
    temp->prev = prevNode->next;
    return head;
}

void reverseDLL(Node*& head){
    //Brute: T=O(2n) & S=O(n) store all value in stack while traversing and then again traverse, while poping and assigning the top to node
    //Better: T=O(n) reverse prev and next of every node 
    if (!head)return ;
    Node* temp = head;
    Node* back = nullptr;
    while (temp){
        back=temp->prev;
        temp->prev= temp->next;
        temp->next = back;
        temp=temp->prev; //actually in front of it
    } 
    head= back->prev;
}

Node* deleteAllOcc(Node* head, int key){
    if (!head) return NULL;

    Node* dummy = new Node(-1);
    dummy->next = head;
    head->prev = dummy;
    
    Node* curr = head;

    while (curr){
        if (curr->data==key){
            Node* prev = curr->prev;
            Node* next = curr->next;

            prev->next = next;
            if (next) next->prev = prev;

            delete curr;
            curr = next; // move to next node
        }
        else{
            curr = curr->next;
        }
    }
    Node* newHead = dummy->next;
    if (newHead) newHead->prev = NULL;
    delete dummy;

    return newHead;
}

int pairsWithGivenSum(Node* head, int sum){
    //Brute: T=O(n^2) & S=O(1) using 2 loops
    //Better: T=O(n) & S=O(n) using hashing how ? store all in set and then for each node check if sum-node->data is present in set or not
    //Optimal: T=O(n) & S=O(1) using 2 pointers
    if (!head || !head->next) return 0;
    Node* tail = head;
    while (tail->next){
        tail=tail->next;
    }
    Node* front = head;
    int cnt=0;

    while (front->data<tail->data){ // why 
        int currSum = front->data + tail->data;
        if (currSum==sum){
            cnt++;
            front=front->next;
            tail=tail->prev;
        }else if (currSum<sum){
            front=front->next;
        }else{
            tail=tail->prev;
        }
    }
    return cnt;
}

Node* removeDuplicates(Node* head){
    // Advantage : duplicates are consecutive
    if (!head || !head->next) return head;
    Node* curr = head;
    while (curr && curr->next){
        Node* nextNode = curr->next;
        while (nextNode && nextNode->data==curr->data){
            Node* temp = nextNode;
            nextNode=nextNode->next;
            delete temp;
        }
        curr->next = nextNode;
        if (nextNode) nextNode->prev = curr;
        curr = curr->next;
    }
    return head;
}



int main() {
    int arr[] = {3,2,1,6,5,4,9,8,7,10,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = cnvrtArrToDLL(arr, n);
    Traverse(head);
    Traverse(head);
    return 0;
}
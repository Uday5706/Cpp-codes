#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    // Node (int value,Node* nextNode){
    //     data = value;
    //     next=nextNode;
    // };
    // Node (int value){
    //     data = value;
    //     next=nullptr;
    // };
    //OR
    Node(int value, Node* nextNode = nullptr, Node* prevNode = nullptr) : data(value), next(nextNode) {}
};

struct childNode{
    int data;
    childNode* next;
    childNode* child;
    // Node (int value,Node* nextNode){
    //     data = value;
    //     next=nextNode;
    // };
    // Node (int value){
    //     data = value;
    //     next=nullptr;
    // };
    //OR
    childNode(int value, childNode* nextNode = nullptr, childNode* childNode = nullptr) : data(value), next(nextNode), child(childNode) {}
};

struct randomNode{
    int data;
    randomNode* next;
    randomNode* random;
    // Node (int value,Node* nextNode){
    //     data = value;
    //     next=nextNode;
    // };
    // Node (int value){
    //     data = value;
    //     next=nullptr;
    // };
    //OR
    randomNode(int value, randomNode* nextNode = nullptr, randomNode* randomNode = nullptr) : data(value), next(nextNode), random(randomNode) {}
};
 
class node{
    int data;
    node* next;

public:
    node (int value, node* nextNode){
        data = value;
        next=nextNode;
    }
    node (int value){
        data = value;
        next=nullptr;
    }
};

void trial(){
    Node x = Node(2,nullptr);
    Node* y =&x;
    //OR
    Node *newNode = new Node(2);
    cout<<x.data<<" "<<y->data <<" "<< newNode->data;
    node X = node(2,nullptr);
    node* Y =&X;
    //OR
    node *Newnode = new node(2);
    // cout<<Y->data<<Newnode->data; Error
}
Node* cnvrtArrToCircularLL(int arr[],int n, int k=0){
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i=1;i<k;i++){
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Node* head2 = new Node(arr[k]);
    temp->next=head2;
    temp = head2;
    for (int i=k+1;i<n;i++){
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    temp->next=head2; //making circular
    return head;
}

Node* cnvrtArrToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i=1;i<n;i++){
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

void Traverse(Node* head) {
    Node* temp = head; //always make a copy of head
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseTraverse(Node* head) {
    if (!head) return; //always make a copy of head
    reverseTraverse(head->next);
    cout<<head->data<<" ";
}

int Length(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
} 

int search(Node* head, int key) {
    Node* temp = head; 
    // O(n)
    while (temp != nullptr) {
        if (temp->data == key) {
            return 1;  // Key found
        }
        temp = temp->next;
    }
    return 0;  // Key not found
}

void printHead(Node* head){
    if (head==nullptr)return;
    cout<< head->data<<endl;
}

int valueOfKthNode(Node* head, int k){
    if (!head)return -1;
    int i=0;
    Node* temp=head;
    while (temp){
        if (i==k) return temp->data;
        i++;
        temp=temp->next;
    }
    return -1;
}

Node* removeHead(Node* head){
    if (head==NULL || head->next == NULL)return NULL;
    Node* temp = head;
    head=head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){ 
    // or make a void function and use Node*& head in parameter
    if (head==NULL || head->next == NULL)return NULL;
    Node* temp = head;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

void deleteKthNode(Node*& head, int k){
    if (head==NULL)return;
    int i=0;
    if (k==0) {
        head = removeHead(head);
        return;
    }
    Node* temp=head;
    Node* prev=NULL;
    while (temp){
       if (i==k){
        prev->next=prev->next->next;
        delete temp;
        return;
       }
        i++;
        prev=temp;
        temp=temp->next;
    }
    return;
}

Node* deleteNode(Node* node) { //node is not tail
    //T=O(1) copy form next node and then delete front node
    node->data=node->next->data;
    Node* temp = node->next->next;
    delete node->next;
    node->next=temp;
}

void deleteEl(Node*& head, int key){
    if (head==NULL)return;
    Node* temp=head;
    if (head->data==key){
        head=head->next;
        delete temp;
        return;
    }
    Node* prev=NULL;
    while (temp){
       if (temp->data==key){
        prev->next=prev->next->next;
        delete temp;
        return;
       }
       prev=temp;
       temp=temp->next;
    }
    return;
}

void insertHead(Node*& head, int key){
    head = new Node(key,head);
}

void insertTail(Node*& head, int key){
    if (!head){
        head = new Node(key);
        return;
    }
    Node* temp= head;
    while (temp->next){
        temp=temp->next;
    }
    temp->next=new Node(key);
}

void insertAtK(Node*& head,int k, int key){
    if (k==0){
        insertHead(head,key);
        return;
    }
    int i=1;
    Node* prev =head;
    while(prev){
        if (i==k){
            Node* newNode = new Node(key);
            newNode->next=prev->next;
            prev->next=newNode;
        }
        i++;
        prev=prev->next;
    }
    return;
}

void insertBeforeX(Node*& head, int el, int x){
    if (!head)return;
    if (head->data==x){
        head=new Node(el,head);
        return;
    }
    Node* temp = head;
    while (temp->next){
        if (temp->next->data==x){
            temp->next=new Node(el,temp->next);
            return;
        }
        temp=temp->next;
    }
}

Node* middleEle(Node* head){
    //Brute: T=O(n+n/2) Finding length (n) of DLL and then again traverse n/2+1 to get middle ele(in case of even return one on right side)
    //Best: T=O(n/2) by making two pointer where traversal speed of one is double o f other so nodes traveled wil be half
    Node* fast =head;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverseLL(Node* head){
    //Brute : T=O(2n) & S=O(n) Using Stack to get data in reverse order and then again traversing and chnaging data acc top
    //Optimal: T=O(n) & S=O(1) creating 3 pointers one for traversal and two for swapping behind the traversal one
    if (!head) return head;
    Node* prev = nullptr;   // previous node
    Node* curr = head;      // current node
    Node* next = nullptr;   // next node
    while (curr) {
        next = curr->next;   // save next
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev one step forward
        curr = next;         // move curr one step forward
    }
    return prev;  // update head to new first node
}
void reverseLLRec(Node*& head, Node* curr, Node* prev = nullptr) {
    if (!curr) {
        head = prev;  // new head is the last non-null node
        return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverseLLRec(head, next, curr);
}
Node* reverseLLRec(Node* head) {
    //T=O(n) & S=O(n)
    // Base case: empty list or single node
    if (!head || !head->next) return head;

    Node* newHead = reverseLLRec(head->next);

    head->next->next = head;  // reverse link
    head->next = nullptr;     // break old link

    return newHead;
}

bool detectLoop(Node* head){
    //Brute: T=O(n) & S=O(n) using hash set to store visited nodes
    //Optimal: T=O(n) & S=O(1) using Floyd's Cycle-Finding Algorithm (Tortoise and Hare Algorithm)
    if (!head || !head->next) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;  // loop detected
        //It is sure they will meet as distance between them is decreasing by 1 in each iteration in a loop
    }
    return false;
}
Node* startingNodeOfLoop(Node* head){
    //brute: T=O(n) & S=O(n) using hash set to store visited nodes & return first repeated node
    //optimal: T=O(n) & S=O(1) using Floyd's Cycle-Finding Algorithm (Tortoise and Hare Algorithm)
    if (!head || !head->next) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head; // Move slow to head
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr; // No loop
}

int lengthOfLoop(Node* head){
    //Brute: T=O(n) & S=O(n) using hash map to store visited nodes and timer with them & return timer-timer of first repeated node
    //Optimal: T=O(n) & S=O(1) using Floyd's Cycle-Finding Algorithm (Tortoise and Hare Algorithm)
    if (!head || !head->next) return 0;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int count = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0; // No loop
}

bool palindromeLL(Node* head){
    //Brute :T=O(2n) & S=O(n) Inserting all nodes data in stack and then again traverse and check if temp->data==stack.top each time.If false return false, if true all over return true at last.

    //Optimal: T=O(2n) & S=O(1) Find the middle element and then reverse LL aftre it and then traverse both half step by step and after reaching conclusion reverse the mid half again and then return the answer
    if (!head || !head->next)return true;
    Node* first = head;
    Node* slow=head;
    Node* fast = head;
    while (fast->next && fast->next->next ){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* second = newHead;
    while (second!=NULL){
        if (second->data!=first->data){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
}

Node* oddEvenList(Node* head) {
    //Brute: T=O(2n) & S=O(n) Using extra space to store odd and even nodes value in a array separately and then again traverse and change data acc to odd even array
    //Optimal: T=O(n) & S=O(1) by making two pointers one for odd and other for even and then at last joining odd list with even list
    if (!head || !head->next || !head->next->next)return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while (even && even->next){
        odd->next = odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

Node* removekthNodeFromEnd(Node* head, int k){
    // if (!head)return head;
    // if (k==1){
    //     return removeTail(head);
    // }
    // Node* start = head;
    // Node* end = NULL;
    // Node* mid = NULL;
    // while (start!=end){
    //     int cnt=1;
    //     int n=0;
    //     Node* slow= start;
    //     Node* fast= start;
    //     while (fast!=end && fast->next!=end){
    //         slow=slow->next;
    //         fast=fast->next;
    //         n++;
    //     }
    //     Node* mid = slow;
    //     if (fast!=end) n=2*cnt-1;
    //     else n= 2*(cnt-1);
    //     if (n-cnt+1==k){
    //         deleteNode(slow); //can't remove tail
    //         return head;
    //     }else if (n-cnt+1<k){
    //         k-=n-cnt+1;
    //         end = slow;
    //     }else {
    //         start = slow->next;
    //     }
    // }
    // return head;
    //OR
    //Brute : T=O(2n) First calculate length n and then check if n==k then newHead = head->next; if not then traverse again traverse n-k and then delete k th node from that position.

    //Optimal : T=O(n) set distnace between two pointer a distance of k and then when front pointer reaches the back pointer points to back of kth node from end and then you can delete it.
    if (!head) return NULL;

    Node* dummy = new Node(0); // helps when head itself is deleted
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    // Move fast k+1 steps so gap between slow and fast is k
    for (int i = 0; i <= k; i++) {
        if (!fast) return head; // k > length → do nothing
        fast = fast->next;
    }

    // Move both until fast hits the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow is now before the target node
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

Node* deleteMiddleNode(Node* head){
    //Brute: T=O(n+ n/2) Find length O(n) and then traverse n/2 to delete it.
    //Optimal : T=O(n/2) Find mid by tortoise and hare algo and then delete it.
    if (!head || !head->next)return NULL;
    Node* slow = head;
    Node* fast = head->next->next;
    while (fast && fast->next){
        slow=slow->next;
        fast = fast->next->next;
    }
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}

Node* merge(Node* L1, Node* L2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while (L1 && L2){
        if (L1->data<L2->data){
            temp->next = L1;
            temp=L1;
            L1=L1->next;
        }else{
            temp->next = L2;
            temp=L2;
            L2=L2->next;
        }
    }
    if (!L1)temp->next=L2;
    else temp->next = L1;
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}
Node* mergeMid(Node* head){
    Node* slow= head;
    Node* fast = head->next;
    while (fast && fast->next){
        slow=slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSrt(Node* head){
    //T=O(nlogn) & S=O(logn) //recursion stack space
    if (!head || !head->next)return head;
    Node* mid = mergeMid(head);
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next=NULL;
    leftHead = mergeSrt(leftHead);
    rightHead = mergeSrt(rightHead);
    return merge(leftHead,rightHead);
}

Node* srt0s1s2s(Node* head){
    //Brute: T=O(2n) Two traversals one for counting 0's,1's and 2's and then assigning in linked list till that counts of respective numbers become 0
    //Optimal: T=O(n) By Link Chnage method and forming three LL for 0 ,1 and 2 & then joining them
    if (!head || !head->next)return head;
    Node* zeroHead = new Node(-1), *zeroTail = zeroHead;
    Node* oneHead  = new Node(-1), *oneTail  = oneHead;
    Node* twoHead  = new Node(-1), *twoTail  = twoHead;

    Node* temp = head;
    while (temp){
        if (temp->data==0){
            zeroTail->next=temp;
            zeroTail=zeroTail->next;
        }else if (temp->data==1){
            oneTail->next=temp;
            oneTail=oneTail->next;
        }else{
            twoTail->next=temp;
            twoTail=twoTail->next;
        }
        temp=temp->next;
    }

    zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    Node* newHead = zeroHead->next;
    
    // free dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

Node* findIntersectionPoint(Node* L1, Node* L2) {
    // Brute: T=O(n1+n2) & S=O(max(n1,n2)) in case of using unordered map and inserting all nodes of l1 in map and then finding each node of l2 in  map if found then found intersection point otherwise doesn't exist.

    //Better: T=O(n1+2n2) & S=O(1) find length from both heads (n1,n2) and move temp |n1-n2| in longer one so that both are vertical up down and then move both temps till they are equal or terminate to null

    //Optimal: T=O(n1+n2) & S=O(1)
    if (!L1 || !L2) return NULL;
    Node* p1 = L1;
    Node* p2 = L2;
    while (p1 != p2) {
        p1 =p1->next;
        p2 = p2->next;
        if (!p1) p1=L2;
        if (!p2) p2=L1;
    }
    return p1; // either intersection or NULL
}

int add1Rec(Node* head){
    if (!head) return 1;
    int carry = add1Rec(head->next);
    int sum = head->data +carry;
    if (sum>9){
        head->data=0;
        return 1;
    }
    else {
        head->data = sum;
        return 0;
    } 
}
Node* add1ToLL(Node* head){
    //T=O(n) & S=O(n) recursive Like 4 bit adder in DLD
    // int carry = add1Rec(head);
    // if (carry==1){
    //     insertHead(head,1);
    // }
    // return head;
    //OR T=O(3n) & S=O(1) iterative
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    int sum;
    while (temp){
        sum = temp->data +carry;
        if (sum>9){
            temp->data=0;
            carry= 1;
        }
        else {
            temp->data = sum;
            carry = 0;
            break;
        } 
        temp=temp->next;
    }
    head = reverseLL(head);
    if (carry==1)insertHead(head,1);
    return head;
}

Node* addTwoLLNum(Node* L1, Node* L2){ 
    //L1 and L2 are in reverse Order
    // T=O(max(n1,n2)) & S=O(max(n1,n2)) 
    if (!L1 && !L2)return NULL;
    else if (!L1) return L2;
    else if (!L2) return L1; 
    Node* dummy = new Node(-1);
    Node* temp=dummy;
    int carry=0,sum=0;
    while (L1 || L2 || carry){
        int d1 = L1 ? L1->data : 0;
        int d2 = L2 ? L2->data : 0;
        sum = d1+d2+carry;
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;

        if (L1) L1 = L1->next;
        if (L2) L2 = L2->next;
    }
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

Node* findKthNode(Node* head, int k){
    if (!head) return NULL;
    int cnt=0;
    Node* temp = head;
    while (temp){
        cnt++;
        if (cnt==k) return temp;  
        temp=temp->next;
    }
    return NULL;
}
Node* reverseLLKGrouped(Node* head, int k){
    //Best: T=O(2n) & S=O(1) reversing links of k nodes at a time and joining them
    // if (!head)return NULL;
    // Node* newHead=NULL;
    // Node* curr = head;
    // Node* prev = NULL;
    // Node* next = head->next;
    // int check=0;
    // Node* prevTail=NULL;
    // while (curr){
    //     int flag=0; //for checking if can reverse next group
    //     int n=0; //for counting members in next group
    //     Node* temp= curr; 
    //     while (temp && n<k){
    //         n++;
    //         temp=temp->next;
    //     }
    //     if (n==k)flag=1; //Next group has k members so reverse
    //     if (flag){
    //         int cnt=0; //for counting how many times reversing
    //         Node* first = curr; //to make it tail of that group after reversing
    //         while (curr && cnt<k){
    //             cnt++;
    //             curr->next=prev;
    //             prev=curr;
    //             curr=next;
    //             if (next)next=next->next;
    //         }
    //         first->next=curr; 
    //         if (prevTail){
    //             prevTail->next=prev;
    //         }
    //         if (!check){ //for getting the newHead when first time reversed
    //             newHead=prev;
    //             check=1;
    //         }
    //         prev=first; // now prev is first one
    //         prevTail=first;
    //     }else{
    //         break;
    //     }
    // }
    // return newHead;
    //OR simpler
    if (!head)return NULL;
    Node* currHead = head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;
    while(currHead){
        Node* kthNode = findKthNode(currHead,k);
        if (!kthNode){
            if (prevTail) prevTail->next=currHead;
            break;
        }
        Node* nextGroupHead = kthNode->next;
        kthNode->next = NULL;
        Node* reversedHead = reverseLL(currHead);
        if (!newHead) newHead = reversedHead;
        if (prevTail) prevTail->next = reversedHead;
        prevTail = currHead;
        currHead = nextGroupHead;
    }
    if (!newHead) newHead = currHead;
    return newHead;
}

Node* rotateLL(Node* head,int k){
    if (!head)return NULL;
    Node* front = head;
    Node* tail = NULL;
    int n=0;
    while (front){ //O(n)
        n++;
        if (!front->next)tail=front;
        front=front->next;
    }
    k=k%n;
    if (k==0)return head;
    front=head;
    for (int i=1;i<n-k;i++){ //O(n-k) getting n-k th node
        front=front->next;
    }
    Node* newHead=front->next;
    front->next=NULL;
    tail->next=head;
    return newHead;
}

childNode* spMerge(childNode* l1, childNode* l2){
    childNode* dummyNode = new childNode(-1);
    childNode* res = dummyNode;
    while(l1 && l2){
        if (l1->data < l2->data){
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }else{
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = NULL;
    }
    if (l1) res->child = l1;
    else res->child = l2;
    if (dummyNode->child) dummyNode->child->next=NULL;
    childNode* newHead = dummyNode->child;
    delete dummyNode;
    return newHead;
}
childNode* flattenLL(childNode* head){
    //Brute: T=O(2n*m+n*m*log(n+m)) & S=O(2n) traverse all nodes and save in arr and then sort it and then make a new LL of child ptrs conecting all nodes in srtd order.
    //Optimal: T=O(2*m*n)
    if (!head || !head->next)return head;
    childNode* mergedHead = flattenLL(head->next);
    head= spMerge(head,mergedHead);
    return head;
}

void insertCopyInBetween(randomNode* head){
    randomNode* temp = head;
    while(temp){
        randomNode* nextEle = temp->next;
        randomNode* copy = new randomNode(temp->data);

        copy->next = nextEle;
        temp->next= copy;

        temp = nextEle;
    }
}
void connectRandomPointers(randomNode* head){
    randomNode* temp= head;
    while (temp){
        randomNode* copyNode = temp->next;
        if (temp->random){
            copyNode->random=temp->random->next;
        }else{
            copyNode->random = NULL;
        }
        temp=temp->next->next;
    }
}
randomNode* getDeepCopyList(randomNode* head){
    randomNode* temp= head;
    randomNode* dummyNode = new randomNode(-1);
    randomNode* res = dummyNode;

    while(temp){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp=temp->next;
    }
    randomNode* newHead = dummyNode->next;
    delete dummyNode;
    return newHead;
}
randomNode* cloneLL(randomNode* head){
    //Brute: T=O(2n) and S=O(2n) storing (node, cpynode) in map and then again traversing so that cpynode->next/random = mpp[node->next/random] where cpynode = mpp[node];
    //Optimal: T=O(3n) & S=O(n)
    //1. inserting all copy nodes just after their real node in LL ie A → A' → B → B' → C → C'
    //2. connect random ptrs if cpynode is node->next and i do cpynode->random=node->random->next & do node.next.next;
    //3. connect next ptrs. For this make a dummy head for copy LL traverse res in it and temp in real LL evertime do res->next = temp->next and the temp->next=temp->next->next; then res and temp ko ek aage krdo
    if (!head) return NULL;
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = cnvrtArrToLL(arr, n);
    Traverse(head);
    head = rotateLL(head,5);
    Traverse(head);
    return 0;
}
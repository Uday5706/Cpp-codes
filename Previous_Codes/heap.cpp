#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int n;

        heap(){
            arr[0] = -1;
            n=0;
        }
    
        void insert(int val){

            n++;
            int index = n;
            arr[index] = val;

            while(index>1){
                int parent = index/2;

                if (arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for (int i =1;i<=n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void deleteFromHeap() {
            if (n == 0) {
                cout << "Nothing to delete" << endl;
                return;
            }
        
            // Move last element to root and reduce size
            arr[1] = arr[n];
            n--;
        
            int i = 1;
        
            while (i <= n) {
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;
                int maxIndex = i;
        
                // Check left child
                if (leftIndex <= n && arr[leftIndex] > arr[maxIndex]) {
                    maxIndex = leftIndex;
                }
        
                // Check right child
                if (rightIndex <= n && arr[rightIndex] > arr[maxIndex]) {
                    maxIndex = rightIndex;
                }
        
                // If parent is already bigger, heap is fine
                if (maxIndex == i) {
                    return;
                }
        
                // Otherwise, swap and move down
                swap(arr[i], arr[maxIndex]);
                i = maxIndex;
            }
        }
};

void heapify(int arr[], int n, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left<=n && arr[largest]<arr[left]){
        largest = left;
    }

    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if (largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    int size = n;

    while (size>1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){
    // heap h;
    // h.insert(55);
    // h.insert(53);
    // h.insert(54);
    // h.insert(50);
    // h.insert(52);
    // h.print(); 

    // h.deleteFromHeap();
    // h.print();

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n=5;
    // for (int i =n/2; i>0; i--){
    //     heapify(arr, n, i);
    // }
    // cout<<"printing the array now"<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<< arr[i] << " ";
    // }
    // cout<<endl;
    
    // heapSort(arr, n);
    
    // cout<<"printing the sorted array now"<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<< arr[i] << " ";
    // }
    // cout<<endl; 

    //max heap
    priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    cout<<"element at top "<< maxHeap.top()<<endl;
    maxHeap.pop(); 
    cout<<"element at top "<<maxHeap.top()<<endl;
    cout<< "Size is " << maxHeap.size()<<endl;
    if (maxHeap.empty()){
        cout<<"maxHeap is empty "<<endl;
    }else{
        cout<<"maxHeap is not empty "<<endl;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"element at top "<< minHeap.top()<<endl;
    minHeap.pop(); 
    cout<<"element at top "<<minHeap.top()<<endl;
    cout<< "Size is " << minHeap.size()<<endl;
    if (minHeap.empty()){
        cout<<"minHeap is empty "<<endl;
    }else{
        cout<<"minHeap is not empty "<<endl;
    }

    return 0;
}
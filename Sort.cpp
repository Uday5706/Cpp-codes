#include <bits/stdc++.h>
using namespace std;

void selectionSrt(vector<int> &v){
    for (int i=0;i<v.size()-1;i++){
        int minIndex = i;
        for (int j=i;j<v.size();j++){
            if (v[j]<v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}

void bubbleSrt(vector<int> &v){
    int n =v.size();
    for (int i=n-1;i>=1;i--){
        bool Swapped=false;
        for (int j=0;j<=i-1;j++){
            if (v[j]>v[j+1]){
             swap(v[j],v[j+1]);
             Swapped =true;
            }
        }
        if (!Swapped) break;
    }
}

void recBubbleSrt(vector<int> &v, int i){
    if (i==1)return;
    bool Swapped=false;
    for (int j=0;j<=i-2;j++){
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                Swapped=true;
            }
    }
    if (!Swapped) return;
    recBubbleSrt(v, i-1);
}

void insertionSrt(vector<int> &v){
    int n=v.size();
    for (int i=1;i<n;i++){
        for (int j=i;j>=1;j--){
            if (v[j-1]<v[j]) break;
            swap(v[j],v[j-1]);
        }
    }
}

void recInsertionSrt(vector<int> &v,int i=1){
    if (i>=v.size())return;
    for (int j=i;j>=1;j--){
        if (v[j-1]<v[j]) break;
        swap(v[j],v[j-1]);
    }
    recInsertionSrt(v,i+1);
}

void merge(vector<int> &v, int st,int end){
    int mid = (st + end) / 2;
    vector<int> sorted(end - st + 1);
    int i = st, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            sorted[k++] = v[i++];
        } else {
            sorted[k++] = v[j++];
        }
    }

    while (i <= mid) sorted[k++] = v[i++];
    while (j <= end) sorted[k++] = v[j++];

    for (int a = st; a <= end; a++) {
        v[a] = sorted[a - st];
    }
}

void mergeSrt(vector<int> &v, int st,int end){
    if (st>=end)return;
    int mid = (st+end)/2;
    mergeSrt(v,st,mid);
    mergeSrt(v,mid+1,end);
    merge(v,st,end);
}

void quickSrt(vector<int> &v, int st, int end ){
    if (st>=end) return;
    int pivot = st;
    int i=st,j=end;
    while (i<j){
        while (v[i]<=v[pivot] && i<end)i++;
        while (v[j]>v[pivot] && j>st)j--;

        if (i<j) swap(v[i],v[j]);
    }
    swap(v[j],v[pivot]);
    int partition=j;
    quickSrt(v,st,partition-1);
    quickSrt(v,partition+1,end);
}

int main() {
    vector<int> v={7,3,2,1,6,4,5};
    recInsertionSrt(v);
    for (int i:v) cout<<i<<" ";
    return 0;
}
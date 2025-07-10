#include <bits/stdc++.h>
using namespace std;

void Hash(int arr[],int n, int qry[],int q){
    int hash[13]={0}; //maxValue limit12 
    for (int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    for (int i=0;i<q;i++){
        cout<<hash[qry[i]]<<endl;
    }
}

void callHash(){
    int a[]={1,2,3,5,3,8,11,12,11,6,5,4,7,8,12,10,6,6,6};
    int n=sizeof(a)/sizeof(a[0]);
    int qry[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int q=sizeof(qry)/sizeof(qry[0]);
    Hash(a,n,qry,q);
}

void HashAlpha(string s,char qry[],int q){
    int hash[256]={0};
    for (int i=0; i<s.size(); i++){
        hash[s[i]]+=1;
    }
    for (int i=0;i<q;i++){
        cout<<hash[qry[i]]<<endl;
    }
    
}

void callHashAlpha(){
    string s="aabbcjmbcjkac";
    char qry[]={'a','b','g','h','f'};
    int q=sizeof(qry)/sizeof(qry[0]);
    HashAlpha(s,qry,q);
}

void HighestFreq(unordered_map<int,int> mpp){
    int maxNum;
    int maxFreq = 0;
    for (auto it : mpp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxNum = it.first;
        }
    }
    cout<<maxNum<<"->"<<maxFreq<<endl;
}

void LowestFreq(unordered_map<int,int> mpp){
    int minNum;
    int minFreq = INT_MAX;
    for (auto it : mpp) {
        if (it.second < minFreq) {
            minFreq = it.second;
            minNum = it.first;
        }
    }
    cout<<minNum<<"->"<<minFreq<<endl;
}

void HashMap(vector<int> v, vector<int> qry){
    unordered_map<int,int> mpp;
    for(int i:v) mpp[i]++;
    //unsorted iteration
    for (auto i:mpp){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    HighestFreq(mpp);
    LowestFreq(mpp);
    for (int i:qry) cout<<mpp[i]<<endl;
    
}

void callHashMap(){
    vector<int> v={1,2,2,1,1,3,4,7,7,5};
    vector<int> qry={1,3,7};
    HashMap(v,qry);
}

int maxFrequency(vector<int>& nums, int k) {
    //Brute: T=O(n^2 + nlogn) & S=O(1)
    // sort(nums.begin(), nums.end());
    // int n = nums.size();
    // int maxFreq = 1;

    // // Traverse from the last (largest element)
    // for (int i = n - 1; i >= 0; --i) {
    //     long long totalCost = 0;
    //     int freq = 1;

    //     // Try to make previous elements equal to nums[i]
    //     for (int j = i - 1; j >= 0; --j) {
    //         totalCost += (long long)(nums[i] - nums[j]);
    //         if (totalCost > k) break;
    //         freq++;
    //     }

    //     maxFreq = max(maxFreq, freq);
    // }

    // return maxFreq;

    //Optimal:T=O(nogn +n) & S=O(1) sliding window algo
    sort(nums.begin(), nums.end());
    long long left = 0, total = 0;
    int maxFreq = 0;

    for (int right = 0; right < nums.size(); ++right) {
        total += nums[right];

        // Check if we can make all elements in [left, right] equal to nums[right]
        while ((long long)nums[right] * (right - left + 1) - total > k) {
            total -= nums[left];
            left++;
        }

        maxFreq = max(maxFreq, (int)(right - left + 1));
    }

    return maxFreq;
}

int main() {
    vector<int> v={1,4,8,13};
    cout<<maxFrequency(v,5);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void printName(int n){
    if (n==0) return;
    cout<<"Uday\n";
    printName(n-1);
}

void printName2(int n,int i=0){
    if (i<n){
        cout<<"Uday\n";
        printName2(n,i+1);
    }
}

void oneToN(int n){
    //Back Tracking
    if (n==0 )return;
    oneToN(n-1);
    cout<<n<<" ";
}

void NToOne(int n, int i=1){
    //BackTracking
    if (i>n)return;
    NToOne(n,i+1);
    cout<<i<<" ";
}

void revArr(int a[],int n,int i=0){
    if (i>=n/2)return;
    swap(a[i],a[n-1-i]);
    revArr(a,n,i+1);
}

bool isPalindrome(string s,int i=0){
    // if (i>=s.size()/2) return true;
    // if ( s[i]==s[s.size()-1-i]){
    //     return isPalindrome(s,i+1);
    // }
    // return false;
    //Another way
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        // Compare lowercase versions
        if (tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
    }

    return true;
}

int Fibonacci(int n){
    //0 th is 0 and 1st is 1
    if (n<=1)return n;
    return Fibonacci(n-1)+Fibonacci(n-2);
    //Time Complexity is O(2^n)
}

int fibMemo(int n,vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n-1,dp) + fibMemo(n-2, dp);
}

int main() {
    // 0 1 1 2 3 5 8 13 21 34 55 
    // 0 1 2 3 4 5 6  7  8  9 10..
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    cout<<fibMemo(n,v);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void digitPrint(int num){
    while (num){
        cout<<num%10;
        num/=10;
    }
}

int countDigits(int num){
    //Time complexity is O(log10N)
    // int count=0;
    // while (num){
    //     count+=1;
    //     num/=10;
    // }
    int count = (int)(log10(num)+1);
    return count;
}

int revNum(int num){
    int revNum = 0;
    while (num){
        revNum = revNum*10 + num%10;
        num/=10;
    }
    return revNum;
}

bool isPalindrome(int num){
    int numCpy = num;
    int revNum = 0;
    while (num){
        revNum = revNum*10 + num%10;
        num/=10;
    }
    return numCpy==revNum;
}

bool isArmstrong(int num){
    int numCpy = num;
    int sum=0;
    while (num){
        sum+=pow(num%10,3);
        num/=10;
    }
    return numCpy==sum;
}

void printFactors(int num){
    vector<int> v;
    //O(sqrt(n))
    for (int i=1;i<=sqrt(num);i++){
        if (num%i==0){
            v.push_back(i);
            if ((num/i)!=i){
                v.push_back(num/i);
            }
        }
    }
    //O(no. of factors * log(number of factors))
    sort(v.begin(), v.end());
    // sum of both time complexity
    for (auto it:v){
        cout<<it<<" ";
    }
}

bool isPrime(int num){
    // int F=0;
    // for (int i=2;i<=sqrt(num);i++){
    //     if (num%i==0){
    //         F=1;
    //         break;
    //     }
    // }
    // if (!F && (num-1) && num){
    //     cout<<"prime"<<endl;
    // }
    // else{
    //     cout<<"not prime"<<endl;
    // }
    // return !F && num-1 && num;
    int cnt=0;
    for (int i=1; i*i<=num;i++){
        if (num%i==0){
            cnt++;
            if ((num/i)!=i) cnt++;
        }
    }
    if (cnt==2)cout<<"true";
    else cout<<"false";
    return cnt==2;
}

int GCD(int a, int b){
    int A =max(a,b);
    int B = min(a,b);
    int r = A%B;
    if (r==0){
        cout<< B;
        return B;
    }
    GCD(B,r);
}

int main() {
    int a,b;
    cin>>a>>b;
    GCD(a,b);
    return 0;
}
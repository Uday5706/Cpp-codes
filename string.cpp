#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int cnt=0;
    string ans="";
    for (int i=0;i<s.size();i++){
        if (cnt==0){ //Leave the first openiing bracket after cnt=0
            cnt++;
            continue;
        }
        if (s[i]=='(')cnt++;
        else cnt--;
        if (cnt!=0)ans+=s[i];
    }
    return ans;
}

string reverseWords(string s) {
    // T=O(n) & S=O(n)
    // string ans="";
    // string word="";
    // for ( char i:s){
    //     if (i==' '){
    //         if (word!=""){
    //             ans= " "+word +ans;
    //             word="";
    //         }
    //         continue;
    //     }else{
    //         word+=i;
    //     }
    // }
    // ans= word+ans;
    // if (ans[0]==' ')return ans.substr(1);
    // return ans;
    //Better: T=O(n) & S=O(1)
    reverse(s.begin(), s.end());

    int i = 0, k = 0, n = s.size();
    while (i < n) {
        while (i < n && s[i] == ' ')i++;

        if (i != n && k > 0) {
            s[k++] = ' ';
        }

        int s_index = k;

        while (i < n && s[i] != ' ')
            s[k++] = s[i++];

        reverse(s.begin() + s_index, s.begin() + k);
    }
    s.resize(k);
    return s;
}

string largestOddNumber(string num){
    int i=num.size()-1;
    while(i>=0){
        if ((int)num[i]%2!=0){
            return num.substr(0,i+1);
        }
        i--;
    }
    return "";
}

int commonPrefixLength(string s1, string s2){
    int cnt=0;
    int n1=s1.size(),n2=s2.size();
    if (n1>n2)return commonPrefixLength(s2,s1);
    for (int i=0;i<n1;i++){
        if (s1[i]==s2[i])cnt++;
        else break;
    }
    return cnt;
}
string longestCommonPrefix(vector<string>& strs) {
    //Brute: T=O(n*m)
    // int maxPrefixLen=200;
    // for (int i=1;i<strs.size();i++){
    //     maxPrefixLen=min(maxPrefixLen,commonPrefixLength(strs[i],strs[i-1]));
    // }
    // return strs[0].substr(0,maxPrefixLen);
    //Best: T=O(200*n)
    if (strs.empty()) return "";
    for (int i = 0; i < strs[0].size(); ++i) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

bool isIsomorphic(string s, string t) {
    if (s.size()!=t.size()) return false;
    unordered_map<int,int> mpp;
    unordered_set<int> st;
    for (int i=0; i<s.size();i++){
        if (mpp.find(s[i])==mpp.end()){
         if (st.find(t[i])==st.end()){
            mpp[s[i]]=t[i];
            st.insert(t[i]);
         }else{
            return false;
         }
        }else {
            if (mpp[s[i]]!=t[i])return false;
        }
    }
    return true;
}

bool rotateString(string s, string goal){
    //Brute: T=O(n^2) & S=O(n) for n times we make rotated string as string rotated = s.substr(1) + first; and if its not equal we change s=rotated; substr takes O(n) n=size of substr
    //Better: T=O(n^2) & S=O(1) Trying each rotation and comparing it with goal
    //Optimal: T=O(n) & S=O(n) Make a temp = s+s and comparte with npos temp.find(goal) != string::npos;
    // Step 1: Check if the lengths are equal.
    if (s.length() != goal.length()) {
        return false;
    }
    // Step 2: Check if 'goal' is a substring of 's' concatenated with itself.
    string temp = s + s;
    return temp.find(goal) != string::npos;  
}

bool isAnagram(string s, string t) {
    if (s.size()!=t.size()) return false;
    unordered_map<char,int> mpp1;
    unordered_map<char,int> mpp2;
    for (int i=0;i<s.size();i++){
        mpp1[s[i]]++;
        mpp2[t[i]]++;
    }
    for (int i=0;i<s.size();i++){
        if (mpp1[s[i]]!=mpp2[s[i]])return false;
    }
    return true;
}

string frequencySort(string s) {
    if (s.empty())return s;
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
    }
    vector<pair<int, int>> vec(mpp.begin(), mpp.end());

    // Sort by value (second), descending
    sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
    string ans="";
    for (auto& p : vec) {
            ans.append(p.second, p.first);  // repeat char p.second times
        }
    return ans;
}

int maxDepth(string s) {
    int maxCnt=0;
    int cnt=0;
    for (char c:s){
        if (c=='('){
            cnt++;
            maxCnt=max(cnt,maxCnt);
        }else if (c==')')cnt--;
    }
    return maxCnt;
}

int romanToInt(string s) {
    int n=s.size();
    unordered_map<char,int> symbols={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans=0;
    for (int i=0;i<s.size();i++){
        if (i<n-1 && symbols[s[i]]>=symbols[s[i+1]]){
            ans+=symbols[s[i]];
        }else if (i<n-1){
            ans-=symbols[s[i]];
        }else{
            ans+=symbols[s[i]];
        }
    }
    return ans;
}

signed int myAtoi(string s){
    int i=0, n=s.size();
    long long ans=0;
    int sign=1;
    while ( i<n && (s[i]==' '))i++;
    if (i<n && (s[i]=='-'||s[i]=='+')){
        if (s[i]=='-') sign=-1;
        i++;
    }
    while (i<n && isdigit(s[i])){
        int digit = s[i]-'0';
        ans=ans*10 + digit;
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans< INT_MIN) return INT_MIN;
        i++;
    }
    return ans*sign;
}

int main() {
    cout<<myAtoi("  -00042");
    return 0;
}
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

int countAtMostK(string &s, int k) {
    int n = s.size();
    vector<int> freq(256, 0); // char frequency
    int left = 0, right = 0;
    int distinct = 0;
    long long ans = 0;

    while (right < n) {
        if (freq[s[right]] == 0) distinct++; 
        freq[s[right]]++;
        
        while (distinct > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) distinct--;
            left++;
        }
        ans += (right - left + 1); // all substrings ending at right
        right++;
    }
    return ans;
}
int countSubStrings(string str, int k) {
    //Brute: T =O(n^3) checking each substring and counting number of unique characters ==k
    //Better: T=O(n) Using sliding window algo + freq and finding substrings with atmostK unique chars and then atmost k-1 and then subtract them to get the ans. Increase right and if the character at right has 0 freq => distinct++ and freq[s[right]]++ and if at any time distinct >k increase left++ until it is <=k,(window shrinking) after it ans+=right-left+1 i.e number of substrings  ending at right as all between (left and right are all ready counted before)and then right++(window expanding)
    return countAtMostK(str, k) - countAtMostK(str, k - 1);
}

string longestPalindrome(string s) {
    //Brute : T=O(n^3) checking all possible substrings O(n^2) and then checking if they are palindrome O(n)
    //Better : T=O(n^2) we knwo palindrome are symmetrical around their center and their are total 2n-1 possible centers, so expanding through all that centers and checking how much far or long can this be palindrome  
    int n = s.size();
    if (n == 0) return "";
    int start = 0, maxLen = 1;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; i++) { //checking each possible center of palindrome
        expand(i, i);     // odd length
        expand(i, i + 1); // even length
    }

    return s.substr(start, maxLen);
}

string isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        // Skip non-alphanumeric characters
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;

        // Compare characters ignoring case
        if (tolower(s[i]) != tolower(s[j])) return "Nope!";

        i++;
        j--;
    }
    return "Yees!!!";
}

int beautySum(string s) {
    //T=O(n^2) & S=O(1)
    int n = s.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            int maxFreq = 0, minFreq = INT_MAX;
            for (int f : freq) {
                if (f > 0) {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, f);
                }
            }
            sum += (maxFreq - minFreq);
        }
    }

    return sum;
}

void replaceSpaces(string &s) {
    //wihtout any extra space
    int spaceCount = 0;
    for (char c : s) {
        if (c == ' ') spaceCount++;
    }
    int oldSize = s.size();
    s.resize(oldSize + 2 * spaceCount);

    int i = oldSize - 1;        // old index
    int j = s.size() - 1;       // new index

    while (i >= 0) {
        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '4';
            s[j--] = '@';
        } else {
            s[j--] = s[i];
        }
        i--;
    }
    //OR
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == ' ') {
    //         s.erase(i, 1);          // remove the space
    //         s.insert(i, "@40");     // insert "@40" at same index
    //         i += 2;                 // skip past inserted "@40"
    //     }
    // }
}

string removeOccurrences(string s, string part) {
    // for (int i=0;i<s.size();i++){
    //     if (s.substr(i,part.size())==part){
    //         s.erase(i,part.size());
    //         return removeOccurrences(s,part); //stack
    //     }
    // }
    // return s;
    // int i = 0;
    // int n = s.size();
    // while (i < n) {
    //     if (s.substr(i, part.size()) == part) { //temp substr
    //         s.erase(i, part.size());
    //         i = 0;
    //         n -= part.size();
    //     } else {
    //         i++;
    //     }
    // }
    // return s;
    while (s.size()!=0 && s.find(part)<s.size()){ //optimal
        s.erase(s.find(part),part.size());
    }
    return s;
}

bool check(int a[],int b[]){
    for (int i=0;i<26;i++){
        if (a[i]!=b[i])return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    //T=O(n1+26n2) Fix window moving over s2 by updating shrinked and expanded chars count and matching count1 and count2 each time
    // if (s1.size() > s2.size()) return false;
    // int count1[26]={0};
    // int count2[26]={0};
    // for (char c:s1)count1[c-'a']++;
    // int i=0;
    // while (i<s1.size() && i<s2.size())count2[s2[i++]-'a']++;
    // if (check(count1,count2))return  true;
    // while(i<s2.size()){
    //     count2[s2[i-s1.size()]-'a']--;
    //     count2[s2[i++]-'a']++;
    //     if (check(count1,count2))return  true;
    // }
    // return false;

    //OR T=O(n1+n2) To avoid checking count1 and count2 fully each time create a match var which checks the matched values in count1 and count2 initially before window creation in s2 and then when at any time that match reaches 26 i.e the count of chars in  s2 window == s1 chars count then return true. do it by window expanding and shrinking
    if (s1.size() > s2.size()) return false;
    int count1[26] = {0}, count2[26] = {0};
    for (char c : s1) count1[c - 'a']++;

    int matches = 0;
    for (int i = 0; i < 26; i++) 
            if (count1[i] == count2[i]) matches++;

    int l = 0;
    for (int r = 0; r < s2.size(); r++) {
        int idx = s2[r] - 'a';
        count2[idx]++;
        if (count1[idx] == count2[idx]) matches++;
        else if (count1[idx] + 1 == count2[idx]) matches--;

        if (r - l + 1 > s1.size()) {
            int leftIdx = s2[l++] - 'a';
            if (count1[leftIdx] == count2[leftIdx]) matches--;
            else if (count1[leftIdx]==count2[leftIdx]-1) matches++;
            count2[leftIdx]--;
        }

        if (matches == 26) return true;
    }
    return false; 
}

string removeDuplicates(string s) {
    // T=O(n^2) but more worst
    // int n = s.size();
    // int i=0;
    // while (i<n-1){
    //     if (s[i]==s[i+1]){
    //         s.erase(i,2); //O(n) for shifting
    //         n-=2;
    //         if (i-1>=0)i--;
    //     }else i++;
    // }
    // return s;
    string result;
    for (char c : s) {
        if (!result.empty() && result.back() == c)
            result.pop_back(); // remove duplicate
        else
            result.push_back(c);
    }
    return result;
}

int compress(vector<char>& chars) {
    int l = 0, r = 0;
    int n = chars.size();
    while (r < n) {
        if (chars[l] == chars[r]) {
            r++;
        } else {
            int count = r - l;
            chars.erase(chars.begin() + l + 1, chars.begin() + r);
            n -= count - 1;
            l += 1;
            if (count >= 10) {
                int num = count;
                int digits = 0;
                while (num > 0) {
                    char digit = '0' + (num % 10);
                    digits += 1;
                    chars.insert(chars.begin() + l, digit);
                    n += 1;
                    num /= 10;
                }
                l += digits;
                r = l;
            } else if (count > 1) {
                chars.insert(chars.begin() + l, '0' + count);
                n += 1;
                r = ++l;
            }
        }
            
    }
    //last group
    if (l != n - 1) {
        int count=r-l;
        chars.erase(chars.begin() + l + 1, chars.begin() + r);
        n-=count-1;
        l+=1;
        if (count >= 10) {
            int num = count;
            int digits = 0;
            while (num > 0) {
                char digit = '0' + (num % 10);
                digits += 1;
                chars.insert(chars.begin() + l, digit);
                n += 1;
                num /= 10;
            }
            l += digits;
            r = l;
        } else if (count > 1) {
            chars.insert(chars.begin() + l, '0' + count);
            n += 1;
            r = ++l;
        }
    }
    return n;
    //OR
    int l = 0, r = 0;
    int n = chars.size();
    while (r < n) {
        while (r < n && chars[l] == chars[r])r++; // expand group
        int count = r - l; // group length
        chars.erase(chars.begin() + l + 1, chars.begin() + r);
        n -= (count - 1);
        if (count > 1) { // insert count if > 1
            string cnt = to_string(count);  // ensures correct order
            chars.insert(chars.begin() + l + 1, cnt.begin(), cnt.end());
            n += cnt.size();
            l += cnt.size();  // move past digits
        }
        // move to next group
        l++;
        r = l;
    }
    return n;
    //OR without insert and erase
    int l = 0, r = 0;
    int ansIndex=0;
    int n = chars.size();
    while (l < n) {
        // expand group
        while (r < n && chars[l] == chars[r])
            r++;
        int count = r - l; // group length
        // erase duplicates, keep one copy
        chars[ansIndex++]=chars[l];
        // insert count if > 1
        if (count > 1) {
            string cnt = to_string(count);
            for (char c:cnt) chars[ansIndex++]=c;
        }
        l=r;
    } 
    return ansIndex;
}

int main() {
    vector<char> chars ={'a','a','a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<compress(chars);
    return 0;
}
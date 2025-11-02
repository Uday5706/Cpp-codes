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

int atoiHelper(const string &s, int i, long long ans, int sign, bool started){
    int n = s.size();

    // Base case
    if (i >= n)
        return ans * sign;

    char c = s[i];

    // Skip leading spaces (only before number starts)
    if (!started && c == ' ')
        return atoiHelper(s, i + 1, ans, sign, started);

    // Handle sign (only if number not started yet)
    if (!started && (c == '-' || c == '+'))
        return atoiHelper(s, i + 1, ans, (c == '-') ? -1 : 1, true);

    // If it's a digit
    if (isdigit(c)){
        ans = ans * 10 + (c - '0');

        // Clamp to 32-bit signed integer range
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;
        if (sign == -1 && -ans < INT_MIN)
            return INT_MIN;

        return atoiHelper(s, i + 1, ans, sign, true);
    }

    // Stop at first invalid character after number start
    return ans * sign;
}
int atoi(string s) { return atoiHelper(s, 0, 0, 1, false); }

double powHelper(double x, long long n, double ans = 1){
    if (n == 0)
        return ans;
    if (n % 2 == 0)
        return powHelper(x * x, n / 2, ans);
    else
        return powHelper(x, n - 1, ans * x);
}
double myPow(double x, int n){
    long long N = n; // promote to long long
    if (N < 0)
        return 1 / powHelper(x, -N);
    else
        return powHelper(x, N);
}

const long long MOD = 1e9 + 7;
long long power(long long base, long long exp){
    long long result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}
int countGoodNumbers(long long n){
    long long evenCount = (n + 1) / 2; // positions 0,2,4,...
    long long oddCount = n / 2;        // positions 1,3,5,...

    long long evenWays = power(5, evenCount);
    long long oddWays = power(4, oddCount);

    return (evenWays * oddWays) % MOD;
}

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}
void sortStack(stack<int>& st) {
    if (st.size() <= 1) return;

    int topElement = st.top();
    st.pop();

    sortStack(st);  // sort remaining stack

    insertSorted(st, topElement);  // insert in correct place
}

void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}
void reverseStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

void binHelper(vector<string>& v, int n, string bin = "") {
    if (n == 0) {
        v.push_back(bin);
        return;
    }
    binHelper(v, n - 1, bin + '0');
    binHelper(v, n - 1, bin + '1');
}
vector<string> binstr(int n) {
    vector<string> bins;
    binHelper(bins, n);
    return bins;
}

void parenthesisHelper(vector<string>& v, int n, string ans = "", int open = 0, int close = 0) {
    if (ans.size() == 2 * n) {
        v.push_back(ans);
        return;
    }
    if (open < n)
        parenthesisHelper(v, n, ans + '(', open + 1, close);
    if (close < open)
        parenthesisHelper(v, n, ans + ')', open, close + 1);
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    parenthesisHelper(ans,n);
    return ans;
}
    
void subsetsHelper(vector<int>& nums,vector<vector<int>>& result,vector<int>& ans, int i=0){
    if (i>=nums.size()){
        result.push_back(ans); //O(n)
        return;
    }
    subsetsHelper(nums,result,ans,i+1);
    ans.push_back(nums[i]);
    subsetsHelper(nums,result,ans,i+1);
    ans.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    //T=O(2^n * n) & S=O(n+n+2^n*n) recursion takes O(n) space as stack space is recursion tree depth(longest chain needed at a time)DFS not BFS
    vector<vector<int>> result;
    vector<int> ans={};
    subsetsHelper(nums,result,ans);
    return result;
    //or by masks T=O(2^n * n) & S=O(2^n*n)
    // int n = nums.size();
    // vector<vector<int>> result;

    // for (int mask = 0; mask < (1 << n); mask++) { // mask from 0 to 2^n - 1
    //     vector<int> subset;
    //     for (int j = 0; j < n; j++) {
    //         if (mask & (1 << j)) { // check if j-th bit is set
    //             subset.push_back(nums[j]);
    //         }
    //     }
    //     result.push_back(subset);
    // }
    // return result;
}

bool isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void helper(string &S, int index, string curr, set<string> &res){
    if (index == S.size()){
        if (!curr.empty() && isVowel(curr[0]) && !isVowel(curr.back())){
            res.insert(curr);
        }
        return;
    }
    // Include current character
    helper(S, index + 1, curr + S[index], res);
    // Exclude current character
    helper(S, index + 1, curr, res);
}
set<string> allPossibleSubsequences(string S){
    //T=O(2^n*nlogu) & S=O(n+n*u) where u is no. of unique subseq
    set<string> res;
    helper(S, 0, "", res);
    return res;
}

void printSubSeqsWithSumK(vector<int>& nums,int k,vector<int>& ds,int i=0, int sum =0){
    //T=O(2^n * n) & S=O(2n) stack depth + ds
    if (i==nums.size()){
        if (sum==k){
            for (int num: ds){
                cout<<num<<",";
            }
            cout<<endl;
        }
        return;
    }
    if (sum>k)return;

    ds.push_back(nums[i]);
    printSubSeqsWithSumK(nums,k,ds,i+1,sum+nums[i]);

    ds.pop_back();
    printSubSeqsWithSumK(nums,k,ds,i+1,sum);
}

bool checkSubSeqWithSumK(vector<int>& nums,int k,int i=0, int sum =0){
    // T=O(2^n * n) & S=O(2n) Stack depth + ds and using value return by function to discontinue the recursion
    if (i==nums.size()){
        if (sum==k){
            return true;
        }
        else return false;
    }
    if (sum>k)return false;

    if (checkSubSeqWithSumK(nums,k,i+1,sum+nums[i]))return true;

    if (checkSubSeqWithSumK(nums,k,i+1,sum))return true;

    return false;
}

int countSubSeqsWithSumK(vector<int>& nums,int k,int& count,int i=0, int sum =0){
    //for counting follow 2nd pattern check all counts in left rec tree and then in right rec tree and then return l+r
    //T=O(2^n) & S=O(2n) stack depth + ds
    // if (i==nums.size()){
    //     if (sum==k){
    //         count++;
    //     }
    //     return;
    // }
    // if (sum>k)return; //pruning
    // countSubSeqsWithSumK(nums,k,count,i+1,sum+nums[i]);
    // countSubSeqsWithSumK(nums,k,count,i+1,sum);
    if (i==nums.size()){
        if (sum==k){
            return 1;
        }
        return 0;
    }
    if (sum>k)return 0; //pruning only if all are +ve
    int l = countSubSeqsWithSumK(nums,k,count,i+1,sum+nums[i]);
    int r = countSubSeqsWithSumK(nums,k,count,i+1,sum);
    return l+r;
}

void combinationSum(vector<int>& nums, int t,vector<int>& ds,vector<vector<int>>& res, int i=0, int sum=0){
    //T=O(2^t * k) say if there's a 1 then rec go for t times and then k is len of ds pushing to res which takes O(k)
    //S=O(t+t) as ds and recursion depth can be max t
    if (i == nums.size()) {
        if (sum == t) {
            res.push_back(ds);
        }
        return;
    }
    //Pruning: If the sum is already too high, stop.
    // (This assumes all numbers in 'nums' are positive)
    if (sum > t) {
        return;
    }
    //Two choices choose nums[i] again or move forward
    ds.push_back(nums[i]);
    combinationSum(nums, t, ds, res, i, sum + nums[i]);

    ds.pop_back();
    combinationSum(nums, t, ds, res, i + 1, sum);
}

void combinationSum2Helper(int start,int target, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res) {
    if (target==0){
        res.push_back(ds);
        return;
    }
    for (int i=start; i<nums.size(); i++){
        if (i>start && nums[i]==nums[i-1])continue;//skip duplicates at same recursion depth
        if (nums[i]>target)break;

        ds.push_back(nums[i]);
        combinationSum2Helper(i+1,target-nums[i],nums,ds,res);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> nums, int target) {
    //T=O(nlogn + 2^n*n) & S=O(n+n*k) recursion depth + DS and k subseq
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> ds;
    combinationSum2Helper(0,target,nums,ds,res);

    return res;
}

void subsetSum(vector<int>& nums, set<int>& ds, int i=0, int sum=0){
    //T=O(2^n) & S=O(2^n)
    if (i == nums.size()) {
        ds.insert(sum);
        return;
    }
    subsetSum(nums, ds, i+1, sum + nums[i]);
    subsetSum(nums, ds, i + 1, sum);
}

void subsetSum2Helper(int start, vector<int>& ds, vector<int>& nums, vector<vector<int>>& res) {
    // T=O(2^n*n) & S=O(2^n*k + n)
    res.push_back(ds);
    for (int i=start; i<nums.size(); i++){
        if (i>start && nums[i]==nums[i-1])continue;//skip duplicates at same recursion depth
        
        ds.push_back(nums[i]);
        subsetSum2Helper(i+1,ds,nums,res);
        ds.pop_back();
    }
}
vector<vector<int>> subsetSum2(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<int> ds;
    vector<vector<int>> res;
    subsetSum2Helper(0,ds,nums,res);
    return res;
}

void combinationSum3Helper(int start, int k, int n,vector<int>& ds, vector<vector<int>>& res){
    if (k==0 && n==0){
        res.push_back(ds);
        return;
    }

    if (k == 0 || n < 0) return;

    for (int i=start; i<10;i++){
        // if (i > n) break;
        ds.push_back(i);
        combinationSum3Helper(i+1,k-1,n-i,ds,res);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n){
    //T=O(nCk*k) but since bounded by O(2^9*k) & S=O(k+k*p) (p=no. of combinations)
    vector<int> ds;
    vector<vector<int>> res;
    combinationSum3Helper(1,k,n,ds,res);
    return res;
}

map<int,string> phone = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
void letterCombinationsHelper(string digits,int i,string& ans, vector<string>& res){
    //T=O(n*4^n) & S=O(n+ n*4^n)
    //maine iskle bare me aise socha ki hr loop me ek choose krke next num ke letters me se ek choose krna h liek pick or unpick by for loop just domain changes at each step
    if (i>=digits.size()){
        res.push_back(ans);
        return;
    }

    int digit = digits[i] - '0';
    for (char c : phone[digit]) {
        ans.push_back(c);
        letterCombinationsHelper(digits, i + 1, ans, res);
        ans.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    string ans="";
    vector<string> res;
    letterCombinationsHelper(digits,0,ans,res);
    return res;
}

void partitionHelper(int start, string& s, vector<string>& ds, vector<vector<string>>& res) {
    if (start == s.size()) {
        res.push_back(ds);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        string sub = s.substr(start, end - start + 1);
        if (isPalindrome(sub)) {
            ds.push_back(sub);                          // pick
            partitionHelper(end + 1, s, ds, res);       // explore next part
            ds.pop_back();                              // backtrack
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> ds;
    partitionHelper(0, s, ds, res);
    return res;
}

bool existHelper(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    //T=O(m*n + N)
    // 1. Base cases
    if (idx == word.size())
        return true; // found word
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;
    if (board[i][j] != word[idx])
        return false; // mismatch

    // 2. Mark visited
    char temp = board[i][j];
    board[i][j] = '#'; // mark as visited temporarily

    // 3. Explore in all four directions
    bool found = existHelper(board, word, i + 1, j, idx + 1) ||
                 existHelper(board, word, i - 1, j, idx + 1) ||
                 existHelper(board, word, i, j + 1, idx + 1) ||
                 existHelper(board, word, i, j - 1, idx + 1);

    // 4. Unmark (backtrack)
    board[i][j] = temp;

    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    // T= O(m × n + L + m*n*4^L)  or Q(m × n + L + m*n*L)
    // S = O(L) recursion depth upto word length]
    int m = board.size(), n = board[0].size();
    if ((int)word.size() > m * n)
        return false;

    // Frequency pruning: check if board contains enough of each char
    int freqBoard[256] = {0}, freqWord[256] = {0};
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            ++freqBoard[(unsigned char)board[i][j]];
    for (char c : word)
        ++freqWord[(unsigned char)c];
    for (int ch = 0; ch < 256; ++ch)
        if (freqWord[ch] > freqBoard[ch])
            return false;

    // Heuristic: if last char is rarer than first char, reverse the word
    // This can reduce branching in many cases.
    if (freqBoard[(unsigned char)word.front()] >
        freqBoard[(unsigned char)word.back()]) {
        reverse(word.begin(), word.end());
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (existHelper(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

// void disableBoard(vector<vector<int>>& board, int row, int col) {
//     int n = board.size();
//     // Block row
//     for (int j = 0; j < n; j++) board[row][j] = 1;
//     // Block column
//     for (int i = 0; i < n; i++) board[i][col] = 1;
//     int i, j;
//     // Block top-right diagonal
//     i = row; j = col;
//     while (i >= 0 && j < n) board[i--][j++] = 1;
//     // Block bottom-right diagonal
//     i = row; j = col;
//     while (i < n && j < n) board[i++][j++] = 1;
//     // Block top-left diagonal
//     i = row; j = col;
//     while (i >= 0 && j >= 0) board[i--][j--] = 1;
//     // Block bottom-left diagonal
//     i = row; j = col;
//     while (i < n && j >= 0) board[i++][j--] = 1;
// }
// void NQueensHelper(int start, int queensLeft, vector<vector<int>>& board,vector<string>& ans, vector<vector<string>>& res) {
//     if (queensLeft == 0) {
//         res.push_back(ans);
//         return;
//     }
//     int n = board.size();
//     for (int j = 0; j < n; j++) {
//         if (board[start][j] == 0) {
//             vector<vector<int>> temp = board;  // make a copy
//             disableBoard(temp, start, j);
//             string row(n, '.');  // must be of full board size
//             row[j] = 'Q';
//             ans.push_back(row);
//             NQueensHelper(start + 1, queensLeft - 1, temp, ans, res);
//             ans.pop_back();
//         }
//     }
// }
// vector<vector<string>> solveNQueens(int n) {
//     //T=O(N!*N^2) & S=O(N^3)
//     vector<vector<int>> board(n, vector<int>(n, 0));
//     vector<vector<string>> res;
//     vector<string> ans;
//     NQueensHelper(0, n, board, ans, res);
//     return res;
// }

void NQueensHelper(int row, int n,vector<string>& board,vector<vector<string>>& res, vector<int>& cols,vector<int>& diag1,
vector<int>& diag2) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (cols[col] || diag1[row + col] || diag2[row +(n-1-col)])
            continue;  // position under attack

        // place queen
        board[row][col] = 'Q';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;

        // recurse for next row
        NQueensHelper(row + 1, n, board, res, cols, diag1, diag2);

        // backtrack
        board[row][col] = '.';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
    }
}
vector<vector<string>> NQueens(int n) {
    //T=O(N!) & S=O(N+N^2)
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    vector<int> cols(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);
    NQueensHelper(0, n, board, res, cols, diag1, diag2);
    return res;
}

void ratInMazeHelper(int i, int j, vector<vector<int>>& maze, string& path,vector<string>& paths, int di[], int dj[], string& dir) {
    int n = maze.size();
    if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
        return;
    if (i == n - 1 && j == n - 1) {
        paths.push_back(path);
        return;
    }
    maze[i][j] = 0; // mark visited
    for (int k = 0; k < 4; k++) {
        path.push_back(dir[k]);
        ratInMazeHelper(i + di[k], j + dj[k], maze, path, paths, di, dj, dir);
        path.pop_back();
    }
    maze[i][j] = 1; // unmark
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> paths;
    if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return {};
    string path = "";
    // Directions defined once and passed to helper
    int di[4] = {1, 0, 0, -1};     // Down, Left, Right, Up
    int dj[4] = {0, -1, 1, 0};
    string dir = "DLRU";           // ensures lexicographical order
    ratInMazeHelper(0, 0, maze, path, paths, di, dj, dir);
    return paths;
}

bool wordBreakHelper(int start, string& s, unordered_set<string> &dict){
    if (start==s.size())return true;

    for (int end=start+1;end<=s.size();end++){
        string word = s.substr(start,end-start);
        if (dict.count(word) && wordBreakHelper(end,s,dict))
            return true;
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return wordBreakHelper(0, s, dict);
}

int main() {
    // 0 1 1 2 3 5 8 13 21 34 55 
    // 0 1 2 3 4 5 6  7  8  9 10..
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> res =ratInMaze(maze);
    for (auto j:res)cout<<j<<" ";
    return 0;
}
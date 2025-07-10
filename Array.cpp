#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void secLargest(int arr[], int n){
    int max = INT16_MIN;
    int secMax = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            secMax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secMax)
        {
            secMax = arr[i];
        }
    }
    if (max == secMax)
    {
        cout << "Second Largest isn't available";
        return;
    }
    cout << secMax;
}

int smallest(int arr[], int n){
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void secSmallest(int arr[], int n){
    int min = INT16_MAX;
    int secMin = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            secMin = min;
            min = arr[i];
        }
        else if (arr[i] > min && arr[i] < secMin)
        {
            secMin = arr[i];
        }
    }
    if (min == secMin)
    {
        cout << "Second Smallest isn't available";
        return;
    }
    cout << secMin;
}

bool ifSorted(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return true;
        }
    }
    return false;
}

int removeDupsSrtdArr(int arr[], int n){
    // int index=0;
    // set<int> st;
    // for (int i=0;i<n;i++){
    //     st.insert(arr[i]);
    // }
    // for (auto it:st){
    //     arr[index]=it;
    //     index++;
    // }
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

void leftRotate(int arr[], int n, int d = 1){
    // T(N+d) & S(d)
    //  Input Space you are using is O(n)
    // Extra space used is O(d)
    d = d % n;
    // int temp[d];
    // for (int i=0;i<d;i++){
    //     temp[i]=arr[i];
    // }
    // for (int i=d;i<n;i++){
    //     arr[i-d]=arr[i];
    // }
    // for (int i=n-d;i<n;i++){
    //     arr[i]=temp[i-(n-d)];
    // }
    d = d % n;
    // T(2n) and S(1)
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
    // Or make a temp arrayu and directly assign temp[i+d]=arr[i] and then make temp and arr equal. Same time and Space Complexity
}

void moveZeroesToEnd(int arr[], int n){
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] == 0 && arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[i] != 0)
        {
            i++;
            j++;
        }
        else if (arr[j] == 0)
        {
            j++;
        }
    }
}

void rightRotate(int arr[], int n){
    int temp = arr[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int linearSearch(int arr[], int n, int key){
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[i] == key)
            return i;
    }
    return i;
}

void unionOfSrtdArr(int a1[], int n1, int a2[], int n2){
    // Brute Force approach is to use set T(n1logn + n2logn +n1+n2) & S(O(n1+n2) + O(n1+n2))
    vector<int> Union;
    int i = 0, j = 0;
    while (true)
    {
        if (i < n1 && a1[i] <= a2[j])
        {
            if (Union.empty() || Union.back() != a1[i])
            {
                Union.push_back(a1[i++]);
            }
            else
            {
                i++;
            }
        }
        else if (j < n2)
        {
            if (Union.empty() || Union.back() != a2[j])
            {
                Union.push_back(a2[j++]);
            }
            else
            {
                j++;
            }
        }
        else
        {
            break;
        }
    }
    for (int it : Union)
    {
        cout << it << ' ';
    }
    // T=O(n1+n2) & S=O(n1+n2)
}

void intersectionOfSrtdArr(int a1[], int n1, int a2[], int n2){
    // Brute force approch will be checking for each element in n1 in n2 and mark the visited ones as 1 in a vis array of n2 storing 0 for not visited and 1 for visited.
    // T=O(n1*n2) and S=O(n2)
    vector<int> Intersection;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] == a2[j] && (Intersection.empty() || Intersection.back() != a1[i]))
        {
            Intersection.push_back(a1[i]);
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    for (int it : Intersection)
    {
        cout << it << " ";
    }
    // T = O(n1+n2) && S=O(1) (excluding output array as it is to return)
}

int findMissingNum(int arr[], int &n){
    // Brute: Check every number from 1 to n in the array by linear Search So T=O(n^2)
    // Better: Make a vis of size n+1 array and traverse through loop and mark 1 to every number which is visited and then check for the number which is zero in the visited array So T=O(2n) & S=O(n)
    // Optimal: (1) XOR: T=O(n) & S=O(1) better as if n comes to around 10^5 then sum will croos the limit of a int whereas xor can handle it easily;
    int xOR = 0, XOR = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xOR ^= arr[i];
        XOR ^= (i + 1);
    }
    XOR ^= n;
    return xOR ^ XOR;
    //(2) SUM T=O(n) & S=O(1)
    // int sum=0;
    // int Sum=n*(n+1)/2;
    // for (int i=0;i<n-1;i++){
    //     sum+=arr[i];
    // }
    // return Sum-sum;
}

int maxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count += 1;
        }
        else
        {
            if (maxCount < count)
            {
                maxCount = count;
            }
            count = 0; // reset counter after encountering 0
        }
    }
    return maxCount;
}

int numAppear(int arr[], int n)
{
    // Brute:Check every number from 1 to n in the array by linear Search and count whose count is 1 So T=O(n^2)
    // Better:Finding one with 1 frequency by data traversal. In hash Array case T=O(3n) and S=O(max(arr)) , IN map case: T=O(NlogM)+O(N/2+1) & S=O(N/2+1)
    // Optimal:(1) XOR: T=O(n) & S=O(1) better as if n comes to around 10^5 then sum will croos the limit of a int whereas xor can handle it easily;
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }
    return XOR;
    //(2) SUM T=O(n) & S=O(1)
    // int sum=0;
    // int Sum=2*n*(n+1)/2;
    // for (int i=0;i<n-1;i++){
    //     sum+=arr[i];
    // }
    // return Sum-sum;
}

// Sub arr is contiguous sub part of array
int LongestSubArrOfSumK(int arr[], int n, int k)
{
    // Brute: Calculate all subarrays T=O(n^2) & S=O(1) work with all type of arrays
    //  int maxCnt=0;
    //  for (int i=0;i<n;i++){
    //      int sum=0;
    //      for (int j=i;j<n;j++){
    //         sum += arr[j];
    //         if (sum == k) {
    //             maxCnt = max(maxCnt, j - i + 1);
    //         }
    //      }
    //  }
    //  return maxCnt;
    //Better: Hashmap T=O(nlogn or n) & S=O(n) work with all type of arrays and best if negatives are present
    map<int,int> sumMpp;
    int sum=0;
    int maxCnt=0;
    for (int i=0; i<n;i++){
        sum+=arr[i];
        if (sum==k){
            maxCnt = max(maxCnt,i+1);
        }
        int rem=sum-k;
        if (sumMpp.find(rem)!=sumMpp.end()){
            int cnt=i-sumMpp[rem];
            maxCnt = max(maxCnt,cnt);
        }
        if (sumMpp.find(sum)==sumMpp.end()){
            sumMpp[sum]=i;
        }
    }
    return maxCnt;
    // Optimal: Sliding Window Algo(only with zeroes and positives) Failure case:{4,-1,-1,1} best with zeroes and positives only T=O(2n) & S=O(1)
    // int i = 0, j = 0;
    // int sum = 0;
    // int maxCnt = 0;

    // while (j < n){
    //     sum += arr[j];
    //     while (sum > k && i <= j){
    //         sum -= arr[i++];
    //     }
    //     if (sum == k){
    //         maxCnt = max(maxCnt, j - i + 1);
    //     }
    //     j++;
    // }
    // return maxCnt;
}

string twoSum(int arr[],int n, int target){  
    //variety 1: telling yes or no
    //variety 2: telling indexes of both
    //Brute:T=O(n^2) & S=O(1) iterating from each element to every other & checking if sum is K.
    //Better: (best for variety 1) Hashing iterating one time over arr and simultaneously finding target-arr[i] in the map which takes O(1) or O(logn) so T=O(nlogn or n) & S=O(n)
    // map<int,int> mpp;
    // for (int i=0;i<n;i++){
    //  if (mpp.find(target-arr[i])!=mpp.end()){ //find takes O(1) or O(N^2)
    //      int index = mpp[target - arr[i]];
    //      cout << "Found at index: " << index << " and " << i << endl;
    //  }else{
    //      mpp[arr[i]]=i;
    //  }
    // }
    // return "No";
    //Optimal:T=O(nlogn+n) & S=O(1) Two pointer Approach: first sort array and then move accrodingly the two pointers(best for variety 2 as changed the arr)
    int i=0,j=n-1;
    sort(arr,arr+n);
    while (i<j){
        if (arr[i]+arr[j]<target)i++;
        else if(arr[i]+arr[j]>target) j--;
        else return "Yes, of " + to_string(arr[i]) + " and " + to_string(arr[j]);
    }
    return "No";
}

void sortArrOf012(int arr[],int n){
    //Brute: Quick Sort lgao T=O(nlogn) & S=O(1);
    //Better: T=O(2n) & S=O(3) Hashing storing the freq of 0, 1 and 2
    // int temp[3] ={0};
    // for (int i=0;i<n;i++)temp[arr[i]]++;
    // for (int i=0;i<temp[0];i++)arr[i]=0;
    // for (int i=temp[0];i<temp[0]+temp[1];i++)arr[i]=1;
    // for (int i=temp[0]+temp[1];i<n;i++)arr[i]=2;
    //Optimal: Dutch National Algorithm T=O(N) & S=O(1)
    //elements before low are 0, after high are 2 and elements between low and mid is for 1 and mid is trash trader with low and high
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if (arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

}

string majorityElement(int arr[],int n){
    //Brute: T=O(n^2) & S=O(1) Two for loops checking and counting frq of each element 
    //Better: T=O(nlogn) & S=O(n) map element with freg and checking freq>n/2
    // map<int,int> mpp;
    // for (int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    //     if (mpp[arr[i]] > n / 2) {
    //         return arr[i];
    //     }     
    // }
    //Optimal: Moose's Voting Algorithm
    int cnt=0;
    int el;
    for (int i=0;i<n;i++){
        if (cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if (arr[i]==el)cnt++;
        else{
            cnt--;
        }
    }
    //ele we got is the candidate for majority element not the real majority element ex: {7,7,5,5,5,7,5,5,7,7,1,1,1,1}
    //checking if the el we got is majority number or not
    int cnt1=0;
    for (int i=0;i<n;i++){
        if (arr[i]==el)cnt1++;
    }
    if (cnt1>n/2){
        return to_string(el);
    }
    return "none";
}

string maxSubArrSum(int arr[],int n){
    //Brute: T=O(n^3) & S=O(1) Trying all subarrays sum and keeping the max sum
    // int maxSum=INT16_MIN;
    // for (int i=0;i<n;i++){
    //     for (int j=i;j<n;j++){
    //         int sum=0;
    //         for (int k=i;k<j;k++)sum+=arr[k];
    //         maxSum=max(maxSum,sum);
    //     }
    // }
    // return maxSum;

    //Better:T=O(n^2) & S=O(1) Trying all subarrays sum and keeping the max sum
    // int maxSum=INT16_MIN;
    // for (int i=0;i<n;i++){
    //     int sum=0;
    //     for (int j=i;j<n;j++){
    //         sum+=arr[j];
    //         maxSum=max(maxSum,sum);
    //     }
    // }
    // return maxSum;

    //Optimal: Kadane's Algorithm T=O(N) & S=O(1)
    int maxSum=INT16_MIN;
    int sum=0;
    int ansStart=0;
    int start=0;
    int ansEnd=n-1;
    for (int i=0;i<n;i++){
        if (sum==0)start=i;
        sum+=arr[i];
        if (sum>maxSum){
            maxSum=sum;
            ansStart=start;
            ansEnd=i;
        }
        if (sum<0)sum=0;//Agr start strip ka sum -ve ho gya to  leavekro use as net sum of strip is -ve so it is useless to have it
    }
    return (maxSum>0)?to_string(maxSum)+" from index "+to_string(ansStart)+" to "+to_string(ansEnd):"null sub array";
}

void stock(int arr[], int n){
    int maxProfit=0;
    int buy=0;
    int sell=0;
    int i=1;
    int min=0;
    while (i<n){
        if ((arr[i]-arr[min])>maxProfit){
            maxProfit=arr[i]-arr[min];
            buy = min;
            sell=i;
        }
        if (arr[i]<arr[min]){
            min=i;
        }
        i++;
    }
    cout<<"Buy at day "<<buy+1<<" & sell at day "<<sell+1<<" for max Profit i.e "<<arr[sell]-arr[buy];
}

void rearrangeEleBySign(int arr[],int n){
    //Brute: T=O(2n) & S=O(n) take a pos and neg arr and then put all pos and neg in them and traverse through arr and place the value alternatively in the arr from pos and neg (Best if unequal no. of pos and neg)
    vector<int> pos;
    vector<int> neg;
    for (int i=0;i<n;i++){
        if (arr[i]<0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }
    
    if (pos.size()>neg.size()){
        for (int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index = neg.size()*2;
        for (int i=neg.size(); i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }else{
        for (int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index = pos.size()*2;
        for (int i=pos.size(); i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }

    //Optimal: best for equal no. of pos and neg
    // vector<int> ans(n);
    // int a=0,b=1;
    // for (int i=0;i<n;i++){
    //     if (arr[i]>0){
    //         ans[a]=arr[i];
    //         a=a+2;
    //     }
    //     else {
    //         ans[b]=arr[i];
    //         b=b+2;
    //     }
    // }
    // return ans;
}

void permutation(int arr[],int n,map<int,int>& mpp,set<string>& st,string result=""){
    if (result.size()==n){
        st.insert(result);
        return;
    }
    for (int j=0;j<n;j++){
        if (mpp[j])continue;
        result+= to_string(arr[j]);
        mpp[j]=1;
        permutation(arr,n,mpp,st,result);
        mpp[j]=0;
        result.pop_back();
    }
}

void nextPermutation(int arr[],int n){
    //Brute: T=O(N!*N+N ) & S=O(N!*N+N) complexity get all permutations and keep them in sorted way and then find the one next to it
    // set<string> St;
    // map<int,int> mpp;
    // permutation(arr,n,mpp,St);
    // string str="";
    // for (int i=0;i<n;i++)str+=to_string(arr[i]);
    // auto it = St.find(str);
    // it++;
    // if ((it)==St.end()){cout<< *(St.begin());}
    // else cout<< *(it);

    //Better: Use STL next_permutation(A.begin(),A.end())

    //Optimal: 1) longer prefix arrch by checking from end and going towards starting if these subarray can be the changing one or isn't it in the max order. if yes then go further and if not split at that point
    //2) Find the number that is just greater than the split no. from that to end and then replace with it and then sort the elements after it towards end.
    int index=-1;
    for (int i=n-2; i>=0; i--){//O(n)
        if (arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if (index!=-1){
        int justGreater=index+1;
        for (int i=index+1;i<n;i++){//O(n)
            if (arr[justGreater]>arr[i] && arr[i]>arr[index]){
                justGreater=i;
            }
        }
        swap(arr[index],arr[justGreater]);
    }
    reverse(arr+index+1,arr+n);//O(n)
    for (int i=0;i<n;i++)cout<<arr[i]<<" ";
}

void Leaders(int arr[],int n){
    //Brute: T=O(N^2)For every element check the elements after it. if they are smaller than it then they are leader otherwise not

    //Optimal: T=O(N) & S=O(1) moving from right to left the lastLeader is always smaller than the coming leader
    // int lastLeader=arr[n-1];
    // cout<<lastLeader<<" ";
    // for (int i=n-2;i>=0;i--){
    //     if (arr[i]>lastLeader){
    //         lastLeader=arr[i];
    //         cout<<lastLeader<<" ";
    //     }
    // }
}

void longestSubseq(int arr[],int n){
    //Brute: T=O(n^3) & S(1) Trying for each element
    // int longest=1;
    // for (int i=0;i<n;i++){
    //     int cnt=1;
    //     int found=1;
    //     int j=1;
    //     while (found){
    //         found=0;
    //         int key=arr[i]+j;
    //         for (int k=0;k<n;k++){
    //             if (arr[k]==key){
    //                 found=1;
    //                 j++;
    //                 cnt++;
    //             }   
    //         }
    //     }
    //     longest=max(longest,cnt);
    // }
    // cout<<longest;

    //Better: T=O(nlogn + n) & S=O(1)
    // sort(arr,arr+n);
    // int lastSmaller=INT_MIN;
    // int cnt=0;
    // int longest=1;
    // for (int i=0; i<n; i++){
    //     if (arr[i]-1==lastSmaller){
    //         cnt++;
    //         lastSmaller=arr[i];
    //     }
    //     else if(lastSmaller!=arr[i]){
    //         cnt=1;
    //         lastSmaller=arr[i];
    //     }
    //     longest = max(longest, cnt);
    // }
    // cout<< longest;

    //Optimal: T=O(3N) & S=O(N) if a element is in middle of a subseq then no counting i.e checking if its previous element exists in set.
    unordered_set<int> st;
    int longest=1;
    for (int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    for (auto it: st){
        if (st.find(it - 1) == st.end()){
            int cnt=1;
            int x=it;
            while (st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest = max(longest, cnt);
        }
    }
    cout<<longest;
}

void markRow(vector<vector<int>>& arr,int m, int n,int i){
    for (int j=0;j<n;j++){
        if (arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}

void markCol(vector<vector<int>>& arr,int m, int n,int j){
    for (int i=0;i<m;i++){
        if (arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}

void setarrrixZero(vector<vector<int>>& arr,int m,int n){
    //Brute: T=O((n*m)(n+m) + (n*m)) almost n^3 & S=O(1)
    // for (int i=0;i<m;i++){
    //     for (int j=0;j<n;j++){
    //         if (arr[i][j]==0){
    //             markRow(arr,m,n,i);
    //             markCol(arr,m,n,j);
    //         }
    //     }
    // }

    // for (int i=0;i<m;i++){
    //     for (int j=0;j<n;j++){
    //         if (arr[i][j]==-1){
    //             arr[i][j]=0;
    //         }
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //Better: T=O(2*m*n) & S=O(m+n) Using a col & row array to store which row & column is going to be zero
    // int col[m]={0};
    // int row[n]={0};
    // for (int i=0; i<m;i++){
    //     for (int j=0;j<m;j++){
    //         if (arr[i][j]==0){
    //             row[i]=1;
    //             col[j]=1;
    //         }
    //     }
    // }
    // for (int i=0;i<m;i++){
    //     for (int j=0;j<n;j++){
    //         if (row[i] || col[j]){
    //             arr[i][j]=0;
    //         }
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //Optimal: T=O(2*m*n) & S=O(1)
    int col0=1;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (arr[i][j]==0){
                arr[i][0]=0;
                if (j!=0){
                    arr[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for (int i=1;i<m;i++){
        for (int j=1;j<n;j++){
            if (arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
            }
        }
    }
    if (!arr[0][0]){
        for (int j=1;j<n;j++){
            arr[0][j]=0;
        }
    }
    if (col0==0){
        for (int i=0;i<m;i++){
            arr[i][0]=0;
        }
    }
}

vector<vector<int>> rotateMatrix90(vector<vector<int>>& arr){
    //Brute: T=O(n^2) & S=O(n^2 )
    // vector<vector<int>> ans=arr;
    // int n = arr.size();
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         ans[j][n-1-i]=arr[i][j];
    //     }
    // }
    // return ans;

    //Optimal: T=O(n^2/2) & S=O(1) Do transpose and then reverse each row
    int n = arr.size();
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for (int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
}

void spiralMatrix(vector<vector<int>> arr){
    // Both T=O(mn) & S=O(1)
    // Mine:
    int m = arr.size();
    int n = arr[0].size();
    int layers = (min(m, n) + 1) / 2;

    for (int i = 0; i < layers; i++) {
        int row = i, col = i;

        // top row → right
        for (int a = col; a <= n - 1 - i; a++) {
            cout << arr[row][a] << " ";
            col = a;
        }

        // right column ↓
        for (int a = i + 1; a <= m - 1 - i; a++) {
            cout << arr[a][col] << " ";
            row = a;
        }

        // bottom row ←
        if (m - 1 - i > i) { // To avoid double printing in single row
            for (int a = col - 1; a >= i; a--) {
                cout << arr[row][a] << " ";
                col = a;
            }
        }

        // left column ↑
        if (n - 1 - i > i) { // To avoid double printing in single column
            for (int a = row - 1; a >= i + 1; a--) {
                cout << arr[a][col] << " ";
            }
        }
    }
    //Sir
    // int m = arr.size();
    // int n = arr[0].size();

    // int left = 0, right = n - 1;
    // int top = 0, bottom = m - 1;

    // vector<int> ans;

    // while (top <= bottom && left <= right) {
    //     // move right
    //     for (int i = left; i <= right; i++) {
    //         ans.push_back(arr[top][i]);
    //     }
    //     top++;

    //     // move down
    //     for (int i = top; i <= bottom; i++) {
    //         ans.push_back(arr[i][right]);
    //     }
    //     right--;

    //     // move left
    //     if (top <= bottom) {
    //         for (int i = right; i >= left; i--) {
    //             ans.push_back(arr[bottom][i]);
    //         }
    //         bottom--;
    //     }

    //     // move up
    //     if (left <= right) {
    //         for (int i = bottom; i >= top; i--) {
    //             ans.push_back(arr[i][left]);
    //         }
    //         left++;
    //     }
    // }

    // return ans;
}

int countSubArrWithSumK(vector<int>& arr, int k){
    //Brute : Trying all subarray sum T=O(n^3) & S=O(1)
    //Better: Trying all subarray sum but managing sum while travelling T=O(n^2) & S=O(1)
    //Optimal: T=O(nlogn) & S=O(n) By PreSum Concept
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0,cnt=0;
    for (int i=0;i<arr.size();i++){
        preSum+=arr[i];
        int remove = preSum -k;
        cnt+= mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
    // special example {3,-3,1,1,1}
}

int countSubArrWithXORK(vector<int>& arr, int k){
    //Brute : Trying all subarray XOR's T=O(n^3) & S=O(1)
    //Better: Trying all subarray XOR's but managing XOR while travelling T=O(n^2) & S=O(1)
    //Optimal: T=O(nlogn) & S=O(n) By PreSum Concept XOR has this cool reversible property:If:  A ^ B = C (A+B=C) ,Then: C ^ B = A (C-B=A)

    map<int,int> mpp;
    mpp[0]=1;
    int xr=0,cnt=0;
    for (int i=0;i<arr.size();i++){
        xr^=arr[i];
        int remove = xr^k;
        cnt+= mpp[remove];
        mpp[xr]+=1;
    }
    return cnt;
    // special example {3,-3,1,1,1}
}

int combination(int n,int r){
    //Brute: calculate n!,r! and then (n-r)! and then calculate
    //T=O(r)
    int res=1;
    for (int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

vector<int> pascalRow(int r){
    //Brute: calculate all C(n,r) in a row T=O(r^2)
    //T=O(r)
    vector<int> row;
    int res=1;
    row.push_back(res);
    for (int i=1;i<=r;i++){
        res*=(r-i+1);
        res/=i;
        row.push_back(res);
    }
    return row;
}

vector<vector<int>> pascalTriangle(int h){
    //T=O(h^2)
    vector<vector<int>> ans;
    for (int i=0;i<h;i++){
        vector<int> row=pascalRow(i);
        ans.push_back(row);
    }
    return ans;

}

vector<int> majorityEle2(vector<int> v){
    //Brute : T=O(n^2) & O(1) checking frequency for each element(>(n/3)) and storing the outputs in a array and if size of array reaches 2 we break;

    //Better: T=O(nlogn or n) & S=O(n) Keeping a map that stores the frequency of each no. and while increasing freq check if it crosses n/3 then add it to our ans
    // vector<int> ans;
    // map<int,int> mpp;
    // int min = v.size()/3 +1;
    // for (int i=0;i<v.size();i++){
    //     mpp[v[i]]++;
    //     if (mpp[v[i]]==min){
    //         ans.push_back(v[i]);
    //     }
    //     if (ans.size()==2)break;
    // }
    // sort(ans.begin(), ans.end()); //O(1) as size 2
    // return ans;

    //Optimal: T=O(2n) & S=O(1) max counter approach ki max itne ho skte h to itne leke chalte h or ginte h agr dono me se koi nhi h koi no. to tabhi dono ke count ghtao, agr dono zero ho gye mtlb perfect 3 hise hue h
    vector<int> ans;
    int cnt1=0,cnt2=0;
    int ele1=INT_MIN,ele2=INT_MIN;
    for (int i=0;i<v.size();i++){
        if (cnt1==0 && ele2!=v[i]){
            cnt1=1;
            ele1=v[i];
        }
        else if(cnt2==0 && ele1!=v[i]){
            cnt2=1;
            ele2 = v[i];
        }
        else if (v[i]==ele1)cnt1++;
        else if (v[i]==ele2)cnt2++;
        // Jb dono me se koi nhi to iska mtlb koi tisra sher ho skta h
        // agr in dono ke alawa vale n/3 se kam h to ye 0 ni bnege or agr jyada h to inme se koi zero bn skta h
        else{ 
            cnt1--;  
            cnt2--;
        }
    }
    cnt1=0,cnt2=0;
    for (int i=0;i<v.size();i++){
        if (ele1==v[i])cnt1++;
        if (ele2==v[i])cnt2++;
    }
    int min = v.size()/3 +1;
    if (cnt1>=min)ans.push_back(ele1);
    if (cnt2>=min)ans.push_back(ele2);

    sort(ans.begin(), ans.end()); //O(1) as size 2
    return ans;
}

vector<vector<int>> threeSum(vector<int> v){
    int n=v.size();
    set<vector<int>> st;
    //Brute: T=O(n^3) & S=O(no. of triplets)
    // for (int i=0;i<n-2;i++){
    //     for (int j=i+1;j<n-1;j++){
    //         for (int k=j+1;k<n;k++){
    //             if (v[i]+v[j]+v[k]==0){
    //                 vector<int> ans={v[i],v[j],v[k]};
    //                 sort(ans.begin(),ans.end());
    //                 st.insert(ans);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //Better: T=O(n^2*logm or n^2) & S=O(n)+O(no. of triplets)
    // for (int i=0;i<n-2;i++){
    //     set<int> hashset;
    //     for (int j=i+1;j<n-1;j++){
    //         int third = -(v[i]+v[j]);
    //         if (hashset.find(third)!=hashset.end()){
    //             vector<int> temp = {v[i],v[j],third};
    //             sort(temp.begin(),temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(v[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //Optimal: T=O(nlogn + n^2) & S=O(1) Is tarah ki problem me pointer approach bahot kaam aate h jaha hum apne set ko sort bhi kr ske or hume pata bhi ho ki hame kya sum chahiye
    vector<vector<int>> ans;
    for (int i=0;i<n;i++){
        if (i>0 && v[i]==v[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while (j<k){
            int sum=v[i]+v[j]+v[k];
            if (sum<0)j++;
            else if (sum>0)k--;
            else{
                vector<int> temp={v[i],v[j],v[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && v[j]==v[j-1])j++;
                while(j<k && v[k]==v[k+1])k--;
            }
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> nums,int target){
    //Brute: T=O(n^4) & S=O(no. of quantruplets) using 4 for loops for getting each variable possible value and inserting the target sum ones in set

    //Better: T=O(n^3logm or n^3) & S=O(n)+O(no. of Quantruplets) checking l in a hashset between j and k , as arr[l]=target-(arr[i]+arr[j]+arr[k])
    // int n = nums.size();
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         unordered_set<long long> hashset;
    //         for (int k = j + 1; k < n; k++) {
    //             long long sum = (long long)nums[i] + nums[j] + nums[k];
    //             long long fourth = (long long)target - sum;

    //             if (hashset.find(fourth) != hashset.end()) {
    //                 vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
    //                 sort(quad.begin(), quad.end());
    //                 st.insert(quad);
    //             }

    //             hashset.insert(nums[k]);
    //         }
    //     }
    // }

    // return vector<vector<int>>(st.begin(), st.end());

    //Optimal: T=O(n^3) & S=O(1) Like in 3Sum Sort and then make it for j and then for i
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int i=0; i<n;i++){
        if (i>0 && nums[i]==nums[i-1])continue;
        for (int j=i+1;j<n;j++){
            if (j!=(i+1) && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum= nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if (sum==target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while (k<l && nums[l]== nums[l+1])l--;
                }
                else if(sum <target)k++;
                else l--;
            }
        }
    }
    return ans;
}

int LongestSubArrWith0Sum(int arr[], int n){
    //Brute and //Better same as LongestSubArrOfSumK()
    //Optimal: T=O(nlogn) & S=O(n)
    unordered_map<int,int> mpp;
    int maxCnt = 0;
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=arr[i];
        if (sum==0){
            maxCnt=i+1;
        }
        else {
            if (mpp.find(sum)!=mpp.end()){
                maxCnt= max(maxCnt,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
    }
}

vector<vector<int>> mergeOverlappingSubIntervals(vector<vector<int>> v){
    //Brute: T=O(n*logn + 2n) & S=O(1) sorting the intervals and then for each pair checking if the pairs after it are overlapping or not
    // vector<vector<int>> ans;
    // sort(v.begin(),v.end());
    // int n=v.size();
    // for (int i=0;i<n;i++){
    //     int start = v[i][0];
    //     int end =v[i][1];
    //     if (ans.empty() || end>ans.back()[1]){
    //         for (int j=i+1;j<n;j++){
    //             if (v[j][0]<=end) end = max(end,v[j][1]);
    //             else break;
    //         }
    //         ans.push_back({start,end});
    //     }  
    // }
    // return ans;

    //Optimal: T=O(nlogn + n) & S=O(1) sorting and checking and goinng in one go
    if (v.empty()) return {};

    // Sort intervals by starting time
    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    ans.push_back(v[0]);

    for (int i = 1; i < v.size(); i++) {
        // Compare current interval with the last merged interval
        if (v[i][0] <= ans.back()[1]) {
            // Merge intervals
            ans.back()[1] = max(ans.back()[1], v[i][1]);
        } else {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

void merge2SortdArrWithoutExtraSpace(int arr1[],int n,int arr2[],int m){
    //Optimal1: T=O(min(n,m) + O(nlogn) + O(mlogm)) & S=O(1)
    // int left=n-1,right=0;
    // while (left>=0 && right<m){
    //     if (arr1[left]>arr2[right]){
    //         swap(arr1[left],arr2[right]);
    //         left--;
    //         right++;
    //     }else break;
    // }
    // sort(arr1, arr1+n);
    // sort(arr2, arr2+m);
    //Optimal2: Gap Method T=O((n+m)log(n+m)) 
    int len = n+m;
    int gap = len/2 + len%2;
    while(gap>0){
        int left=0,right=left+gap;
        while (right<len){
            if (left<n && right<n){
                if (arr1[left]>arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }else if(left<n && right>=n){
                if (arr1[left]>arr2[right-n]){
                    swap(arr1[left],arr2[right-n]);
                }
            }else{
                if (arr2[left-n]>arr2[right-n]){
                    swap(arr2[left-n],arr2[right-n]);
                }
            }
            left++;
            right++;
        }
        if (gap == 1) break;
        gap=gap/2 + gap%2;
    }
}

vector<int> missingAndRepeatingNum(int a[],int n){
    //Brute: T=O(n^2) & S=O(1) Checking cnt for each number and if its 0 then missing and if its 2 then it is then repeating
    //Better: T=O(2n) & S=O(n) using hashing and chekcing whose freq is 0 and whose 2
    //Optimal:(1)  Maths
    // int Sn=(n*(n+1))/2;
    // int S2n = (n*(n+1)*(2*n+1))/6;
    // int S = 0,S2=0;
    // for (int i=0;i<n;i++){
    //     S+=a[i];
    //     S2+=a[i]*a[i];
    // }
    // int val1=S-Sn;
    // int val2=S2-S2n;
    // val2/=val1;
    // int x = (val1 + val2)/2;
    // int y=x-val1;
    // return {y,x};
    //(2) T=O(3n) & S=O(1)
    int xr=0;
    for (int i=0;i<n;i++){
        xr^=a[i];
        xr^=(i+1);
    }
    //Or 1<<bitNo can be done by num = xr&~(xr-1)
    int bitNo=0;
    while(1){
        if ((xr&(1<<bitNo))!=0){
            break;
        }
        bitNo++;
    }
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & (1 << bitNo)) != 0) one ^= a[i];
        else zero ^= a[i];

        if (((i + 1) & (1 << bitNo)) != 0) one ^= (i + 1);
        else zero ^= (i + 1);
    }

    int cnt=0;
    for (int i=0;i<n;i++){
        if (a[i]==zero)cnt++;
    }
    if (cnt==2) return {one,zero};
    return {zero, one};
}

void merge(vector<int> &v, int st,int end,int& cnt){
    int mid = (st + end) / 2;
    vector<int> sorted(end - st + 1);
    int i = st, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            sorted[k++] = v[i++];
        } else {
            sorted[k++] = v[j++];
            cnt+=mid-i+1;
        }
    }

    while (i <= mid) sorted[k++] = v[i++];
    while (j <= end) sorted[k++] = v[j++];

    for (int a = st; a <= end; a++) {
        v[a] = sorted[a - st];
    }
}
void mergeSrt(vector<int> &v, int st,int end,int& cnt){
    if (st>=end)return;
    int mid = (st+end)/2;
    mergeSrt(v,st,mid,cnt);
    mergeSrt(v,mid+1,end,cnt);
    merge(v,st,end,cnt);
}
int countInversions(vector<int> v){ 
    //Inversions are pairs where i<j but arr[i]>arr[j]
    //Brute: T=O(n^2) & S=O(1) for each element I go all elements after it
    //Optimal: T=O(nlogn) & S=O(n or 2n) (to avoid changing the array) calculating no. of pairs in two sorted left and right arrays (left array ele , right array ele)in which all pairs in each particular array is already counted.
    int cnt=0;
    mergeSrt(v,0,v.size()-1,cnt);
    return cnt;
}

void merge_(vector<int> &v, int st,int end,int& cnt){
    int mid = (st + end) / 2;
    vector<int> sorted(end - st + 1);
    int i = st, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (v[i] > 2*v[j]) {
            cnt+=(mid-i+1);
            j++;
        } else {
            i++;
        }
    }

    i = st;
    j = mid + 1;
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
void mergeSrt_(vector<int> &v, int st,int end,int& cnt){
    if (st>=end)return;
    int mid = (st+end)/2;
    mergeSrt_(v,st,mid,cnt);
    mergeSrt_(v,mid+1,end,cnt);
    merge_(v,st,end,cnt);
}
int reversePairs(vector<int>& v){
    //i<j and a[i]>2*arr[j]
    //Brute: T=O(n^2) & S=O(1) for each element I go all elements after it
    //Optimal: T=O(2nlogn) & S=O(n or 2n) (to avoid changing the array) calculating no. of pairs in two sorted left and right arrays (left array ele , right array ele)in which all pairs in each particular array is already counted.
    int cnt=0;
    mergeSrt_(v,0,v.size()-1,cnt);
    return cnt;
}

int maximumProductSubArr(vector<int> v){
    //Brute: T=O(n^3) & S=O(1) Trying all subarrays product and keeping the max product

    //Better:T=O(n^2) & S=O(1) Trying all subarrays product and keeping the max product while travelling in second loop

    //Optimal:(1) T=O(n) & S=O(1)
    // int pre=1, suff=1;
    // int ans=INT_MIN;
    // int n=v.size();
    // for (int i=0;i<n;i++){
    //     if (pre==0) pre=1;
    //     if (suff==0) suff=1;
    //     pre=pre*v[i];
    //     suff=suff*v[n-i-1];
    //     ans=max(ans,max(pre,suff));
    // }
    // return ans;
    //(2) maxProd managing max product and minProduct managing min product (managing negative*negative possibility) and when 0 comes it becomes 0 to check from starting and <0 swaps the min and max 
    int n = v.size();
    int maxProd = v[0];
    int minProd = v[0];
    int result = v[0];

    for (int i = 1; i < n; i++) {
        int curr = v[i];

        // If current is negative, swap max and min
        if (curr < 0) swap(maxProd, minProd);

        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        result = max(result, maxProd);
    }

    return result;
}

int main(){
    vector<int> arr = {5,3,-2,4,0,2,-1};
    cout<<maximumProductSubArr(arr); 
    return 0;
}
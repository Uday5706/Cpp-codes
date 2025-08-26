#include <bits/stdc++.h>
using namespace std;
// These all aplies to Srtd Array
int rec_BinarySearch(vector<int> &v, int st, int end, int key){
    // T=O(logn)
    if (st > end)
        return -1;
    // int mid = (st+end)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
    int mid = st + (end - st) / 2; // so that it desn't cross INT_MAX otherwise use long long
    if (v[mid] < key)
        return rec_BinarySearch(v, mid + 1, end, key);
    else if (v[mid] > key)
        return rec_BinarySearch(v, st, mid - 1, key);
    else
        return mid;
}

int iter_BinarySearch(vector<int> &v, int key){
    // T=O(logn)
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] < key))
            low = mid + 1;
        else if (v[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int lowerBound(vector<int> &v, int key){
    // Smallest Index such that v[ind]>=key
    // Brute = T=O(n) Linear Search
    // OR return lower_bound(v.begin(), v.end(), key) - v.begin()
    // Optimal: T=O(logn) Think like when search space is sorted, use binary Search
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] < key))
            low = mid + 1;
        else if (v[mid] >= key){
            high = mid - 1;
        }
    }
    return low;
}

int upperBound(vector<int> &v, int key){
    // Smallest Index such that v[ind]>key
    // Brute = T=O(n) Linear Search
    //OR return upper_bound(v.begin(),v.end(),key)-v.begin()
    // Optimal:  Think like when search space is sorted, use binary Search
    int low = 0, high = v.size() - 1;
    
    while (low <= high){
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] <= key))
            low = mid + 1;
        else if (v[mid] > key){
            high = mid - 1;
        
        }
    }
    return low;
}

int searchInsertPosition(vector<int> v,int key){
    //Indirectly lowerBound
    // T=O(logn)
    int low = 0, high = v.size() - 1;
    while (low <= high){
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        
        if ((v[mid] < key)){
            low = mid + 1;
        }
        else if (v[mid] > key){
            high = mid - 1;
        }
        else
            return mid;
    }
    return low;
    //OR 
    return lowerBound(v,key)==-1?v.size():lowerBound(v,key);
}

vector<int> floorCeil(vector<int>& v, int key){
    //floor: largest num<=x
    int low = 0, high = v.size() - 1;
    int floor = -1;
    while (low <= high)
    {
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] <= key)){
            floor=mid;
            low = mid + 1;
        }
        else if (v[mid] > key) high = mid - 1;
        
    }
    // return {v[floor],v[lowerBound(v,key)]};
    //OR 
    return {v[high],v[low]};
}

vector<int> firstAndLastOccurence(vector<int> v,int x){
    //Brute: T=O(n) & S=O(1)
    // int first=-1,last=-1;
    // for (int i=0;i<v.size();i++){
    //     if (v[i]==x){
    //         if (first==-1) first = i;
    //         last=i;
    //     }
    // }

    //Better: T=O(2logn) & S=O(1)
    // int lb = lowerBound(v,x);
    // if ((lb==v.size()) || (lb!=x)) return {-1,-1};
    // return {lb,upperBound(v,x)-1};

    //OR
    //{first occurence}
    int low=0,high=v.size()-1;
    int first=-1;

    while (low<=high){
        int mid = low+(high-low)/2;
        if (v[mid]==x){
            first=mid;
            high=mid-1;
        }
        else if(v[mid]<x)low=mid+1;
        else high = mid-1;
    }

    if (first==-1) return {-1,-1};
    
    //{last occurence}
    low=0;
    high=v.size()-1;
    int last=-1;

    while (low<=high){
        int mid = low+(high-low)/2;
        if (v[mid]==x){
            last=mid;
            low=mid+1;
        }
        else if(v[mid]<x)low=mid+1;
        else high = mid-1;
    }

    return {first, last};
}

int countOccurenceSrtdArr(vector<int> v,int x){
    //Brute: T=O(n) Linear Search
    //Optimal:
    vector<int> temp = firstAndLastOccurence(v,x);
    return temp[1]-temp[0] +1;
}

int searchElementRotatedSrtdArr(vector<int> v, int x){
    //Brute: Linear Search
    //Better: T=O(logn) Binary Search Identifying which half to eliminate by identifying the sorted part and checking if  x is in that part or not by using upper and lower index of that half (Fails when duplicates)
    // int low=0, high=v.size()-1;
    // while(low<=high){
    //     int mid = low+(high-low)/2;
    //     if (v[mid]==x) return mid;
    //     else if(v[mid]<=v[high]){
    //         if (v[mid]<=x && x<=v[high]) low=mid+1;
    //         else high=mid-1;
    //     }
    //     else{
    //         if (v[low]<=x && x<=v[mid]) high=mid-1;
    //         else low=mid+1;
    //     }
    // }
    // return -1;
    
    //Optimal: T=O(n/2) & avg(logn) Fails when v[low]=v[mid]=v[high] It is unable to identify the sorted part so we reduce the searchjing space by reducing high and increasing low and then going again. Thinking is that check the failure case of unique case and treat that failure case separately
    int low=0, high=v.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if (v[mid]==x) return mid;
        if (v[mid]==v[low] && v[mid]==v[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        else if(v[mid]<=v[high]){
            if (v[mid]<=x && x<=v[high]) low=mid+1;
            else high=mid-1;
        }
        else{
            if (v[low]<=x && x<=v[mid]) high=mid-1;
            else low=mid+1;
        }
    }
    return -1;
}

int minEleRotatedSrtdArr(vector<int> v){
    //jaha unsorted h vahi se to sorted arr ki shuruat hui hogi
    // int low=0, high=v.size()-1;
    // int ans=0;
    // while(low<high){
    //     int mid = low+(high-low)/2;
    //     if (v[mid]>v[high]){
    //         low=mid+1;
    //     }
    //     else if(v[mid]<v[high]){
    //         high=mid;
    //     }
    //     else{
    //         high--;
    //     }
    // }
    // return low;
    int low = 0, high = v.size() - 1;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Handle duplicates: can't determine which half is sorted
        if (v[low] == v[mid] && v[mid] == v[high]) {
            if (v[mid] < v[ans]) ans = mid;
            low++;
            high--;
            continue;
        }
        if (v[low]<v[high]){
            cout<<"Ab sorted h bhai to print kr rha hu\n";
            return low;
        } 
        // Left half is sorted
        if (v[low] <= v[mid]) {
            if (v[low] < v[ans]) ans = low;
            low = mid + 1;
        }
        // Right half is sorted
        else {
            if (v[mid] < v[ans]) ans = mid;
            high = mid - 1;
        }
    }
    cout<<"Last me jaake mila h\n";
    return ans;
}

int timesRotated(vector<int> v){
    //Find min Element
    int low=0, high=v.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if (v[mid]>v[high]){
            low=mid+1;
        }
        else if(v[mid]<v[high]){
            high=mid;
        }
        else{
            high--;
        }
    }
    if (low<=v.size()/2) return low; //right rotate
    return low-v.size(); //leftrotate
}

int singleEleSrtdArr(vector<int> v){
    //Brute: O(n) checking for edge cases i=0 and n-1 and if for any i arr[i-1]!=arr[i] && arr[i]!=arr[i-1] return it and if n=1 return arr[0]

    //Better: O(log2n) observation: onm left side of single ele pairs index are (even,odd) and on right side it is (odd,even) so by checking our current pair we can choose which side to move.
    int n=v.size();
    if (n==1)return v[0];
    if (v[0]!=v[1])return v[0];
    if (v[n-2]!=v[n-1])return v[n-1];
    int low=1,high=n-2;
    
    while(low<=high){
        int mid = low+(high-low)/2;
        if (v[mid-1]!=v[mid] && v[mid]!=v[mid+1]) return v[mid];
        if (mid%2==0){
            if (v[mid]==v[mid+1])low=mid+1;
            else high=mid-1;
        }
        else {
            if (v[mid]==v[mid+1])high=mid-1;
            else low=mid+1;
        }
    }
    return -1;
}

int findPeakElement(vector<int> v){
    //Brute: Linear search for an ele which is greater than it neighbours and for edge cases assume at -1 and n there is -infinity
    //better : T=O(logn) if multiple peaks give a random peak
    int n=v.size();
    if (n==1) return 0;
    if (v[0]>v[1])return 0;
    if (v[n-1]>v[n-2])return n-1;

    int low=1, high = n-2;
    while (low<=high){
        int mid=(low+high)/2;
        if (v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            return mid;
        }
        else if(v[mid]>v[mid-1]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int squareRoot(int n2){
    //brute : T=O(n/2)
    //OPtimal: T=O(log(n/2)
    if (n2==1)return 1;
    int low=0;
    int high=(n2<=3)?n2:n2/2;
    // cout<<high;
    while (low<=high){
        int mid = low+(high-low)/2;
        // cout<<mid<<endl;
        int mid2=mid*mid;
        // cout<<mid2<<endl;
        if (mid2==n2)return mid;
        else if(mid2>n2){
            high=mid-1;
            // cout<<high<<endl;
        }
        else{
             low=mid+1;
            //  cout<<low<<endl;
        }
    }
    return high;
}

long long power(long long x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    long long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            if (ans > LLONG_MAX / x) return LLONG_MAX; // prevent overflow
            ans *= x;
        }
        if (n > 1) { // only square if more multiplications left
            if (x != 0 && llabs(x) > LLONG_MAX / llabs(x)) return LLONG_MAX; // prevent overflow in x*x
            x *= x;
        }
        n /= 2;
    }
    return ans;
}
int kthRoot(int n, int k){
    //Brute: T=O(n)
    //Better: T=O(logn)
    if (k==1)return n;
    int low=0;
    int high=(n<=3)?n:n/2;
    while (low<=high){
        int mid = low+(high-low)/2;
        long long mid2=1;
        for (int i=0;i<k;i++){ // or power function which changes the complexity to logn*logk
            mid2*=mid;
            //overflow check
            if (mid2>n) break;
        }
        if (mid2==n)return mid;
        else if(mid2>n){
            high=mid-1;
        }
        else{
             low=mid+1;
        }
    }
    return high;// returning floor value
}

int maxEle(int piles[], int n){
    int max = piles[0];
    for (int i = 1; i < n; i++){
        if (piles[i] > max)
            max = piles[i];
    }
    return max;
}
int totalHrs(int piles[],int n, int bananaPerHr){
    int totalHrs=0;
    for (int i=0;i<n;i++){
        totalHrs+=(piles[i]/bananaPerHr +1);
    }
    return totalHrs;
}
int kokoEatingBananas(int piles[],int n, int h){
    //Brute: T=O(n) checking form min 1 and calculating the totalHrs for every rate and the giving the first valid ans
    for (int i=1;i<=maxEle(piles,n);i++){
        if (totalHrs(piles,n, i)<=h)return i;
    }

    //Better: T=O(log(maxEle)*n) Binary Search between 1 and maxEle 
    //pattern- {x,x,x,o,o,o,o,o,o,o,o} Since initially i is in acceptable area & low in wrong area at last they will be at opposite area thus low will be answer.
    int low=1, high=maxEle(piles,n);
    while (low<=high){
        int mid = low +(high-low)/2;
        if (totalHrs(piles,n,mid)<=h)high=mid-1;
        else low=mid+1;
    }
    return low;
}

pair<int, int> getMinMax(const int bloomDay[], int n) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (bloomDay[i] < mn) mn = bloomDay[i];
        if (bloomDay[i] > mx) mx = bloomDay[i];
    }
    return {mn, mx};
}
int bouqetPossible(int bloomDay[],int n,int m, int k, int day){
    int flowers=0,bouqets=0;
    for (int i =0;i<n;i++){
        if (bloomDay[i]<=day)flowers+=1;
        else flowers=0;
        if (flowers==k){
            bouqets+=1;
            flowers=0;
        }
        if (bouqets==m)return 1;
    }
    return 0;
}
int minDaysMBouqets(int bloomDay[],int n, int m, int k){
    // k= no. of adjacent flowers to make a bouqet
    long long val = m*1LL*k*1LL;// to prevent overflow
    if (n<val)return -1;
    pair<int, int> minMax = getMinMax(bloomDay, n);
    
    //Brute: O((max-min+1)*n) checking from day min(bloomDay) to max(bloomDay)
    // int mn = minMax.first;
    // int mx = minMax.second;
    // for (int i=mn;i<=mx;i++){
    //     if (bouqetPossible(bloomDay, n ,m,k,i))return i;
    // }

    //Better: O(n*log(max-min+1)) BinarySearch on range of no. of days 
    //pattern- {x,x,x,x,x,x,x,o,o,o,o} since ans is on high side so low will be ans
    int low=minMax.first,high=minMax.second;
    while(low<=high){
        int mid = low +(high-low)/2;
        if (bouqetPossible(bloomDay,n,m,k,mid))high=mid-1;
        else low=mid+1;
    }
    return low;
}

int Days(vector<int> weights, int capacity){
    int weight=0,Day=0;
    for (int w:weights){
        if (weight+w<=capacity){
            weight+=w;
        }
        else{
            Day+=1;
            weight=w;
        }
    }
    if (weight!=0)Day+=1; //or assume day = 1 from starting
    return Day;
}
int shipPackaging(vector<int> weights, int D){
    //Brute: O(n*(sum-max))
    //Better: O(n*log(sum-max))
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid = low+(high-low)/2;
        if (Days(weights,mid)<=D)high=mid-1;
        else low=mid+1;
    }
    return low;
}

int kthMissingNo(vector<int> nums, int k){ //nums sorted h
    //Given an array arr of positive integers sorted in a strictly increasing order, and an integer k. Return the kth positive integer that is missing from this array.

    //Brute: T=O(n) agr koi number aaya hua k se chota h mtlb vo ab k tk aane wale number me se ek kam ho gya isliye k ko aur badhna padega taaki kth missing number mile
    // for  (int i:nums){
    //     if (i<=k)k++;
    //     else break;
    // }
    // return k;

    //Better: T=O(logn) agr koi number missing nhi hota to vo {1,2,3,4,...}to agr mujhe janna h ki ek index tk kitne number missing h to vo mujhe nums[i]-(i+1) dega 
    int low = 0, high = nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing = nums[mid]-(mid+1);
        if (missing<k)low=mid+1;
        else high=mid-1;
    }
    return k+high+1;  //nums[high]+(k-(nums[high]-(high+1)))

}

int minConsecutiveDiff(vector<int>& arr) {
    if (arr.size() < 2) return -1; // not enough elements
    
    int minDiff = INT_MAX;
    for (int i = 1; i < arr.size(); i++) {
        minDiff = min(minDiff, arr[i] - arr[i-1]);
    }
    return minDiff;
}
bool canPlace(const vector<int> &stalls, int cows,int minDis){
    int j=1,lastCow=stalls[0]; //index of last cow
    for (int i=1;i<stalls.size() && j<cows;i++ ){
        if (stalls[i]-lastCow>=minDis){
            j++;
            lastCow=stalls[i];
        }else{
            continue;
        }
    }
    return j==cows;
}
int AggressiveCows(vector<int> stalls, int cows){
    sort(stalls.begin(),stalls.end());
    //Brute:  O(n*(stalls[n-1]-stalls[0])) checking min dist answers from 1 to max possible dist
    //pattern : {o,o,o,o,x,x,x,x,x} if that minDist is possible or not
    // int maxMinDis=1;
    // for (int i=minConsecutiveDiff(stalls);i<=stalls[stalls.size()-1]-stalls[0];i++){
    //     if (canPlace(stalls,cows, i)) maxMinDis=i;
    //     else break;
    // }
    // return maxMinDis;
    //Better : O(n*log(stalls[n-1]-stalls[0])) Binary Search on Answers {o,o,o,o,x,x,x,x}
    int low=minConsecutiveDiff(stalls),high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid = low+(high-low)/2;
        if (canPlace(stalls,cows, mid))low=mid+1;
        else high=mid-1;
    }
    return high;
}

int studentsAllocated(const vector<int> &books, int minMaxPages){
    int j=1,totalPages=0;
    for (int pages:books){
        if (totalPages+pages<=minMaxPages){
            totalPages+=pages;        
        }else{
            totalPages=pages;
            j++;
        }
    }
    return j; //Each student should get atleast one book
}
int allocateBooks(vector<int> books, int students){
    if (students>books.size()) return -1;
    //Brute: O(n*(sum-max+1)) in case if students = books.size() lowest answer = max(books) and if students = 1 highest answer = sum(books) pattern : {x,x,x,x,o,o,o,o,o,o,o} so implement linear search on answers by checking if this no. min pages can be maintained or not.
    // for (int i=*max_element(books.begin(),books.end());i<=accumulate(books.begin(),books.end(),0);i++){
    //     if (studentsAllocated(books, mid)==students)return i;
    // }

    //Better: O(n*log(sum-max+1))  BS on answers
    int low = *max_element(books.begin(),books.end()), high = accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid = low+(high-low)/2;
        if (studentsAllocated(books, mid)<=students)high=mid-1;
        else low=mid+1;
    }
    return low;
}

int paintersReq(const vector<int>& boards, int minTime) {
        int j = 1, totalTime = 0;
        for (int time : boards) {
            if (totalTime + time <= minTime) {
                totalTime += time;
            } else {
                totalTime = time;
                j++;
            }
        }
        return j; //may require less than k
    }
int painterPartition(vector<int> &boards, int k){
    return allocateBooks(boards,k); //same type of problem min(max)
    //OR
    if (k > boards.size())
            return -1;
        int low = *max_element(boards.begin(), boards.end()),
            high = accumulate(boards.begin(), boards.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (paintersReq(boards, mid) <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
}

int numberOfGasStationRequired( const vector<int> &stations,long double dist){
    int cnt=0;
    for (int i=1;i<stations.size();i++){
        int numberInBetween = ceil((stations[i] - stations[i-1]) / dist) - 1;
        cnt+=numberInBetween;
    }
    return cnt;
}
long double minMaxDistGasStations(vector<int> stations, int k){
    int n = stations.size();
    //stations sorted h
    //Brute: T=O(n*k) S=O(n)
    // vector<int> sections(n-1,1);// Each gap starts as 1 section
    // // Place k gas stations
    // for (int station=0;station<k;station++){
    //     long double maxDiff=-1;
    //     int maxInd=-1;
    //     // Find the section with the maximum distance
    //     for (int i=0;i<n-1;i++){
    //         long double diff= (stations[i+1]-stations[i])/sections[i];
    //         if (maxDiff<diff){
    //             maxDiff=diff;
    //             maxInd=i;
    //         }
    //     }
    //     // Add a station (increase divisions in that gap)
    //     sections[maxInd]++;
    // }
    // // Find the maximum distance after placements
    // long double maxDiff=-1;
    // for (int i=0;i<n-1;i++){
    //     long double diff= (stations[i+1]-stations[i])/sections[i];
    //         if (maxDiff<diff){
    //             maxDiff=diff;
    //         }
    // }
    // return maxDiff;

    //Better: T=O(NlogN + klogN) & S=O(2*(n-1))
    // vector<int> sections(n-1,1);// Each gap starts as 1 section
    // priority_queue<pair<long double, int>> pq;
    // for (int i=0; i<n-1;i++){ //nlogn
    //     pq.push({stations[i+1]-stations[i],i});
    // }
    // // Place k gas stations
    // for (int station=0;station<k;station++){ //klogn
    //     auto tp=pq.top();pq.pop();
    //     int secInd=tp.second;
    //     sections[secInd]++;
    //     long double iniDiff = stations[secInd+1]-stations[secInd];
    //     long double newSecLen = iniDiff/(long double)(sections[secInd]);
    //     pq.push({newSecLen,secInd}); //logn
    // }
    // return pq.top().first;

    //Optimal: Binary Search on answers since here long double can be answer too we will use a different answer
    long double low=0;
    long double high = 0;
    for (int i=0;i<n-1;i++){
        high=max(high,(long double)(stations[i+1]-stations[i]));
    }

    long double diff = 1e-6;
    while (high-low>diff){
        long double mid=(low+high)/(2.0);
        int cnt = numberOfGasStationRequired(stations,mid);
        if (cnt>k)low=mid;
        else high=mid;
    }
    return high;
}

int medianOf2SrtedArr(vector<int> &a, vector<int> &b){
    //Brute: T=O(n+m) & S=O(n+m) Merge two vectors like in merge sort and then use median formula for even and odd length
    //Better : T=O(n+m) & S=O(1) Instead of merging create a cnt variable and when its time to add the number in merged array , cnt++ and when cnt == (n+m)/2 and (n+m)/2-1 then save them and then according to length of n+m return median by formula.
    //Optimal: T=O(min(logn1,logn2)) & S=O(1) Using Binary Search on answers by taking answers as no. of elements of a in left part of merged srtd array and whichever satisfies condition gets selected and then answered accordingly.
    int n1=a.size();
    int n2 = b.size();
    if (n1>n2)return medianOf2SrtedArr(b,a);
    int low=0, high=n1;
    int n=n1+n2;
    int left = (n+1)/2; // for odd combination we want left to be larger
    while (low<=high){
        int mid1=low+(high-low)/2;
        int mid2=left-mid1;
        int l1 = INT_MIN,l2=INT_MIN;
        int r1= INT_MAX, r2=INT_MAX;
        if (mid1<n1) r1=a[mid1];
        if (mid2<n2) r2=b[mid2];
        if (mid1-1>=0) l1=a[mid1-1];
        if (mid2-1>=0) l2=b[mid2-1];
        if (l1<=r2 && l2<=r1){
            if (n%2==1)return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2)high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}

int kthEleOfTwoSrtdArr(vector<int> &a, vector<int> &b, int k){
    //Brute: T=O(n+m) & S=O(n+m) Merge both arrays by method in merge sort and then return arr[k-1]
    //Better: T=O(n+m) & S=O(1) don't merge just replace adding part with cnt++ and when cnt=k-1 return that element
    //Optimal : 
    int n1=a.size();
    int n2 = b.size();
    if (n1>n2) return kthEleOfTwoSrtdArr(b,a,k);
    int low=max(0,k-n2), high=min(k,n1);
    while (low<=high){
        int mid1=low+(high-low)/2;
        int mid2=k-mid1;
        int l1 = INT_MIN,l2=INT_MIN;
        int r1= INT_MAX, r2=INT_MAX;
        if (mid1<n1) r1=a[mid1];
        if (mid2<n2) r2=b[mid2];
        if (mid1-1>=0) l1=a[mid1-1];
        if (mid2-1>=0) l2=b[mid2-1];
        if (l1<=r2 && l2<=r1){
           return max(l1,l2);
        }
        else if(l1>r2)high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}

int RowWithMaximumOnes(vector<vector<int>> &matrix){
    // Each row is sorted and have value 0 or 1
    //Brute: T=O(n^2) & S=O(1) find out max no. of ones by traversing each row
    //Better: T=O(nlogm) & S=O(1)
    //Incase all are 0 then return 0
    int cnt_max=0;
    int index=-1;
    for (int i=0; i<matrix.size();i++){
        int cnt_ones = matrix[i].size()-lowerBound(matrix[i],1);
        if (cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            index=i;
        }
    }
    return index;
}

bool SearchIn2DSrtdMatrix(vector<vector<int>> &matrix, int target){
    int n=matrix.size(), m=matrix[0].size();
    //Brute: T=O(n*m) two for loops traversing each row
    //Better : T=O(n+logm) =O(n) Implementing BS on that row where row[0]<=target && target<=row[m-1]
    //Optimal : Flatten out the matrix from index 0 to n*m-1 and row=mid/m and column=mid%m
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/m,col=mid%m;
        if (matrix[row][col]==target) return true;
        else if (matrix[row][col]<target)low=mid+1;
        else high=mid-1;
    }
    return false;
}

bool SearchRowColumnSrtdMatrix(vector<vector<int>> &matrix, int target ){
    //Brute: T=O(n*m) two for loops
    //Better: T=O(n*logm) BS on each row
    //Optimal: T=O(n+m) If we go diagonally we know whether go down or left from matrix[0][m-1]
    int row=0,col=matrix[0].size()-1;
    while (row<matrix.size() && col>=0){
        if (matrix[row][col]==target) return true;
        else if (matrix[row][col]<target)row++;
        else col--;
    }
    return false;
}

pair<int,int> findPeakEle2D(vector<vector<int>> &matrix){
    //No two adjacent cells can be equivalent
    //Brute : T=O(n*m) checking for each element that if its greater than its top, bottom,left and right OR find the largest element in 2d matrix
    //Optimal: T=O(n*logm) BS on Columns . Find the max in each column and then compare that max with left and right and where condn fails make that column high and then do BS.
    //Can do the BS on Rows too.
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = m-1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // find max in this column
        int maxRow = 0;
        for (int i=0; i<n; i++) {
            if (matrix[i][mid] > matrix[maxRow][mid]) {
                maxRow = i;
            }
        }

        bool left  = (mid==0   || matrix[maxRow][mid] > matrix[maxRow][mid-1]);
        bool right = (mid==m-1 || matrix[maxRow][mid] > matrix[maxRow][mid+1]);

        if (left && right) {
            return {maxRow, mid};
        }
        else if (mid > 0 && matrix[maxRow][mid-1] > matrix[maxRow][mid]) {
            high = mid-1; // move left
        }
        else {
            low = mid+1; // move right
        }
    }
    return {-1,-1};
}

int smallEqualElements(vector<vector<int>> &matrix, int key){
    int cnt=0;
    for (int i=0;i<matrix.size();i++){
        cnt+=upperBound(matrix[i],key);
    }
    return cnt;
}
int matrixMedian(vector<vector<int>> &matrix){
    // n and m are odds and rowwise sorted
    //Brute: T= O(n*m + n*m*log(n*m)) Insert all elements of matrix in a 1d array and then sort them and return arr[n*m/2]
    //Best : T=O(log10^9 * n*logm)
    int n = matrix.size(),m=matrix[0].size();
    int low=INT_MAX, high = INT_MIN;
    for (int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }
    int req=n*m/2;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (smallEqualElements(matrix,mid)>req)high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };
    cout<< matrixMedian(matrix);
    return 0;
}
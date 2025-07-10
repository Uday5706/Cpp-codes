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
    int ans = -1;
    while (low <= high)
    {
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] < key))
            low = mid + 1;
        else if (v[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &v, int key){
    // Smallest Index such that v[ind]>key
    // Brute = T=O(n) Linear Search
    //OR return upper_bound(v.begin(),v.end(),key)-v.begin()
    // Optimal:  Think like when search space is sorted, use binary Search
    int low = 0, high = v.size() - 1;
    int ans = -1;
    while (low <= high){
        // int mid = (low+high)/2; but to avoid overflow cases (INT_MAX + INT_MAX)
        int mid = low + (high - low) / 2; // so that it desn't cross INT_MAX otherwise use long long
        if ((v[mid] <= key))
            low = mid + 1;
        else if (v[mid] > key){
            ans = mid;
            high = mid - 1;
        
        }
    }
    return ans;
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

float squareRoot(int n2){
    //brute : T=O(n/2)
    //OPtimal: T=O(log(n/2)
    if (n2==1)return 1;
    float low=0;
    float high=(n2<=3)?n2:(float)n2/2;
    // cout<<high;
    while (low<=high){
        float mid = low+(high-low)/2;
        // cout<<mid<<endl;
        float mid2=mid*mid;
        // cout<<mid2<<endl;
        if (mid2==n2)return mid;
        else if(mid2>n2){
            high=mid-0.0001;
            // cout<<high<<endl;
        }
        else{
             low=mid+0.0001;
            //  cout<<low<<endl;
        }
    }
    int roundoff=high*1000;
    float ans=(float)roundoff/1000;
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,9,8};
    cout<<squareRoot(29);
    return 0;
}
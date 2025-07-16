#include<bits/stdc++.h>
using namespace std;

int power(int n,int m){
    long long res=1;
    while (m--)
    {
        res=res*n;
        if(res>INT_MAX) return INT_MAX;
    }
    


    return res;
}

int nthRootOfM(int n,int m){
    for(int i=1;i<m;i++){
        if(power(i,n)==m){
            return i;
        }
        else if(power(i,n)>m) break;
    }
    return -1;
}

int nthRootOfMOptimal(int n ,int m){
    int low=1;int high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int midPow=power(mid,n);
        if(midPow==m)return mid;
        else if(midPow<m) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int sgrtN(int n){
    int low=1;
    int high=n;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int midPow=pow(mid,2);
        if(midPow==n){
            return mid;
        }
        else if(midPow<n) {
            ans=mid;
            low=mid+1;
        }
        else{ high =mid-1;}
    }

    return ans;

}

int sumByD(vector<int>&a,int div){
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)a[i]/(double)div);
    }

    return sum;

}

int smallestDivisor(vector<int>&a,int t){
    int n=a.size();
    if(n>t) return -1;
    int low=1;int high=*max_element(a.begin(),a.end());
    while (low<=high)
    {
        int mid=(low+high)/2;
        int ans=sumByD(a,mid);
        if(ans<=t){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
    

}
int findDays(vector<int>w,int cap){
        int days=1;
        int load=0;
        int n=w.size();
        for(int i=0;i<n;i++){
            if(load+w[i]>cap){
                days+=1;
                load=w[i];
            }
            else load+=w[i];
        }


        return days;
}

int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;

        }
        return k+high+1;
        
}
int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int numOfDays=findDays(weights,mid);
            if(numOfDays<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
}


bool canWePlace(vector<int>&a,int d,int cows){
    int n=a.size();
    int cnt=1;
    int last=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-last>=d){
            cnt++;
            last=a[i];
        }
        if (cnt>=cows) return true;
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); 
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}


int noOfStudents(vector<int>&a,int pages){
    int n=a.size();
    int student=1;
    int pagesStudent=0;
    for(int i=0;i<n;i++){
        if(pagesStudent+a[i]<=pages){
            pagesStudent+=a[i];
        }
        else {
            student++;
            pagesStudent=a[i];
        }
    }
    return student;
}

int bookAllocation(vector<int>&a,int students){
    int n=a.size();
    int mini=*max_element(a.begin(),a.end());
    int maxi=accumulate(a.begin(),a.end(),0);
    for(int i=mini;i<=maxi;i++){
        int cntStu=noOfStudents(a,i);
        if(cntStu==students){
            return i;
        }
    }
    return -1;
}

int bookAllocationOptimal(vector<int>&a,int students){
    int n=a.size();
    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);
    int ans=-1;
    if (students > n) return -1;
    while(low<=high){
        int mid=(low+high)/2;
        int cntStu=noOfStudents(a,mid);
        if(cntStu<=students){ 
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;

    
}


int countPart(vector<int> &a,int maxSum){
        int part=1;
        long long subSum=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(subSum+a[i]<=maxSum){
                subSum+=a[i];
            }else{
                part++;
                subSum=a[i];
            }
        }

        return part;
}
int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0); 
        while(low<=high){
            int mid=(low+high)/2;
            int midPart=countPart(nums,mid);
            if(midPart<=k) high=mid-1;
            else low=mid+1;
        }

        return low;
        
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int len = n1 + n2;
        int idx1 = (len - 1) / 2;
        int idx2 = len / 2;
        
        int el1 = -1, el2 = -1;
        int cnt = 0, i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == idx1) el1 = nums1[i];
                if (cnt == idx2) el2 = nums1[i];
                i++;
            } else {
                if (cnt == idx1) el1 = nums2[j];
                if (cnt == idx2) el2 = nums2[j];
                j++;
            }
            cnt++;
        }

        while (i < n1) {
            if (cnt == idx1) el1 = nums1[i];
            if (cnt == idx2) el2 = nums1[i];
            i++; cnt++;
        }

        while (j < n2) {
            if (cnt == idx1) el1 = nums2[j];
            if (cnt == idx2) el2 = nums2[j];
            j++; cnt++;
        }

        if (len % 2 == 1) {
            return (double)el2;
        }

        return (el1 + el2) / 2.0;
}
int main() {
    cout<<sgrtN(28);
    cout<<nthRootOfM(3,27);
    cout<<nthRootOfMOptimal(3,27);
   //  cout<<pow(2,3);
    return 0;
}

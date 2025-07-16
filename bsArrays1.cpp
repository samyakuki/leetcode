#include<bits/stdc++.h>
using namespace std;
int binarySearchIte(vector<int>&a,int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==k) return mid;
        else if(a[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return -1;
    
}
int binarySearchRec(vector<int>& a, int low, int high, int k) {
    sort(a.begin(),a.end());
    int n=a.size();
    if(low > high) return -1;
    int mid=(low+high)/2;
    if(a[mid]==k ) return mid;
    else if(a[mid]<k ) return binarySearchRec(a,mid+1,high,k);
    return binarySearchRec(a,low,mid-1,k);
}

int lowerBound(vector<int>&a,int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=k) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}


int upperBound(vector<int>&a,int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>k) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}
int findFloor(vector<int>&a,int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<=k) {
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;

        }
    }
    return a[ans];
    
}

int findCeil(vector<int>&a,int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=k) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return a[ans];
    
}



pair<int, int> getFloorAndCeil(vector<int>&arr, int x) {
	int f = findFloor(arr, x);
	int c = findCeil(arr, x);
	return make_pair(f, c);
}


int firstOccurence(vector<int>&a,int k){
    int n=a.size();
    int low=0;int high=n-1;
    int ans=-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(a[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        /* code */
    }
    


    return ans;
}

int lastOccurence(vector<int>&a,int k){
    int n=a.size();
    int low=0;int high=n-1;
    int ans=-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==k){
            ans=mid;
            
            
            low=mid+1;
        }
        else if(a[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        /* code */
    }
    


    return ans;
}

int occurenceCount(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0; int high=n-1;
        int first=-1;int last=-1;
    while (low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            first=mid;
            
            
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       
    }
    low=0;
    high=n-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target){
            last=mid;
            
            
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
 


        return last-first+1;
        
    }

int rotationCount(vector<int>&a){
    int n=a.size();
    int low=0;
    int high=n-1;
    int index=0;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;

        if(a[low]<=a[high]){
            if(a[low]<=ans){
                ans=a[low];
                index=low;
            }
            break;
        }
        if(a[low]<=a[mid]){

            if(a[low]<ans){
                ans=a[low];
                index=low;

            }
           
            low=mid+1;
        }
        else{
            if(a[mid]<ans){
                ans=a[mid];
                index=mid;

            }
            high=mid-1;
        }
    }
    
    


    return index;
}

int singleNonDuplicate(vector<int>&a){
    int n=a.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid%2==1)mid--;
        if(a[mid]==a[mid+1]){
            low=mid+2;
        }
        else{
            high=mid;
        }

    }
    return a[low];
}
int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]>nums[mid-1])low=mid+1;
            else high=mid-1;
    }

    return -1;
        
}

int main() {
    vector<int> a = {1,1,2,2,3,3,4,4,5,5,6,6,7};
    cout<<singleNonDuplicate(a);
    cout<<rotationCount(a);
    // cout<<occurenceCount(a,13);
    // cout<<firstOccurence(a,13);
    // cout<<lastOccurence(a,13);

    // pair<int, int> ans = getFloorAndCeil(a,  5);
	// cout << "The floor and ceil are: " << ans.first
	//      << " " << ans.second << endl;

    // cout<<lowerBound(a,2);
   
    // cout<<lowerBound(a,9);
    // cout<<upperBound(a,9);

    // cout<<binarySearchRec(a,0,n-1,10)<<endl;
    // cout<<binarySearchIte(a,10);

    

 

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sortArray(int arr[],int n){
    sort(arr,arr+n);
}

int largestElement(int arr[],int n){
    sortArray(arr,n);
    return arr[n-1];
}

int optimalLargestElement(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int secondLargestEelment(int arr[],int n){
    int max=arr[0];
    int secMax=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<max && arr[i]>secMax){
            secMax=arr[i];
        }
    }
    for(int i=0;i<n;i++){
      
        if(arr[i]<max && arr[i]>secMax){
            secMax=arr[i];
        }
    }
    return secMax;
    
}

bool isSorted(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i+1]){
            return true;
        }
        
            return false;
        
    }
}

vector<int> removeDuplicates(vector<int> &a) {
    sort(a.begin(), a.end());
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            res.push_back(a[i]);
        }
    }
    return res;
}

vector<int> moveAllZeroesToEnd(vector<int> &a) {
    vector<int> res;
    int count=0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]!=0) {
            res.push_back(a[i]);
        }
        else{
            count++;
        }
    }
    for(int i=0;i<count;i++){
        res.push_back(0);
    }
    return res;
}
int linearSearch(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}

vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
    set<int> s;
    vector<int> Union;

    for (int i = 0; i < arr1.size(); i++)
        s.insert(arr1[i]);

    for (int i = 0; i < arr2.size(); i++)
        s.insert(arr2[i]);

    for (auto& it : s)
        Union.push_back(it);

    return Union;
}

void leftRotation(vector<int> &a,int k){
    int n=a.size();
    k=k%n;

    reverse(a.begin(),a.begin()+k);
    reverse(a.begin()+k,a.end());
    reverse(a.begin(),a.end());

}

int missingelement(int arr[],int n){
    int total= (n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n;i++ ){
        sum+=arr[i];
    }
    return total-sum;
   

}

int maxConsec1(vector<int>&a){
    int count=0;
    int maxi=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==1){
            count++;
        }
        else{
            count=0;
        }
        maxi=max(maxi,count);
    }
    return maxi;
}
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
        }
        int x=0;

        for(auto it:freq){
            if(it.second==1){
                x=it.first;
                break;
            }

        }

        return x;
        
    }

void subArray (vector <int> &a){
    for(int i=0;i<a.size();i++){
        vector <int> temp;
        for(int j=i;j<a.size();j++){
            temp.push_back(a[j]);
            for(auto it:temp){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

}


void subArraySum (vector <int> &a){
    for(int i=0;i<a.size();i++){
        int sum=0;
        for(int j=i;j<a.size();j++){
          sum+=a[j];
          
          cout<<sum;
            cout<<" ";
        }
        cout<<endl;
    }

}

int subArrayLongest(vector<int> &a, int k) {
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = i; j < a.size(); j++) {
            sum += a[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int subArrayLongestOptimal(vector<int> &a, int k) {
    unordered_map <int,int> preSum;
    int maxLen = 0;
    int sum = 0;


    for (int i = 0; i < a.size(); i++) {
        sum+=a[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;
        if(preSum.find(rem)!=preSum.end()){
            int len=i-preSum[rem];
            maxLen=max(maxLen,len);

        }

        if(preSum.find(sum)==preSum.end()){
            preSum[sum]=i;
        }
    }
    return maxLen;
}

int subArrayLongestOptimal2pointer(vector<int> &a, int k) {
    int left=0;int right=0;
    int sum=a[0];
    int maxLen=0;
    int n=a.size();
    while(right<n){
        while(left<=right && sum>k){
            sum-=a[left];
            left++;

        }

        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n ){
            sum+=a[right];
        }

    }
    return maxLen;
}

void twoSum(vector<int> &a,int k){
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]+a[j]==k){
                cout<<a[i]<<" "<<a[j]<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<"hey";
            }
        }

    }
    
}

int main(){
    int a[]={23,4,224,5,78,224,899};
    vector<int> a1 = {1,2,3,4,5};
    vector<int> a2 = {2,3,4,4,5};
    vector<int> a3 = {2,3,5};
    vector<int> a4 = {2,6,5,8,11,6,8};
    twoSum(a4,14);
    // cout<<subArrayLongestOptimal2pointer(a3,5)<<endl;
    // cout<<subArrayLongestOptimal(a3,5)<<endl;
    // cout<<subArrayLongest(a3,5);
    // subArray(a3);
    // cout<<"'hey \n";
    // subArraySum(a3);
    
    // cout<<singleNumber(a3);
    // cout<<maxConsec1(a3);
    // vector <int> r=unionOfArrays(a1,a2);
    // for(auto it:r){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<endl<<"hey";

    // vector <int> res=moveAllZeroesToEnd(a1);
    //  for(auto it:res){
    //     cout<<it<<" ";
    // }


    // int n=sizeof(a)/sizeof(a[0]);
    // printArray(a,n);
    // sortArray(a,n);
    // printArray(a,n);
    // cout<<largestElement(a,n);
    
    // cout<<endl<<optimalLargestElement(a,n);
    // cout<<endl<<secondLargestEelment(a,n);
    // cout<<endl <<isSorted(a,n);

    // vector<int> res= removeDuplicates(arr1);
    //  for(auto it:res){
    //     cout<<it<<" ";
    // }

    // leftRotation(arr1,2);
    // for(auto it:arr1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;






    return 0;
}
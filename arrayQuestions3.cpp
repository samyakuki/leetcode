#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }

    return res;
}

vector <int> generateRow(int n){
    int ans=1;
    vector <int> ansR;
    ansR.push_back(1);
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
        ansR.push_back(ans);
    }
    return ansR;
}


vector <vector<int>> pascleTri(int N){
    vector <vector<int>> ans;
    for(int i=0;i<N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

vector <int> majorityElement(vector <int> &a){
    int n=a.size();
    unordered_map <int,int> freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    vector<int> res;
    for(auto it:freq){
        if(it.second>n/3){
            res.push_back(it.first);
        }
    }
    return res;
}

vector<vector<int>> threeSum(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(a[i] + a[j] + a[k] == 0) {
                    vector<int> triplet = {a[i], a[j], a[k]};
                    sort(triplet.begin(), triplet.end());
                    if(find(ans.begin(), ans.end(), triplet) == ans.end()) {
                        ans.push_back(triplet);
                    }
                }
            }
        }
    }

    return ans;
}
vector<vector<int>> threeSumBetter(vector<int> &a) {
    int n = a.size();
    set <vector <int>> st;
    for(int i = 0; i < n; i++) {
        set <int> hashSet;
        for(int j = i + 1; j < n; j++) {
            int third=-(a[i]+a[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector <int> temp={a[i],a[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }



            hashSet.insert(a[j]);

           
        }
    }
     vector<vector<int>> ans(st.begin(),st.end());

    return ans;
}

    vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n=nums.size();
        vector <vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
         while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                vector <int> trip={nums[i],nums[j],nums[k]};
                ans.push_back(trip);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;

            }
            else if(sum<0){
                j++;
            }
            else{
                k--;
            }
            }
        }
        return ans;
        
    }


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0&& nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector <int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++; l--;

                    
                         while (k < l && nums[k] == nums[k - 1]) k++;
                         while (k < l && nums[l] == nums[l + 1]) l--;

                    }
                    else if(sum < target )k++;
                    else l--;

                }

            }
        }




        return ans;
}



int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMax=nums[0];
        int currMin=nums[0];
        int maxProd=nums[0];

        for(int i=1;i<n;i++){
               if (nums[i] < 0)
            swap(currMax, currMin);

        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        maxProd = max(maxProd, currMax);
        }
        


        return maxProd;
}

int subArrayLongest(vector<int> &a) {
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = i; j < a.size(); j++) {
            sum += a[j];
            if (sum == 0) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int subArrayCountXor(vector<int> &a,int k) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        int xorE = 0;
        for (int j = i; j < a.size(); j++) {
            xorE =xorE^ a[j];
            if (xorE == k) {
               count++;
            }
        }
    }
    return count;
}

vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>> &a){
    int n=a.size();
    sort(a.begin(),a.end());

    vector <vector<int>> ans;
    for(int i=0;i<n;i++){
        if( ans.empty()|| a[i][0]>ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],a[i][1]);
        }
    }

    return ans;
}


vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector <vector<int>> ans;
          for(int i=0;i<n;i++){
        if( ans.empty()|| intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
        return ans;
        
}

void mergeSortedArrayOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
        
}
void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;
    for(int i = 0; i < m; i++) temp.push_back(nums1[i]);
    for(int i = 0; i < n; i++) temp.push_back(nums2[i]);
    sort(temp.begin(), temp.end());
    for(int i = 0; i < m + n; i++) nums1[i] = temp[i];
}

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n=a.size();
    vector <int> ans(2);
    unordered_map <int,int> freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            ans[1] = i; 
        } else if (freq[i] == 2) {
            ans[0] = i; 
        }
     }

    return ans;

}

int inversionPairs(vector<int>&a){
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }

        }
    }
    return count;
}
int reversePairs(vector<int>&a){
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>(2*a[j])){
                count++;
            }

        }
    }
    return count;
}
void merge(vector<int>&a,int low,int mid,int high){
    vector <int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid&& right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }

    }
    while (left<=mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<high;i++){
        a[i]=temp[low-i];
    }
    
}


int main(){

    vector <int> a={1,2,2,3,2};
    vector <int> b=  {1,3,2,3,1};
    cout<<reversePairs(b);
    // cout<<inversionPairs(b);
    // vector <int> c=findMissingRepeatingNumbers(b);
    // for(auto it :c){
    //     cout<<it<<" ";
    // }

    // cout<<subArrayLongest(b);
    // vector<int>c=majorityElement(b);
    // for(auto it:c){
    //     cout<<it<<" ";
    // }
    // cout<<ncr(10,3);
//     vector <vector<int>> a=pascleTri(6);
//    for (auto row : a) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
    return 0;
}
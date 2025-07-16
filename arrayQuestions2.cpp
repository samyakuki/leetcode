#include<bits/stdc++.h>
using namespace std;


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
    cout<<"[-1,-1]";
    
}

void twoSumOptimal(vector<int> &a, int k){
    sort(a.begin(),a.end());
    int n=a.size();
    int left=0;int right=n-1;
    while(left<right){
        int sum=a[left]+a[right];
        if(sum==k){
            cout<<left<<" "<<right;
        }
        else if(sum<k){
            left++;
        }
        else right--;

    }

    cout<<"[-1,-1]";

}
vector <int> sort012(vector <int > &a){
    vector<int> temp;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==0){
            temp.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            temp.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==2){
            temp.push_back(a[i]);
        }
    }
    return temp;
}

void sort012Optimal(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt0++;
            else if(nums[i]==1)cnt1++;
            else cnt2++;
        }
    for (int i = 0; i < cnt0; i++) nums[i] = 0; 

    for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; 

    for (int i = cnt0 + cnt1; i < n; i++) nums[i] = 2;
        
    }

int majorityElement(vector <int> &a){
    int n=a.size();
    unordered_map <int,int> freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for(auto it:freq){
        if(it.second>n/2){
            return it.first;
        }
    }
    return 0;
}

int majorityMorreAlgo(vector <int> &a){
    int n=a.size();
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
         if (cnt == 0) {
            cnt = 1;
            el = a[i];
        }
        else if(el==a[i]){
            cnt++;
        }
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(a[i]==el){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        return el;
    }
    return -1;
}

int subArrayLongestLargestSum(vector<int> &a) {
    int maxSum = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = i; j < a.size(); j++) {
            sum += a[j];
        maxSum=max(maxSum,sum);

            
        }
    }
    return maxSum;
}


    int subArrayLongestLargestSumOptimal(vector<int>& arr) {
        int n=arr.size();
        int maxi = INT_MIN;
        int sum=0;
          int start = 0;
       int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";


    return maxi; 
    }


int stockBuySell(vector<int>& a){
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] < minPrice){
            minPrice = a[i];
        }
        else {
            int price = a[i] - minPrice;
            if(price > maxProfit){
                maxProfit = price;
            }
        }
    }

    return maxProfit;
}

vector<int> altPlaces(vector<int>& a) {
    int n=a.size();
    vector<int> result(n,0);
    int pi=0;
    int ni=1;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            result[ni]=a[i];
            ni+=2;
        }
        else{
            result[pi]=a[i];
            pi+=2;
        }
    }


    return result;
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
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}
void leaderArray(vector<int> &a) {
    int n = a.size();
    int maxRight = a[n-1];
    cout << maxRight << " ";  // Last element is always a leader

    for (int i = n-2; i >= 0; i--) {
        if (a[i] > maxRight) {
            maxRight = a[i];
            cout << maxRight << " ";
        }
    }
}

int longestConsecSeq(vector <int> &a){
    sort(a.begin(),a.end());
    int n=a.size();
    int currCount=0; int longest=1;
    int lastSmaller=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]-1==lastSmaller){
            currCount++;
            lastSmaller=a[i];
        }
        else if(a[i]!=lastSmaller){
            currCount=1;
            lastSmaller=a[i];
        }
        longest=max(longest,currCount);
    }
    return longest;
}

int longestConsecSeqOptimal(vector <int> &a){
   
    int n=a.size();
    if (n==0) return 0;

    int longest=1;
    unordered_set <int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }

    for (auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;int x=it;
            while (st.find(x+1)!=st.end())
            {
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
            

        }
    }
    return longest;
}



void setMatrixZero(vector<vector <int>>&a){
    int n=a.size();
    int m=a[0].size();

    vector <int> row(n,0),col(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1||col[j]==1){
                a[i][j]=0;
            }
        }

    }

}

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
  
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}



void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=temp;
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;    
}


int main(){
    int a[]={23,4,224,5,78,224,899};
    vector<int> a1 = {2,6,5,8,11};
    vector<int> a2 ={7,1,5,3,6,4};
    vector<int> a3 = {1,2,-4,-5};
    vector<int> a4 = {100, 200, 1, 3, 2, 4};
     vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    setMatrixZero(mat);

    for (auto& row : mat){
        for (int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    // cout<<longestConsecSeqOptimal(a4);
    // leaderArray(a4);
    // subArray(a4);
    // vector <int> rea=altPlaces(a3);
    // for(auto it:rea){
    //     cout<<it<<" ";
    // }
    // cout<<stockBuySell(a2);

    // cout<<subArrayLongestLargestSum(a2);
    // cout<<endl;
    // cout<<subArrayLongestLargestSumOptimal(a2);

    // cout<<majorityElement(a2);
    // cout<<endl<<majorityMorreAlgo(a2);

    // vector  <int >temp=sort012(a2);
    // for(auto it:temp){
    //     cout<<it<<" ";
    // }

    // twoSum(a1,4);
    // cout<<endl<<" bksdk";
    // twoSumOptimal(a1,14);
 





    return 0;
}
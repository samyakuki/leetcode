#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int>st;
        for(int num:nums2){
            while(!st.empty()&& num>st.top()){
                nge[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        vector<int> res;
        for(int num:nums1){
            res.push_back(nge[num]);
        }
        return res;
}

vector<int> nextGreaterElement2(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        stack<int> st;

        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!st.empty()&&nums[st.top()]<=nums[idx]){
                st.pop();
            }
            if(!st.empty()){
                res[idx]=nums[st.top()];
            }
            st.push(idx);
        }


        return res;
        
}
vector<int> nextSmallerElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nse;
        stack<int>st;
        for(int num:nums2){
            while(!st.empty()&& num<st.top()){
                nse[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            nse[st.top()]=-1;
            st.pop();
        }
        vector<int> res;
        for(int num:nums1){
            res.push_back(nse[num]);
        }
        return res;
}
vector<int> countNextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 1; j < n; j++) {
            int nextIdx = (i + j) % n;
            if (nums[nextIdx] > nums[i]) {
                count++;
            }
        }
        res[i] = count;
    }

    return res;
}
int trap(vector<int>& height) {
        int i=0;int water=0;
        stack<int>st;
        while(i<height.size()){
            while(!st.empty()&&height[i]>height[st.top()]){
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                int dist=i-st.top()-1;
                int bounded=min(height[i],height[st.top()])-height[top];
                water+=dist*bounded;
            }

            st.push(i++);
        }

        return water;
}
int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();  
        int MOD=1e9+7;
        vector<int>left(n),right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]) st.pop();
            left[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]) st.pop();
            right[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        long res=0;
        for(int i=0;i<n;i++){
            long cont=(i-left[i])*(right[i]-i)%MOD;
            res = (res + arr[i] * cont ) % MOD;

        }


        return res;
}
vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int as:asteroids){
            bool alive=true;
            while(alive && as<0 && !st.empty() && st.top()>0){
                if(st.top()< -as) st.pop();
                 else if(st.top()==-as) {
                    st.pop();
                    alive=false;
                 }
                 else alive=false;
            }

            if(alive) st.push(as);
        }
        int n=st.size();
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }


        return res;
}
long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        // Contributions as maximum
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int j = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                total += 1LL * nums[j] * (j - left) * (right - j);
            }
            st.push(i);
        }

        // Contributions as minimum (subtract)
        while (!st.empty()) st.pop();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int j = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                total -= 1LL * nums[j] * (j - left) * (right - j);
            }
            st.push(i);
        }

        return total;
}

string removeKdigits(string num, int k) {
    stack<char>st;
    for(char digit:num){
        while(!st.empty()&& k>0 && st.top()>digit){
            k--;
            st.pop();

        }
        st.push(digit);
    }
    while(k-- >0 && !st.empty()){
        st.pop();
    }
    string res;
    while(!st.empty()){
        res+= st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    int i=0;
    while(i<res.size() && res[i]=='0')i++;
    res=res.substr(i);
    return res.empty() ? "0" : res;

}

int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int area=0;
        for(int i=0;i<=n;i++){
            int currH=i==n ? 0 : heights[i];
            while(!st.empty() && currH<heights[st.top()]){
                int height= heights[st.top()];
                st.pop();
                int width=st.empty() ? i : i-st.top()-1;
                area=max(area,height*width);

            }
            st.push(i);
        }

        return area;
        
}

int largestArea(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        int area=0;

        for(int i=0;i<=n;i++){
            int currH= i==n ? 0 :heights[i];
            while(!st.empty()&& currH<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width= st.empty() ? i : i-st.top()-1;
                area=max(area,height*width);
            }
            st.push(i);

        }
        return area;
}
int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int area=0;
        vector<int >heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            area=max(area,largestArea(heights));
        }
    return area;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int> res;

        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }


        return res;
}
stack<int>prices;
stack<int> spans;
int nextSpan(int price) {
    int span = 1;
    while (!spans.empty() && prices.top() <= price) {
        prices.pop();
        span += spans.top();
        spans.pop();
    }
    prices.push(price);
    spans.push(span);
    return span;
}
int celebrity(vector<vector<int>>& M) {
    int n = M.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        
        if (M[a][b] == 1) {
            st.push(b);
        } else {
            st.push(a); 
        }
    }
    
    int candidate = st.top();
    
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
            return -1;
        }
    }
    
    return candidate; 
}
int main(){
    return 0;
}
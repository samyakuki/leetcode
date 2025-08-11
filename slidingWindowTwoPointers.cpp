#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int left=0;int right=0;int maxLen=0;
        int n=s.size();
        vector<int>mpp(256,-1);
        while(right<n){
            if(mpp[s[right]]!=-1){
                left=max(left,mpp[s[right]]+1);
            }
            mpp[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
}

int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zero=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0)zero++;
            while(zero>k){
                if(nums[l]==0)zero--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
}
int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count; 
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            count[fruits[right]]++;

            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
}

int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int count=0,l=0,res=0;

        for(int r=0;r<s.length();r++){
            freq[s[r]-'A']++;
            count=max(count,freq[s[r]-'A']);
            while((r-l+1)-count>k){
                freq[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }

        return res;
}

int atMost(vector<int>& nums, int goal) {
        if (goal<0) return 0;
        int l=0,sum=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
        }


        return cnt;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);
}


int atMostNice(vector<int>& nums, int k) {
        int l=0,odd=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2!=0)odd++;
            while(odd>k){
                if(nums[l]%2!=0)odd--;
                l++;
            }
            cnt+=(r-l+1);
        }

        return cnt;
}
int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostNice(nums,k) -atMostNice(nums,k-1);
}

int numberOfSubstrings(string s) {
        int n=s.length();
        int l=0,cnt=0;
        vector<int>freq(3,0);
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                cnt+=(n-r);
                freq[s[l]-'a']--;
                l++;
            }
        }


        return cnt;
        
}

int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int leftSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        
        int maxScore = leftSum;
        int rightSum = 0;
        
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i];       
            rightSum += cardPoints[n - 1 - i];     
            maxScore = max(maxScore, leftSum + rightSum);
        }
        
        return maxScore;
}

int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;
            
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
}

int atMostKDif(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            freq[nums[r]]++;
            while(freq.size()>k){
            freq[nums[l]]--;
            if(freq[nums[l]]==0)
                freq.erase(nums[l]);
                l++;

            }
            cnt+=(r-l)+1;
        }

        return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDif(nums,k)-atMostKDif(nums,k-1);      
}
int main(){

    return 0;
}
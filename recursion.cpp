#include <bits/stdc++.h>
using namespace std;
int helper(string&s,int sign,int i,long res){
        if(i>=s.length()||!isdigit(s[i])){
            return sign*res;
        }
        res=res*10+(s[i]-'0');
        if(sign*res>=INT_MAX) return INT_MAX;
        if(sign*res<=INT_MIN) return INT_MIN;
        return helper(s,sign,i+1,res);
}
    int myAtoi(string s) {
        int i=0;int sign=1;
        while(i<s.length() && (s[i]==' '))i++;
        if(i<s.length() && (s[i]=='+'|| s[i]=='-')){
            if(s[i]=='-')sign=-1;
            i++;
        }
        return helper(s,sign,i,0);
        
}

double myPow(double x, int n) {
     long long N = n;  

        if (N == 0) return 1;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double half=myPow(x,N/2);

        if(N%2==0) return half*half;
        else return half*half*x;
        
}

const int MOD = 1e9 + 7;
    long long myPower(long long x,long long n){
        if (n==0) return 1;
        long long half=myPower(x,n/2);
        long long res=(half*half)%MOD;
        if(n%2==1) return (res*x)%MOD;
        return res;
    }
int countGoodNumbers(long long n) {
        long long evenPos=(n+1)/2;
        long long oddPos=n/2;
        long long evenWays=myPower(5,evenPos);
        long long oddWays=myPower(4,oddPos);

        return (evenWays * oddWays) % MOD;
        
}

void generateBinaryStrings(int n, string str = "") {
    if (str.length() == n) {
        cout << str << endl;
        return;
    }

    generateBinaryStrings(n, str + "0");
    generateBinaryStrings(n, str + "1");
}


void helperP(int open,int close,int n, string c,vector<string>&s){
        if(c.length()==2*n){
            s.push_back(c);
            return;
        }
        if(open<n) helperP(open+1,close,n,c+"(",s);
        if(close<open) helperP(open,close+1,n,c+")",s);
    }
vector<string> generateParenthesis(int n) {
        vector<string> res;
        helperP(0,0,n,"",res);
        return res;
        
}

void helperS(int i,vector<int>&nums,vector<int>&current,vector<vector<int>>& res){
        if(i==nums.size()){
            res.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        helperS(i+1,nums,current,res);
        current.pop_back();
        helperS(i+1,nums,current,res);


        
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>curr;
        helperS(0,nums,curr,res);

        return res;
        
}


void printAllSubs(string &s, int i, string &curr) {
    if (i == (int)s.size()) {
        cout << curr << '\n';
        return;
    }
    curr.push_back(s[i]);
    printAllSubs(s, i + 1, curr);
    curr.pop_back();
    printAllSubs(s, i + 1, curr);
}

void printAllSubsSumK(string &s, int i, string &curr, int &sum, int k) {
    if (i == (int)s.size()) {
        if (sum == k) cout << curr << '\n';
        return;
    }
    curr.push_back(s[i]);
    sum += s[i];
    printAllSubsSumK(s, i + 1, curr, sum, k);
    sum -= s[i];
    curr.pop_back();
    printAllSubsSumK(s, i + 1, curr, sum, k);
}

bool printOneSubSumK(string &s, int i, string &curr, int &sum, int k) {
    if (i == (int)s.size()) {
        if (sum == k) {
            cout << curr << '\n';
            return true;
        }
        return false;
    }
    curr.push_back(s[i]);
    sum += s[i];
    if (printOneSubSumK(s, i + 1, curr, sum, k)) return true;
    sum -= s[i];
    curr.pop_back();
    if (printOneSubSumK(s, i + 1, curr, sum, k)) return true;
    return false;
}

int countSubSumK(string &s, int i, int sum, int k) {
    if (i == (int)s.size()) return (sum == k);
    int left = countSubSumK(s, i + 1, sum + s[i], k);
    int right = countSubSumK(s, i + 1, sum, k);
    return left + right;
}

void helperComb(int i,int target,vector<int>&candidates,vector<int>&curr,vector<vector<int>>& res){
        if(i==candidates.size()){
            if(target==0) {
                res.push_back(curr);
            }
            return;
        }
        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            helperComb(i,target-candidates[i],candidates,curr,res);
            curr.pop_back();
        }
            helperComb(i+1,target,candidates,curr,res);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        helperComb(0,target,candidates,curr,res);
        return res;
}

void helperComb2(int i,int target,vector<int>&candidates,vector<int>&curr,vector<vector<int>>& res){
        if(target==0) {
                res.push_back(curr);
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[i]>target) break;
            curr.push_back(candidates[j]);
            helperComb2(j+1,target-candidates[j],candidates,curr,res);
            curr.pop_back();

        }

            
        
}
 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        helperComb2(0,target,candidates,curr,res);
        return res;
}


void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
}
vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

void findSubs(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if (i > ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubs(i+1,nums,ds,ans);
            ds.pop_back();
        }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubs(0,nums,ds,ans);
        return ans;
}
void helperComb3(int start,int k,int n,vector<int>&path,vector<vector<int>> &res){
        if(k==0&&n==0){
            res.push_back(path);
            return;
        }
        if(k==0|| n<=0) return;
        for(int i=start;i<=9;i++){
            path.push_back(i);
            helperComb3(i+1,k-1,n-i,path,res);
            path.pop_back();
        }
}
vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helperComb3(1,k,n,path,res);
        return res;
        
}

void helperLetter(string &digits,int idx,string&path,vector<string>&res,vector<string>&mapping){
        if(idx==digits.size()){
            res.push_back(path);
            return;
        }
        string letters= mapping[digits[idx]-'0'];
        for(char ch:letters){
            path.push_back(ch);
            helperLetter(digits, idx + 1, path, res, mapping);
            path.pop_back();
        }
}
vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs", "tuv","wxyz"};
        vector<string>res;
        string path;
        helperLetter(digits,0,path,res,mapping);
        return res;
}

int main() {


    return 0;
}
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



int main() {


    return 0;
}
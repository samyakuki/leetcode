#include <bits/stdc++.h>
using namespace std;

string convert2binary(int n){
   string res="";
    while (n!=1)
    {
        if(n%2==0)res+='0';
        else res+='1';
        n=n/2;
        /* code */
    }

    reverse(res.begin(),res.end());
    return res;
    
}

int convert2decimal(string s){
    int len=s.length();
    int num=0;
    int powe=1;
    for(int i=len-1;i>=0;i--){
        if(s[i]=='1') num+=powe;
        powe*=2;
    }  
    return num; 
}
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

bool isBitUnset(int n, int i) {
    return (n & (1 << i)) == 0;
}

bool isOdd(int n) {
    return (n & 1);
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); 
        count++;
    }
    return count;
}
int setRightmostUnsetBit(int n) {
    return n | (n + 1);
}
void swapXOR(int &a, int &b) {
    if (a != b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}
void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&& divisor==-1)
        return INT_MAX;

        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);
        long long res=0;
        while(a>=b){
            long long temp=b,multiple=1;
            while((temp<<1)<=a){
                temp<<=1;
                multiple<<=1;
            }
            a-=temp;
            res+=multiple;
        }
        if((dividend<0)^(divisor<0)) res=-res;



        return (int)res;
        
}

int singleNumber(vector<int>& nums) {
        int res=0;
        for(int num:nums){
            res=res^num;
        }
        return res;
}
int minBitFlips(int start, int goal) {
        int n=start^goal;
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
}

int xorUpto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; 
}

int xorRange(int L, int R) {
    return xorUpto(R) ^ xorUpto(L - 1);
}
int main(){


    return 0;
}
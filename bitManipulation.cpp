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
int main(){


    return 0;
}
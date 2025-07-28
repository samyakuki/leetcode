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
pair<int,int> findTwoOdd(vector<int>&arr){
    int xorAll=0;
    for(int num:arr){
        xorAll^=num;
    }
    int rightmostSetBit=xorAll&-xorAll;
    int firstOdd=0,secondOdd=0; 
    for(int num:arr){
        if(num&rightmostSetBit) firstOdd^=num;
        else secondOdd^=num;
    }   
    return {firstOdd,secondOdd};
}

void printPrimeFactors(int n) {
    while ((n & 1) == 0) {
        cout << 2 << " ";
        n >>= 1; 
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2)
        cout << n;
}
vector<int> getAllDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);          
            if (i != n / i)              
                divisors.push_back(n / i); 
        }
    }

    return divisors;
}
int countPrimes(int n) {
        int count=0;
        vector <bool>isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int p=2;p*p<=n;p++){
            if(isPrime[p]){
                for(int i=p*p;i<n;i+=p){
                    isPrime[i]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
        
}


const int N = 1e6 + 1; 
vector<int> spf(N);   
void buildSieve() {
    for (int i = 0; i < N; i++)
        spf[i] = i; 
    for (int p = 2; p * p < N; ++p) {
        if (spf[p] == p) { 
            for (int i = p * p; i < N; i += p) {
                if (spf[i] == i)
                    spf[i] = p; 
            }
        }
    }
}

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}




int main(){


    return 0;
}
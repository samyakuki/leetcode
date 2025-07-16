#include<bits/stdc++.h>
using namespace std;

// Count digits (safe for n=0)
int count(int n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

// Faster digit count (but fails for n=0)
int OptimalCount(int n) {
    if (n == 0) return 1;  // Handle n=0 case
    return (int)(log10(n) + 1);
}

// Reverse a number
int revNum(int n) {
    int revN = 0;
    while (n != 0) {
        int ld = n % 10;
        revN = revN * 10 + ld;
        n /= 10;
    }
    return revN;
}

// Check if palindrome
void isPalindrome(int n) {
    if (n == revNum(n)) cout << "Palindrome";
    else cout << "Not palindrome";
}

// Brute-force GCD
int gcd(int n, int m) {
    for (int i = min(n, m); i > 0; i--) {
        if (n % i == 0 && m % i == 0) {
            return i;
        }
    }
    return 1;
}

// Optimized GCD (Euclidean algorithm)
int OptimalGcd(int n, int m) {
    while (n > 0 && m > 0) {
        if (n > m) n %= m;
        else m %= n;
    }
    return (n == 0) ? m : n;
}

// Safe integer power (avoid floating-point errors)
int intPow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Correct Armstrong check
bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int cnt = OptimalCount(n);
    
    while (n > 0) {
        int num = n % 10;
        sum += intPow(num, cnt);  // Use integer exponentiation
        n /= 10;
    }
    
    return (sum == original);
}

void printDiv(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

vector<int> findDivisors(int n) {
   
    vector<int> divisors; 

    
    int sqrtN = sqrt(n); 
    
   
    for (int i = 1; i <= sqrtN; ++i) { 
        
        if (n % i == 0) { 
            divisors.push_back(i); 

            if (i != n / i) {
                divisors.push_back(n / i); 
            }
        }
    }
    
    return divisors; 
}
bool checkPrime(int n){ 
    int cnt = 0;
    for(int i = 1; i<=n; i++){ 
        if(n%i ==0){ 
            cnt = cnt+1;
        }
    }

    if(cnt==2){
        return true;
    }
    else{ 
        return false; 
    }
}


int main() {
    int n = 36;
    int m = 9;

    // cout << "Digit count (basic): " << count(n) << endl;
    // cout << "Digit count (optimal): " << OptimalCount(n) << endl;
    // cout << "Reversed number: " << revNum(n) << endl;
    
    // cout << "Is palindrome? ";
    // isPalindrome(n);
    
    // cout << endl << "GCD (brute-force): " << gcd(n, m) << endl;
    // cout << "GCD (optimal): " << OptimalGcd(n, m) << endl;
    // cout << "2^3 (using intPow): " << intPow(2, 3) << endl;
    // cout << "Is Armstrong? " << isArmstrong(153) << endl;

    printDiv(n);
    cout<<endl;
        vector<int> divisors = findDivisors(n);
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    return 0;
}
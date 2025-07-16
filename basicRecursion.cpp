#include <bits/stdc++.h>
using namespace std;
int cnt=0;

void print(){
    if( cnt==3) return;
    cout<<cnt;
    cnt++;
    print();
}

void printNameN(int i,int n){
    if(i>n) return;
    cout <<"samya ";
    printNameN(i+1,n);
}

void print1toN(int i,int n){
    if(i>n) return;
    cout <<i<< " ";
    print1toN(i+1,n);

}

void printNto1(int i,int n){
    if(i<n) return;
    cout <<i<< " ";
    printNto1(i-1,n);

}

int sumOfN(int n){
    if(n==0){
        
        return 0;
    }
    return n+sumOfN(n-1);
}

int factN(int n){
    if (n==0 ){
        return 1;
    }
    return n*factN(n-1);
}

void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}
void returnRevArr(int arr[],int n){
    int revA[n];
    for(int i=0;i<n;i++){
        revA[n-i-1]=arr[i];
    }
    printArray(revA,n);
}
void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}

void palindromeString(string s, int start, int end) {
    if (start >= end) {
        cout << "pal";
        return;
    }
    if (s[start] != s[end]) {
        cout << "not pal";
        return;
    }
    palindromeString(s, start + 1, end - 1);
}

int fibonaaci(int n){
    if(n<=1){
        return n;
    }

    

    return fibonaaci(n-1)+fibonaaci(n-2);
}

int main(){

        // print();
        // cout<<endl;
        // printNameN(1,5);
        // cout<<endl;
        // print1toN(1,7);
        // cout<<endl;
        // printNto1(7,1);
        // cout<<endl;
        // cout<<sumOfN(10);
        // cout<<endl;
        // cout<<factN(4);
        // cout<<endl;
        // int arr[5]={1,2,3,6,8};
        // int size = sizeof(arr) / sizeof(arr[0]);
        // returnRevArr(arr,size);
        // cout<<endl;
        // string s="madam";
        // palindromeString(s,0,s.length()-1);

        cout<<fibonaaci(4);



    return 0;
}
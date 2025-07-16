#include <bits/stdc++.h>
using namespace std;

int main(){
  int arr[]={1,2,2,2,2,3,5,4};
  int n=sizeof(arr)/sizeof(arr[0]);
//   int hash[100000]={0};
//   string s="aaabcghhfuyd";

//   for(int i=0;i<5;i++){
//     hash[arr[i]]+=1;
//   }

unordered_map<int,int> mpp;
for(int i=0;i<n;i++){
    mpp[arr[i]]++;
}
int maxf=0;

for(auto it:mpp){
    maxf=max(maxf,it.second);
}
cout<<maxf;
//   int q;
//   cout<<"enter ";
//   cin>>q;
//   while(q--){
//     int num;
//     cin>>num;
//     cout<<mpp[num];
//   }

    return 0;
}
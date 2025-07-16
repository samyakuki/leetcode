#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[],int n){
  
    for(int j=0;j<n-1;j++){
      for(int i=0;i<n-j-1;i++){

        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
   }
   printArray(arr,n);

}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    printArray(arr, n);
}


void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
                swap(arr[i],arr[mini]);

        }
    }
    printArray(arr,n);
}
int main(){
    int a[]={23,4,224,5,78,89};
    int n=sizeof(a)/sizeof(a[0]);
    printArray(a,n);
    cout<<endl;
    // bubbleSort(a,n);
    // selectionSort(a,n);
    insertionSort(a,n);
   



    return 0;
}
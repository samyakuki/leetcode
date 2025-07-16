#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=4;

    for(int i=0;i<=n;i++){
        for (int j=0;j<n-i;j++){
            cout<<" ";
        }
        char ch='A';
        int breakoint=(2*i+1)/2;
        for(int k=0;k<2*i+1;k++){
            cout<<ch;
            if(k< breakoint) ch++;
            else ch--;
        }
           for (int j=0;j<n-i;j++){
            cout<<" ";
        }
        cout<<endl;
    }    

    
    return 0;
}

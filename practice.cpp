#include<bits/stdc++.h>
using namespace std;





int main() {
    vector<vector<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    

    for (int i = 0; i < a.size(); ++i) {
        if(a[i][1]>a[i+1][1]){
            a[i][0]=a[i][0];
        }
      
    }

    return 0;
}

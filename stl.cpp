#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5,20);
    v.push_back(337);
    v.push_back(73);
    v.push_back(37);
    v.push_back(74);

    vector<int>:: iterator it=v.begin();
    it++;
    cout<<*(it)<<" ";

    for(auto it:v){
        cout<<it <<" ";
    }

    return 0;
}

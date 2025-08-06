#include<bits/stdc++.h>
using namespace std;
//we have given row number n and we have to find all the elements of row of pascal triangle

int util(int n,int r){
    long long ans = 1;
    for(int i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
vector<int> BruteForce(int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        int value = util(n-1,i);
        temp.push_back(value);
    }
    return temp;
}

vector<int> optimalApproach(int n){
    vector<int> temp;
    long long ans = 1;
    temp.push_back(1);
    for(int i=1;i<n;i++){
        ans*=(n-i);
        ans/=(i);
        temp.push_back(ans);
    }
    return temp;
}
int main(){
    int row = 4;
    vector<int> ans = optimalApproach(row);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
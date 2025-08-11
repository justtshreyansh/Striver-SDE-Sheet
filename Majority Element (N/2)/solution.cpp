#include<bits/stdc++.h>
using namespace std;
int bruteForce(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        int count = 0;
        for(int j=i;j<arr.size();j++){
            if(arr[i]==arr[j]) count++;
        }
        if(count>arr.size()/2) return arr[i]; 
    }
    return -1;
}

int betterSolution(vector<int> &arr){
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>arr.size()/2)return it.first;
    }
    return -1;
}
//moore's voting algorithms
int optimalSolution(vector<int> &arr){
    int count = 0;
    int ele = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            count =1;
            ele = arr[i];
        }
        else if(arr[i]==ele) count++;
        else count--;
    }
    count =0;

    for(int i=0;i<arr.size();i++ ){
        if(arr[i]==ele) count++;
    }
    if(count>arr.size()/2) return ele;


    return -1;
}
int main(){
    vector<int> arr = {2,2,1,1,1,2,2};
    cout<<optimalSolution(arr)<<endl;
    return 0;
}
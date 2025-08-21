#include<bits/stdc++.h>
using namespace std;
//this question has two variations first is that we have to tell true or false other is that we have to give indices

pair<int,int> bruteForce(vector<int> &arr,int target){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
}

pair<int,int> optimalVariation2(vector<int> &nums,int target){
    map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int rem = target-nums[i];
            if(mpp.find(rem)==mpp.end()){
               mpp[nums[i]] = i;
            }
            else{
                return {i,mpp[rem]};
            }
       }
       return {-1,-1};
}

bool optimalSolution(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==target) return true;
        else if(arr[i]+arr[j]>target) j--;
        else i++;
    }
    return false;
}
int main(){
    vector<int> arr = {};
    int target = 9;
    return 0;
}
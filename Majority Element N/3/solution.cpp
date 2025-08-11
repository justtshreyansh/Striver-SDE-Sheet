#include<bits/stdc++.h>
using namespace std;
int bruteForce(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        int count = 0;
        for(int j=i;j<arr.size();j++){
            if(arr[i]==arr[j]) count++;
        }
        if(count>arr.size()/3) return arr[i]; 
    }
    return -1;
}

int betterSolution(vector<int> &arr){
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>arr.size()/3)return it.first;
    }
    return -1;
}
//moore's voting algorithms
vector<int> optimalSolution(vector<int> &arr){
    int count1 = 0;
    int ele1 = INT_MIN;
    int count2 =0;
    int ele2= 0;
    for(int i=0;i<arr.size();i++){
        if(count1==0 && arr[i]!=ele2){
            count1 = 1;
            ele1= arr[i];
        }
        else if(count2==0 && arr[i]!=ele1){
            count2 =1;
            ele2 = arr[i];
        }
        else if(ele1==arr[i]) count1++;
        else if(ele2==arr[i]) count2++;
        else {
            count1--;
            count2--;
        }
    }
    
    count1 = 0;
    count2 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==ele1) count1++;
        else if(arr[i]==ele2) count2++;
    }
    vector<int> ans;
    if(count1>arr.size()/3) ans.push_back(ele1);
    if(count2>arr.size()/3) ans.push_back(ele2);




    return ans;
}
int main(){
    vector<int> arr = {11,33,33,11,33,11};
    vector<int> ans = optimalSolution(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
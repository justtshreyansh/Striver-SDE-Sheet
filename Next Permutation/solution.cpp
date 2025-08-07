#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr,vector<vector<int>> &ans,vector<int>&temp,vector<int> &freq){
    if(temp.size()==arr.size()){
        ans.push_back(temp);
        return ;
    }

    for(int i=0;i<arr.size();i++){
        if(!freq[i]){
            temp.push_back(arr[i]);
            freq[i] = 1;
            solve(arr,ans,temp,freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}
void BruteForce(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int>temp;
    vector<int> freq(arr.size(),0);
    solve(arr,ans,temp,freq);
    sort(ans.begin(),ans.end());
   
    int index = -1;
    for(int i=0;i<ans.size();i++){
        bool flag = true;
        for(int j=0;j<ans[i].size();j++){
            if(ans[i][j]!=arr[j]){
                flag = false;
                break;
            }
        }
        if(flag) index = i;
    }
    
    if(index==ans.size()-1){
        for(int i=0;i<arr.size();i++){
            cout<<ans[0][i]<<" ";
        }
    }
    else{
         for(int i=0;i<arr.size();i++){
            cout<<ans[index+1][i]<<" ";
        }
    }
}

void betterSolution(vector<int> &arr){
    cout<<next_permutation(arr.begin(),arr.end())<<endl;//if more permuation can be generated return true
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

void optimalApproach(vector<int> &arr){
    int n = arr.size();
    int breakPoint = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            
            breakPoint = i;
            break;
        }
    }
    if(breakPoint==-1){
        reverese(arr.begin(),arr.end());
        return ;
    }
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[breakPoint]){
            swap(arr[i],arr[breakPoint]);
            break;
        }
    }
    
    
    reverse(arr.begin()+breakPoint+1,arr.end());
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr= {2,1,5,4,3,0,0};
    optimalApproach(arr);
    return 0;
}

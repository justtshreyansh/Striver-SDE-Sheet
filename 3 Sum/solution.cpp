#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> bruteForce(vector<int> &arr){
    set<vector<int>> ans;
  
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                long long sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                if(sum==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                    
                }
                
            }
        }
    }
      vector<vector<int>> final(ans.begin(),ans.end());
      return final;
    
}

vector<vector<int>> optimalSolution(vector<int> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = arr.size()-1;
        while(j<k){
            long long sum = arr[i];
            sum+=arr[j];
            sum+=arr[k];
            if(sum==0){
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
            else if(sum<0){
                j++;
            }
            else k--;
        }
    }
    return ans;
}
int main(){
    return 0;
}
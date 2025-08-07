#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> optimalApproach(vector<vector<int>>&arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(ans.empty() || ans.back()[1] < start){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],end);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = optimalApproach(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }

    return 0;
}
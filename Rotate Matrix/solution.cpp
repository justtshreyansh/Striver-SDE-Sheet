#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>  BruteForce(vector<vector<int>> &matrix){
    
    int n =matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(m,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-i-1]= matrix[i][j];
        }
    }

    return ans;

}


void optimalApproach(vector<vector<int>> &matrix){
    int n =matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

     for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }



}
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = BruteForce(matrix);
    optimalApproach(matrix);
    return 0;
}
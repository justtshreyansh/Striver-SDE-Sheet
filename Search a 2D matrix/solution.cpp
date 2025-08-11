#include<bits/stdc++.h>
using namespace std;
bool bruteForce(vector<vector<int>> &matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target)return true;
        }
    }

    return false;

}

bool betterSolution(vector<vector<int>> &arr,int target){
    for(int i=0;i<arr.size();i++){
        int low = 0;
        int high = arr[i].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[i][mid]==target) return true;
            else if(arr[i][mid]>target) high = mid-1;
            else low = mid+1;
        }
    }
    return false;
}
//matrix is sorted in itself (every row is sorted and first element of any row is always greater than last element of any row).
bool optimalSolution(vector<vector<int>>&matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    long long high = m*n-1;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(matrix[mid/m][mid%m]==target) return true;
        else if(matrix[mid/n][mid%m]>target) high = mid-1;
        else low = mid+1;
    }
    return false;
}
//each row and column is sorted 
bool matSearch(vector<vector<int>> &mat, int x) {
       
          int n = mat.size();
        int m = mat[0].size();
        
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(x==mat[i][j]){
                return true;
            }else if(x>mat[i][j]){
                i++;
            }else{
                j--;
            }
        }
        
        return false;
    }
int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{6,7,8,9},{10,11,12,13}};
    int target = 3;
    cout<<betterSolution(matrix,target);
    return 0;
}
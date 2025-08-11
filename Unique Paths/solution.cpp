#include<bits/stdc++.h>
using  namespace std;
int solve(int m,int n,int i,int j){
    if(i>=n || j>=m) return 0;
    if(i==n-1 || j==m-1){
        return 1;
    }

    return solve(m,n,i+1,j) + solve(m,n,i,j+1);
}
void bruteForce(int m,int n){
   cout<<solve(m,n,0,0);
}

int betterSolution(int m,int n,int i,int j,vector<vector<int>> &dp){
    
    if(i>=n || j>=m) return 0;
    if(i==n-1 || j==m-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    dp[i][j] = betterSolution(m,n,i+1,j,dp) + betterSolution(m,n,i,j+1,dp);
    return dp[i][j];



}
int main(){
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout<<betterSolution(m,n,0,0,dp);

    return 0;
}
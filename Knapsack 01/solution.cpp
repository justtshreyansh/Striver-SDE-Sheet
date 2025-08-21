#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &weight,vector<int>&value,int capacity,int n){
    if(n==0 || capacity==0) return 0;//if no items or capacity is 0
    //if the weight of the item is greater than the knapsack
    if(weight[n-1]>capacity){
        return knapsack(weight,value,capacity,n-1);
    }
    //take and not take and find the max
    else{
        return max(value[n-1]+knapsack(weight,value,capacity-weight[n-1],n-1),knapsack(weight,value,capacity,n-1));
    }
}
int memoization(vector<int> &weight,vector<int> &value,int capacity,int n,vector<vector<int>> &dp){
    if(n==0 || capacity==0){
        return 0;
    }
    if(dp[n][capacity]!=-1) return dp[n][capacity];

    if(weight[n-1]>capacity){
        dp[n][capacity] = memoization(weight,value,capacity,n-1,dp);
        
    }
    else{
        dp[n][capacity] = max(value[n-1]+memoization(weight,value,capacity-weight[n-1],n-1,dp),memoization(weight,value,capacity,n-1,dp));
    }
    return dp[n][capacity];
}
int tabulation(vector<int> &weight,vector<int> &value,int capacity,int n,vector<vector<int>> &dp){
    for(int i=0;i<=capacity;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(weight[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][capacity];
}
int main(){

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int capacity = 7;
    int n = weight.size();

    cout << "Maximum value in Knapsack = " << knapsack(weight, value, capacity, n) << endl;
    return 0;
}
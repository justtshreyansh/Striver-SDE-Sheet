#include<bits/stdc++.h>
using namespace std;
int bruteForce(vector<int> &arr){
    long long maxi = LLONG_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            long long sum = 0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int betterSolution(vector<int> &arr){
    long long maxi = LLONG_MIN;
    for(int i=0;i<arr.size();i++){
        long long sum = 0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            maxi = max(sum,maxi);
        }
    }
    return maxi;
}

int optimalSolution(vector<int> &arr){
    long long maxi = LLONG_MIN;
    long long sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi  = sum;
        }
        if(sum<0) sum = 0;
    }
    return maxi;
}


//additional follow up to print the maxsum sub array
void printSubArray(vector<int> &arr){
    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0;i<arr.size();i++){
        if(sum==0) start = i;
        sum+=arr[i];
        if(sum>maxi){
            maxi  = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0) sum = 0;
    }
    
    for(int i=ansStart;i<=ansEnd;i++) cout<<arr[i]<<" ";
    
}
int main(){
    vector<int> arr=  {-2,1,-3,4,-1,2,1,-5,4};
    
    printSubArray(arr);
    return 0;
}
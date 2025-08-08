#include<bits/stdc++.h>
using namespace std;
pair<int,int> bruteForce(vector<int> &arr){
    int n = arr.size();
    int repeating  = -1;
    int missing  = -1;
    for(int i=1;i<=n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(i==arr[j]) count++;
        }

        if(count==2) repeating = i;
        if(count==0) missing  = i;
    }

    return {repeating,missing};
}

pair<int,int> betterSolution(vector<int> &arr){
    map<int,int> mpp;
    int n = arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int repeating  = -1;
    int missing = -1;
    for(int i=1;i<=n;i++){
        if(mpp[i]==2) repeating = i;
        if(mpp[i]==0) missing = i;
    }
    return {repeating,missing};
}

pair<int,int> optimalApproach(vector<int> &arr){
   
    int n = arr.size();
    long long firstN = n*(n+1)/2;
    long long firstN2=  n*(n+1)*(2*n+1)/6;
    long long sumN = 0;
    long long sumN2 = 0;
    for(int i=0;i<n;i++){
        sumN+=arr[i];
        sumN2+=pow(arr[i],2);
    }

    int x2y2 = firstN2-sumN2;//diff of squares of number of 1to n and array
    int xy = firstN-sumN;//diff of sum of 1 to n and array elements
    int val1=  x2y2/xy; //this is x+y
    int val2 = xy;//this is x-y

    int val3 = val1+ val2;//this is 2x
    int x = val3/2;
    int y = val1-x;
    

   
    return {y,x};
    
}
int main(){
    vector<int> arr = {1,2,3,1,4,6};
    pair<int,int> p = optimalApproach(arr);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//Given the row number row and col number col find the element at the position.

//Brute force is calculate the n! r! and (n-r)!
int factorial(int n){
    long long ans = 1;
    for(int i=1;i<=n;i++) ans*=i;
    return ans;
}
int BruteForce(int n,int r){
    long long ans = factorial(n)/(factorial(r)*factorial(n-r));
    return ans;
}

int optimalApproach(int n,int r){
    long long ans = 1;
    for(int i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
int main(){
    int row = 4;
    int col =3;
    cout<<BruteForce(row-1,col-1)<<endl;
    cout<<optimalApproach(row-1,col-1)<<endl;
    return 0;
}
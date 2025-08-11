#include<bits/stdc++.h>
using namespace std;
int bruteForce(int x,int n){
    long long ans = 1;
    for(int i=0;i<n;i++){
        ans*=x;
    }
    return ans;
}

int betterSolution(int x,int n){
    return pow(x,n);
}
double solve(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double half = solve(x, n / 2);
        if (n % 2 == 1) {
            return half * half * x;
        } else {
            return half * half;
        }
    }

double optimalApproach(double x, int n) {
        long long N = n;
        if (N < 0) {
            N = -N;
            return 1 / solve(x, N);
        }
        return solve(x, N);
    }
int main(){
    return 0;
}
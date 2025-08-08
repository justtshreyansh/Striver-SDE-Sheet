#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

   
   
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
    
     
    cout<<endl;
}
void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high) return ;

    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    vector<int> arr = {9,5,2,3,4,6,7,1,8};
    mergeSort(arr,0,arr.size()-1);
    
    return 0;
}
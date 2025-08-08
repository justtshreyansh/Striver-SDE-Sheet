#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high,int &count){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            count+=(mid-left+1);
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
    
     
    
}
void mergeSort(vector<int> &arr,int low,int high,int &count){
    if(low>=high) return ;

    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid,count);
    mergeSort(arr,mid+1,high,count);
    merge(arr,low,mid,high,count);
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    int count = 0;
    mergeSort(arr,0,arr.size()-1,count);
    cout<<count<<endl;
    return 0;
}
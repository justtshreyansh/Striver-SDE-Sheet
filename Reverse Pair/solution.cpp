class Solution {
public:
int count = 0;
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left =low;
    int right = mid+1;
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
}
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * 1LL *arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
    void  mergeSort(vector<int> &arr,int low,int high){
        if(low>=high) return ;

        long long mid = low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        count+=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
    }
    int reversePairs(vector<int>& arr) {
        mergeSort(arr,0,arr.size()-1);
        return count;
    }
};
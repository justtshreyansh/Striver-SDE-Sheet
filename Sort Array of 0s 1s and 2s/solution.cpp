#include <bits/stdc++.h>
using namespace std;
void bruteForce(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
void better(vector<int> &arr)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }

    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < arr.size(); i++)
    {
        arr[i] = 2;
    }

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

void optimalSolution(vector<int> &arr){
    int mid = 0;
    int high = arr.size()-1;
    int low= 0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else {
            swap(arr[mid],arr[high]);
            high--;

        }
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    optimalSolution(arr);
    return 0;
}
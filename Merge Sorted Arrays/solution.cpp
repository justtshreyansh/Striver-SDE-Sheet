#include <bits/stdc++.h>
using namespace std;
vector<int> bruteForce(vector<int> &arr1, vector<int> &arr2)
{
    int left = 0;
    int right = 0;
    vector<int> ans;
    while (left < arr1.size() && right < arr2.size())
    {
        if (arr1[left] <= arr2[right])
        {
            ans.push_back(arr1[left]);
            left++;
        }
        else
        {
            ans.push_back(arr2[right]);
            right++;
        }
    }

    while (left < arr1.size())
    {
        ans.push_back(arr1[left]);
        left++;
    }

    while (right < arr2.size())
    {
        ans.push_back(arr2[right]);
        right++;
    }
    return ans;
}

void optimalSolution(vector<int> &arr1,vector<int> &arr2){
    int left = arr1.size()-1;
    int right = 0;
    while(left>=0 && right<arr2.size() && arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
        left--;
        right++;
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(int i=0;i<arr1.size();i++) cout<<arr1[i]<<" ";
    for(int i=0;i<arr2.size();i++) cout<<arr2[i]<<" ";
}
int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 5, 6};
   optimalSolution(arr1,arr2);
    return 0;
}
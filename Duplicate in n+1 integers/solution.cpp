#include <bits/stdc++.h>
using namespace std;
int bruteForce(vector<int> &arr)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mpp[arr[i]])
            return arr[i];
        else
            mpp[arr[i]]++;
    }

    return 1;
}
int optimalApproach(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];

    do{
        fast = arr[arr[fast]];
        slow = arr[slow];
    }
    while(slow!=fast);

    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << bruteForce(arr);
    return 0;
}
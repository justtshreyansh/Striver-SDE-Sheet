#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<int> &freq)
{
    if (temp.size() == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            temp.push_back(arr[i]);
            freq[i] = 1;
            solve(arr, ans, temp, freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> freq(arr.size(), 0);
    solve(arr, ans, temp, freq);
    return ans;
}

int main()
{
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    unordered_map<int, int> countMap; // Using a map to store element frequencies

    for(int i=0; i<arr.size(); i++)
    {
        countMap[arr[i]]++; // Increment the count for each element
    }

    int target = arr.size() / 2;

    vector<int>res;
    for(auto elementCount : countMap)
    {
        if(elementCount.second >= target)
        {
            res.push_back(elementCount.first); // Push the elements with counts greater than or equal to the target
        }
    }

    if(res.size() > 0)
    {
        cout<<"The majority elements are: ";
        for(auto i : res) cout<<i<<" ";
    }
    else
    {
        cout<<"No majority elements.";
    }

    return 0;
}

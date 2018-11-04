#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

void printGroup(vector<int>& ar, vector<bool>& inc)
{
    for (int i=0; i<ar.size(); i++)
    {
        if (inc[i])
            cout << ar[i] << " ";
    }
    cout << "$";
}


bool findGroupsOfFour(vector<int>& ar, vector<bool>& inc, int k, int count, int pos)
{
    if (count < 0)
        return false;

    // value over
    if (k < 0)
        return false;
    
    
    if (k > 0)
    {
        if (count == 0)
            return false; // we can continue
        else
        {
            for (int i=pos; i<ar.size(); i++)
            {
                inc[i] = true;
                if (k-ar[i] < 0)
                    break;
                else
                {
                    if (findGroupsOfFour(ar, inc, k-ar[i], count-1, i+1))
                    {
                        inc[i]  = false;
                        return true;
                    }
                }
                inc[i] = false;
            }
        }
    }
    else if (count == 0)
    {
        printGroup(ar, inc);
        return true;
    }
    return false;
}

bool findGroupsOfFour(vector<int>& array, int k)
{
    bool found = false;
    vector<bool> include(array.size(), false);
    for (int i=0; i<array.size(); i++)
    {
        include[i] = true;
        if (findGroupsOfFour(array, include, k-array[i], 3, i+1))
            found = true;
        include[i] = false;
    }
    return found;
}
int main() {
    
    int T=0;
    cin >> T;
    vector<vector<int>> arrays;
    vector<int> ks(T);
    for (int i=0; i<T; i++)
    {
        int n = 0;
        int k = 0;
        cin >> n >> k;
        
        vector<int> array(n); // let's just not use pointers
        ks[i] = k;
        for (int j=0; j<n; j++)
        {
            cin >> array[j];
        }
        
        sort(array.begin(), array.end());
        arrays.push_back(array);
    }
    
    for (int i=0; i<T; i++)
    {
        if (!findGroupsOfFour(arrays[i], ks[i]))
            cout << "-1";
    
        cout << endl;
    }
    
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

void printGroup(vector<int>& ar, vector<bool>& inc)
{
    string group;
    for (int i=0; i<ar.size(); i++)
    {
        if (inc[i])
        {
            group += to_string(ar[i]) + " ";
        }
    }
    
    group += "$";
    cout << group;
}


bool findGroupsOfFour(vector<int>& ar, vector<bool>& inc, int k, int count, int pos)
{
    bool found = false;
    // value over
    if (k < 0)
        return false;
    else if (k > 0)
    {
        if (count == 0)
            return false; // we can continue
        else
        {
            int prev = 100000;
            for (int i=pos; i<ar.size(); i++)
            {
                if (prev==ar[i])
                    continue;
                prev = ar[i];
                
                inc[i] = true;
                if (k-ar[i] < 0)
                {
                    inc[i]  = false;
                    break;
                }
                else
                {
                    if (findGroupsOfFour(ar, inc, k-ar[i], count-1, i+1))
                    {
                        found = true;
                    }
                }
                inc[i] = false;
            }
        }
    }
    else if (count == 0)
    {
        printGroup(ar, inc);
        found = true;
    }
    return found;
}

void findGroupsOfFour(vector<int>& array, int k)
{
    vector<bool> include(array.size(), false);
    set<string> groups;
    bool found = false;
    int prev=100000;
    for (int i=0; i<array.size(); i++)
    {
        if (prev==array[i])
            continue;
        prev = array[i];
        include[i] = true;
        if (findGroupsOfFour(array, include, k-array[i], 3, i+1))
        {
            found = true;
        }
        include[i] = false;
    }
    if (!found)
        cout << "-1";
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
        
        vector<int> array(n);
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
        findGroupsOfFour(arrays[i], ks[i]);
        cout << endl;
    }
    

    
    return 0;
}

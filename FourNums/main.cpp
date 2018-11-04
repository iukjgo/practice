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


bool findGroups(vector<int>& ar, vector<bool>& inc, int k, int count, int pos)
{
    if (count < 0)
        return false;

    // value over
    if (k < 0)
        return false;
    else if (k > 0)
    {
        if (count == 0)
            return true; // we can continue
        else
        {
            for (int i=pos; i<ar.size(); i++)
            {
                inc[i] = true;
                bool test = findGroups(ar, inc, k-ar[i], count-1, i+1);
                inc[i] = false;
                if (!test) return false;
            }
        }
    }
    else if (count == 0)
    {
        printGroup(ar, inc);
        return false;
    }
    return false;
}

int main() {
    
    int T=0;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int n = 0;
        int k = 0;
        cin >> n >> k;
        
        vector<int> array(n);
        vector<bool> include(n, false);
        for (int j=0; j<n; j++)
        {
            cin >> array[j];
        }
        
        sort(array.begin(), array.end());
        
        for (int j=0; j<n; j++)
        {
            include[j] = true;
            findGroups(array, include, k-array[j], 3, j+1);
            include[j] = false;
        }
        
        
    }
    
    // 1 3 4 9
    //10
    // 9, 3, 1
    // 7, 2, 2,
    // 4, 1, 3,
    // 0, 0, 4,
    
    
    // 1 4 8 17
    
    return 0;
}

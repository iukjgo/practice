#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include "CastleRun.h"
using namespace std;

int main() {
    int T=0;
    cin >> T;

    while (T--) {
        int vertices = 0;
        cin >> vertices;

        Graph test(vertices);
        
        for (int u=0; u<vertices; u++) {
            for (int v=0; v<vertices; v++) {
                int edge;
                cin >> edge;
                
                if (edge == 1)
                    test.addEdge(u, v);
            }
        }
        if (CastleRun::solve(test))
            cout << "True" << endl;
        else
            cout << "False" << endl;

    }


    return 0;
}

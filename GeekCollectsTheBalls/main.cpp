#include <iostream>
#include <vector>

using namespace std;
int main() {

    int T=0;
    cin >> T;
    while (T--) {
        int N, M;

        cin >> N >> M;

        vector<int> A(N);
        vector<int> B(M);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }
        
        vector<int> sumA;
        vector<int> sumB;

        int a=0;
        int b=0;
        int curSumA=0;
        int curSumB=0;

        while (a < N && b < M) {
            if (A[a] < B[b]) {
                curSumA += A[a++];
            }
            else if (A[a] > B[b]) {
                curSumB += B[b++];
            }
            else if (A[a] == B[b]) {
                int val = A[a];
                while (a < N && A[a] == val) {
                    curSumA += A[a++];
                }
                while (b < M && B[b] == val) {
                    curSumB += B[b++];
                }
                sumA.push_back(curSumA);
                sumB.push_back(curSumB);
                curSumA = 0;
                curSumB = 0;
            }
        }
        while (a < N) {
            curSumA += A[a++];
        }

        while (b < M) {
            curSumB += B[b++];
        }

        sumA.push_back(curSumA);
        sumB.push_back(curSumB);

        int sum=0;
        // sumA.size() == sumB.size()
        for (int i = 0; i < sumA.size(); i++) {
            sum += sumA[i] > sumB[i] ? sumA[i] : sumB[i];
        }
        cout << sum << endl;
    }

    return 0;
}
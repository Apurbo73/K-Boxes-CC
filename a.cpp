#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), pos(N + 1);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        vector<long long> B(N);
        for (int i = 0; i < N; i++)
            cin >> B[i];

        for (int i = 0; i < N; i++)
            pos[A[i]] = i;

        vector<long long> ans(N, 0);
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long sumTopK = 0;

        for (int lvl = 1; lvl <= N; lvl++)
        {
            int idx = pos[lvl];
            ans[idx] = sumTopK;

            long long val = B[idx];
            if ((int)minHeap.size() < K)
            {
                minHeap.push(val);
                sumTopK += val;
            }
            else if (!minHeap.empty() && val > minHeap.top())
            {
                sumTopK -= minHeap.top();
                minHeap.pop();
                minHeap.push(val);
                sumTopK += val;
            }
        }

        for (int i = 0; i < N; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
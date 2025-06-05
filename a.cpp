#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector < int > A(N);
        vector < vector < int >> pos(K + 1);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            pos[A[i]].push_back(i);
        }

        vector < vector < long long >> dp(K + 2);
        dp[K].resize(pos[K].size(), 0);

        for (int i = K - 1; i >= 1; --i) {
            int n1 = (int) pos[i].size();
            int n2 = (int) pos[i + 1].size();
            dp[i].resize(n1, LLONG_MAX);

            int p = 0;
            for (int j = 0; j < n1; ++j) {
                int curPos = pos[i][j];



                auto it = lower_bound(pos[i + 1].begin(), pos[i + 1].end(), curPos);

                if (it != pos[i + 1].end()) {
                    int idx = it - pos[i + 1].begin();
                    long long cost = abs((long long) curPos - pos[i + 1][idx]) + dp[i + 1][idx];
                    if (cost < dp[i][j]) dp[i][j] = cost;
                }
                if (it != pos[i + 1].begin()) {
                    int idx = (it - pos[i + 1].begin()) - 1;
                    long long cost = abs((long long) curPos - pos[i + 1][idx]) + dp[i + 1][idx];
                    if (cost < dp[i][j]) dp[i][j] = cost;
                }
            }
        }

        for (int s = 0; s < N; ++s) {
            long long ans = LLONG_MAX;

            auto & v1 = pos[1];
            if (!v1.empty()) {
                auto it = lower_bound(v1.begin(), v1.end(), s);
                if (it != v1.end()) {
                    int idx = it - v1.begin();
                    long long cost = abs((long long) s - v1[idx]) + dp[1][idx];
                    if (cost < ans) ans = cost;
                }
                if (it != v1.begin()) {
                    int idx = (it - v1.begin()) - 1;
                    long long cost = abs((long long) s - v1[idx]) + dp[1][idx];
                    if (cost < ans) ans = cost;
                }
            } else {
                ans = 0;
            }
            cout << ans << (s == N - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
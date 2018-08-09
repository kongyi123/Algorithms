#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
struct Data {
    int y, h;
    bool operator<(const Data& r) const {
        return y < r.y;
    }
};
int n;
Data dat[MAXN];
int dp[2][MAXN];
const int INF = 2100000000;

void proc(int caseidx) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int px;
        cin >> px >> dat[i].y >> dat[i].h;
    }
    sort(dat + 1, dat + n + 1);

    dp[0][0] = -INF;
    for (int j = 1; j <= n; ++j) dp[0][j] = INF;

    int p = 0, pp = 1;
    for (int i = 1; i <= n; ++i) {
        p ^= 1;  pp ^= 1;
        for (int j = 0; j <= i; ++j) {
            dp[p][j] = INF;
            if (dp[pp][j] < INF && dp[pp][j] <= dat[i].y) {
                dp[p][j] = max(dat[i].y, dp[pp][j] + dat[i].h);
            }
            if (j > 0 && dp[pp][j - 1] < INF) {
                dp[p][j] = min(
                    dp[p][j],
                    dp[pp][j - 1] + dat[i].h
                );
            }
        }
    }

    int ans = INF;
    for (int j = 0; j <= n; ++j) {
        if (dp[n % 2][j] < INF) {
            ans = j;
            break;
        }
    }
    cout << "Case #" << caseidx << '\n';
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        proc(i);
    }
    return 0;
}

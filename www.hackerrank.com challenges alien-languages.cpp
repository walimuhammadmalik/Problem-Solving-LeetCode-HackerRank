
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 100000007;

long long n, m, cnt[120000], d[120000], met[120000];
long long dd[1200000];

int main() {
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            cnt[i] = 1;
        }
        for(int q = 1; q < 30; ++q) {
            d[q] = 0;
            for(int i = 1; i <= n; ++i) {
                met[i] = 0;
                if (2 * i > n) {
                    d[q] += cnt[i];
                    d[q] %= MOD;
                    cnt[i] = 0;
                }
            }
            for(int i = 1; i <= n; ++i) {
                met[2 * i] += cnt[i];
            }
            long long now = 0;
            for(int i = 1; i <= n; ++i) {
                now += met[i];
                now %= MOD;
                cnt[i] = now;
            }
        }
        for(int i = 0; i < 1200000; ++i) {
            dd[i] = 0;
        }
        dd[0] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < 30; ++j) {
                dd[i + j] += (dd[i] * d[j]) % MOD;
                dd[i + j] %= MOD;
            }
        }
        cout << dd[m] % MOD << endl;
    }
    return 0;
}

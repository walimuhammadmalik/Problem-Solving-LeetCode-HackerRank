#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXN 200002

int n, k;
int a[MAXN];
ll d[MAXN];
ll f[MAXN];

void go(int l, int r, int k, int ff) {
	if (l > r) return;
	if (l == r) {
		a[l] = ff;
		return;
	}
	int n = r - l + 1;
	k -= n - 1;
	for (int i = 0; i < n; ++i) {
		if (d[i] + d[n - 1 - i] <= k && f[i] + f[n - 1 - i] >= k)
                   {
			a[l] = ff + i;
			int k1 = d[i];
			int k2 = k - d[i];
			if (k2 > f[n - 1 - i]) {
				k1 += k2 - f[n - 1 - i];
				k2 = f[n - 1 - i];
			}
			go(l + 1, l + i, k1, ff);
			go(l + i + 1, r, k2, ff + i + 1);
			return;
		}
	}
}

inline void solve()
{
	scanf("%d%d", &n, &k);
	if (k < d[n] || k > f[n]) {
		puts("-1");
		return;
	}
	go(0, n - 1, k, 0);
	for (int i = 0; i < n; ++i)
		printf("%d%c", a[i] + 1, " \n"[i + 1 == n]);
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	for (int i = 2; i < MAXN; ++i) {
		d[i] = i - 1 + d[i / 2] + d[(i - 1) / 2];
		f[i] = 1LL * (i - 1) * i / 2;
	}

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		solve();

	return 0;
}

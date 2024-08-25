#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)    cerr<<"["#x<<" = "<<(x)<<"]\n"
#define PP(x,i) cerr<<"["#x<<i<<" = "<<x[i]<<"]\n"
#define P2(x,y) cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]\n"
#define TM(a,b) cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v) sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int mod = int(1e9) + 7;
const int N = 501;

#define FF int
const int maxE = 40010;
const int maxN = 10010;
const int INF = 0x3f3f3f3f;

struct Dinic {
    int ne;
    int hd[maxN], work[maxN], q[maxN], Level[maxN], from[maxE], to[maxE], next[maxE];
    FF cap[maxE], flow[maxE];

    Dinic() {init();}

    void init() {
        ne = 0;
        memset(hd, -1, sizeof(hd));
    }

    void add(int x, int y, FF c) {
        from[ne] = x, to[ne] = y, cap[ne] = c, flow[ne] = 0, next[ne] = hd[x], hd[x] = ne++;
        from[ne] = y, to[ne] = x, cap[ne] = 0, flow[ne] = 0, next[ne] = hd[y], hd[y] = ne++;
    }

    void addU(int x, int y, FF c) {
        from[ne] = x, to[ne] = y, cap[ne] = c, flow[ne] = 0, next[ne] = hd[x], hd[x] = ne++;
        from[ne] = y, to[ne] = x, cap[ne] = c, flow[ne] = 0, next[ne] = hd[y], hd[y] = ne++;
    }

    bool dinic_bfs(int S, int T) {
        int head = 0, tail = 0;
        memset(Level, 0, sizeof(Level));
        Level[S] = 1;
        q[tail++] = S;
        while(head < tail) {
            int u = q[head++];
            for(int i = hd[u]; i != -1; i = next[i]) {
                int v = to[i];
                if(flow[i] < cap[i] && !Level[v]) {
                    Level[v] = Level[u] + 1;
                    q[tail++] = v;
                    if(v == T) return 1;
                }
            }
        }
        return 0;
    }

    FF dinic_dfs(int u, int T, FF pMin) {
        if(u == T || !pMin) return pMin;
        FF ret = 0;
        for(int& i = work[u]; i != -1; i = next[i]) {
            int v = to[i];
            FF f;
            if(Level[v] == Level[u] + 1 && (f = dinic_dfs(v, T, min(pMin, cap[i] - flow[i])))) {
                flow[i] += f;
                flow[i ^ 1] -= f;
                ret += f;
                pMin -= f;
                if(pMin == 0) break;
            }
        }
        return ret;
    }

    FF dinic(int S, int T) {
        FF ret = 0;
        while(dinic_bfs(S, T)) {
            memcpy(work, hd, sizeof(hd));
            ret += dinic_dfs(S, T, INF);
        }
        return ret;
    }
} dn;

int n, m;

vector<pair<PII, int>> E;
int visited[N];

void dfs(int cur, vector<vector<int>>& G) {
    if(visited[cur]) return;
    visited[cur] = 1;
    for(auto i : G[cur]) dfs(i, G);
}


int parent[N];
int cut[N][N];


int main() {
    cin >> n >> m;
    assert(3 <= n && n <= 500);
    assert(3 <= m && m <= 1e4);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(u != v);
        assert(1 <= w && w <= 1e5);
        u--, v--;
        E.pb(mp(mp(u, v), w));
    }

    MM(cut, 0x3f);

    for(int i = 1; i < n; i++) {
        dn.init();
        for(auto e : E) dn.addU(e.x.x, e.x.y, e.y);

        int S = i, T = parent[i];
        int x = dn.dinic(S, T);

        MM(visited, 0);
        vector<vector<int>> G(n + 1);
        for(int j = 0; j < dn.ne; j++) if(dn.cap[j] > dn.flow[j]) G[dn.from[j]].pb(dn.to[j]);

        dfs(S, G);

        for(int j = i + 1; j < n; j++) if(visited[j] && parent[j] == parent[i]) parent[j] = i;
        cut[i][parent[i]] = cut[parent[i]][i] = x;
        for(int j = 0; j < i; j++) {
            cut[i][j] = cut[j][i] = min(x, cut[parent[i]][j]);
        }
    }

    LL res = 1;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            res = res * cut[i][j] % mod;
    cout << res << endl;
    return 0;
}

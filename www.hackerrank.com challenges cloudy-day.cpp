

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

vector <ii> seq;
int delt[Maxn];
ll sum[Maxn];

ll maximumPeople(vector <long> p, vector <long> x, vector <long> y, vector <long> r) {
    for (int i = 0; i < p.size(); i++)
        seq.push_back(ii(x[i], p[i]));
    sort(seq.begin(), seq.end());
    for (int i = 0; i < y.size(); i++) {
        int lef = y[i] - r[i], rig = y[i] + r[i];
        int ind1 = lower_bound(seq.begin(), seq.end(), ii(lef, 0)) - seq.begin();
        int ind2 = lower_bound(seq.begin(), seq.end(), ii(rig + 1, 0)) - seq.begin();
        delt[ind1]++; delt[ind2]--;
    }
    ll res = 0;
    int cur = 0;
    for (int i = 0; i < seq.size(); i++) {
        cur += delt[i];
        if (cur == 0) res += seq[i].second;
        else if (cur == 1) sum[i] = seq[i].second;
        if (i) sum[i] += sum[i - 1];
    }
    ll add = res;
    for (int i = 0; i < y.size(); i++) {
        int lef = y[i] - r[i], rig = y[i] + r[i];
        int ind1 = lower_bound(seq.begin(), seq.end(), ii(lef, 0)) - seq.begin();
        int ind2 = lower_bound(seq.begin(), seq.end(), ii(rig + 1, 0)) - seq.begin();
        if (ind2 > 0) {
            ll got = sum[ind2 - 1];
            if (ind1 > 0) got -= sum[ind1 - 1];
            res = max(res, add + got);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    vector<long> x(n);
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    int m;
    cin >> m;
    vector<long> y(m);
    for(int y_i = 0; y_i < m; y_i++){
       cin >> y[y_i];
    }
    vector<long> r(m);
    for(int r_i = 0; r_i < m; r_i++){
       cin >> r[r_i];
    }
    ll result = maximumPeople(p, x, y, r);
    cout << result << endl;
    return 0;
}

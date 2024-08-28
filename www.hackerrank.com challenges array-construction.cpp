#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int q;
    cin >> q;
    for(int Q = 0; Q < q; Q++){
        int n, s, k;
        cin >> n >> s >> k;
        int dp[s+1][k+1];
        for(int i = 0; i <= s; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        int done = 0;
        for(int c = 1; c <= n; c++){
            int d = c*(n-c);
            for(int i = 0; i + c <= s; i++){
                for(int j = 0; j + d <= k; j++){
                    if(dp[i][j] != 0 && dp[i+c][j+d] == 0){
                        dp[i+c][j+d] = c;
                    }
                }
            }
            if(dp[s][k]){
                int diff[n];
                for(int i = 0; i < n; i++) diff[i] = 0;
                int cs = s;
                int ck = k;
                while(cs > 0 || ck > 0){
                    int a = dp[cs][ck];
                    int b = a*(n-a);
                    diff[n-a]++;
                    cs -= a;
                    ck -= b;
                }
                int r = 0;
                for(int i = 0; i < n; i++){
                    r += diff[i];
                    cout << r << " ";
                }
                cout << endl;
                done = 1;
                break;
            }
        }
        if(!done){
            cout << -1 << endl;
        }
    }
}

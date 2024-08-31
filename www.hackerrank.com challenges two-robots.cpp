#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define fi first
#define se second
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>

vector<int> G[2*100000+5];
int fdp[1005][1005];
LL dp[1005][1005], T=0;
pii Q[1000+5];
LL cost(int i,int j){
	if(i==0)
		return abs(Q[j].fi-Q[j].se);
	return abs(Q[j].fi-Q[j].se) + abs(Q[j].fi-Q[i].se);
}
int N;
LL rec(int i,int j){
	if(i==N or j==N)return 0;
	if(fdp[i][j]==T)
		return dp[i][j];
	fdp[i][j] = T;
	int k = max(i,j) + 1;
	return dp[i][j] = min(rec(k,j)+cost(i,k),rec(i,k)+cost(j,k));
}
int main(){
	//fre;
	int t, M;
	cin>>t;
	while(t--){
		T++;
		cin>>M>>N;
		for(int i=1;i<=N;++i){
			scan(Q[i].fi);
			scan(Q[i].se);
		}
		printll(rec(0,0));
	}
}

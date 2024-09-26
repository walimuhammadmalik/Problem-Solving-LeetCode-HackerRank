#include <bits/stdc++.h>

using namespace std;

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,s[2600][2600],dp[2600][2600],lwr,upr,ts;
long long ans1,ans2;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
dp[0][0]=1;
for (int i=0;i<=2500;i++)
 s[0][i]=1;
 
for (int i=0;i<n;i++)
{
 for (int j=0;j<=k;j++)
 {
  upr=j;
  lwr=j-(n-i-1);
  if (lwr<0)lwr=0;
  ts=s[i][upr];
  if (lwr>0)ts-=s[i][lwr-1];
  ts+=bs;
  ts%=bs;
  dp[i+1][j]=ts;
 }   
 for (int j=0;j<=k;j++)
 {
  s[i+1][j]=dp[i+1][j];
  if (j){s[i+1][j]=(s[i+1][j-1]+s[i+1][j])%bs;}
 }
}

ans1=0;
for (int i=k;i>=0;i-=2)
{ans1=(ans1+dp[n][i])%bs;}cout<<ans1;//<<endl;

for (int i=0;i<=n;i++)
 for (int j=0;j<=k;j++)
  dp[i][j]=s[i][j]=0;


dp[0][0]=1;
for (int i=0;i<=2500;i++)
 s[0][i]=1;
 
for (int i=0;i<n;i++)
{
 for (int j=0;j<=k;j++)
 {
  lwr=n-i-1;
  
  dp[i+1][j]=dp[i][j];
  if (j)dp[i+1][j]+=(1ll*dp[i][j-1]*lwr)%bs;
  dp[i+1][j]%=bs;
 }   
 for (int j=0;j<=k;j++)
 {
  s[i+1][j]=dp[i+1][j];
  if (j){s[i+1][j]=(s[i+1][j-1]+s[i+1][j])%bs;}
 }
}

ans1=0;
for (int i=0;i<=k;i++)
 ans1=(ans1+dp[n][i])%bs;
 cout<<" "<<ans1<<endl;
 
cin.get();cin.get();
return 0;
}

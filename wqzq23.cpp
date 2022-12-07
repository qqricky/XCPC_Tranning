#include<bits/stdc++.h>
#define ll long long
#define _for(i,a,b) for(int i=a;i<b;i++)
#define mod 100000007
using namespace std; 

ll cnt=0;
ll n,s,a,b;
ll dp[2][1010*1010]={0}; //滚动数组 
//ll tmp[1010*1010]={0}; //存滚动数组的上一层 

int main(void){
	memset(dp,0,sizeof(dp));
	ll t1,t2,x1;
	cin>>n>>s>>a>>b;
	_for(i,1,n){_for(j,0,n*n){
        int now=i&1;
		if(i==1&&(j==1||j==0)) dp[now][j]=1;
		else if(j>i*(i+1)/2+10) {
			dp[now][j]=0; break;
		}
		else if(j<i) dp[now][j]=dp[now^1][j];
		else if(j>=i&&i!=1){
			dp[now][j]=(dp[now^1][j]+dp[now^1][j-i])%mod;
		}
}//_for(k,0,n*n) tmp[k]=dp[k];
    }
	ll maxT=n*(n-1)/2;
	for(t1=0;t1<=maxT;t1++){
		t2=maxT-t1;
		if((s-a*t1+b*t2)%n==0){
			x1=(s-a*t1+b*t2)/n;
			cnt=(cnt+dp[n&1][t1])%mod;
		}
	}
	cout<<cnt%mod;
	return 0;
}
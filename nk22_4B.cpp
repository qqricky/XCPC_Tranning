#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bitset<403>ok[11][402][402];
const ll modd=998244353;
int mod;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%modd;
		}
		b/=2;
		a=a*a%modd;
	}
	return ans;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	int i;int a,b,c;
	for(i=1;i<=n;i++){
		int m;
		cin>>m;
		int j;
		for(j=1;j<=m;j++){
			cin>>a>>b>>c;
			int h,hh,hhh;
			for(h=a;h<=400;h++){
				if(ok[i][h][b][c]==0)break;
				for(hh=b;hh<=400;hh++){
					if(ok[i][h][hh][c]==0)break;
					for(hhh=c;hhh<=400;hhh++){
						if(ok[i][h][hh][hhh]==0)break;
						ok[i][h][hh][hhh]=1;
					}
				}
			}
		}
	}
	cin>>mod;
	std::mt19937 rng(mod);
	std::uniform_int_distribution<> u(1,400);
	int lastans=0;ll anss=0;
	for (int i=1;i<=q;i++)
	{
  	  int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
  	  int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
   	 int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
   	 lastans=0;
   	 //cout<<IQ<<' '<<EQ<<' '<<AQ<<'\n';
   	 int h;
   	 
   	 for(h=1;h<=n;h++){
   	 	if(ok[h][IQ][EQ][AQ])lastans++;
		}
		anss+=(ll)lastans*ksm(mod,q-i)%modd;
		anss%=modd;
	}
	cout<<anss<<'\n';
	

}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll a[201];
ll dp[201][200];
ll k,b,d,l,r;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b=b/2;
	}
	return ans;
}
ll dfs(int pos,int cnt, bool lim,bool qiandao)
{
    if(pos == -1&&cnt==0)
        return 1;
        if(pos==-1&&cnt!=0)return 0;
        
    if(!lim && dp[pos][cnt] != -1)return dp[pos][cnt];
        ll up = lim ? a[pos] : b-1;
        if (lim==false){
        	if(qiandao==false){
        		if(d==0){
        			return dp[pos][cnt]=(up)*dfs(pos-1,cnt,false,true)+dfs(pos-1,cnt,false,false);
				}
				return dp[pos][cnt]=dfs(pos-1,cnt,false,false)+dfs(pos-1,cnt-1,false,true)+(up-1)*dfs(pos-1,cnt,false,true);
			}
        	return dp[pos][cnt]=(b-1)*dfs(pos-1,cnt,lim,true)+dfs(pos-1,cnt-1,lim,true);
		}else{
			ll tmp=0;
			ll cntt=0;
			if(qiandao==false){
				tmp+=dfs(pos-1,cnt,0==up,false);
				cntt++;
			}else{
				tmp+=dfs(pos-1,cnt-(0==d),0==up,true);
				cntt++;
			}
			int flag=0;
			if(d!=0){
				if(d==up){
					flag=1;
					tmp+=dfs(pos-1,cnt-1,d==up,true);
					cntt++;
				}
				if(d<up){
					tmp+=dfs(pos-1,cnt-1,d==up,true);
					cntt++;
				}
			}
			if(flag==1){
				tmp+=(up+1-cntt)*dfs(pos-1,cnt,false,true);
			}else{
				tmp+=(up+1-cntt-1)*dfs(pos-1,cnt,false,true)+dfs(pos-1,cnt,true,true);
			}
			return tmp;
		}
}
    ll solve(ll x,ll d)
    {
    	int i,j;
    	for(i=0;i<=70;i++)for(j=0;j<=70;j++)dp[i][j]=-1;
      int pos = 0;
      while(x)
      {
      a[pos++] = x % b;
      x /= b;
      }
      return dfs(pos - 1,d, true,false);
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>k>>b>>d>>l>>r;
		int i;
		ll ans=0;
		for(i=1;i<=70;i++){	
			ll tmp=solve(r,i)-solve(l-1,i);
			//cout<<solve(r,i)<<' '<<solve(l-1,i)<<endl;
			ans=ans+tmp*ksm(i,k)%mod;
		}
		cout<<ans<<'\n';
	}
    cout.flush();
    system("pause");
}
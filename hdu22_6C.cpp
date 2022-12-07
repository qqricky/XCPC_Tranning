#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
vector<int>path;
ll sum[100]={};
ll num[100]={};
ll count(ll n){
    if(n==0)return 0;
	ll pren = 0,pres=0,m,p;
	for(int i = 62;i>=0;i--){
		// if(n<(1ll<<i)) continue;
		p = 1ll<<i;
		num[i] = n/p;
		sum[i] = num[i]*(num[i]+1)/2*p-pres;
		pres = num[i]*(num[i]+1)/2*p;
		num[i] = num[i]-pren;
		pren = n/p;
		// cout << i << ' ' << num[i] << ' ' << sum[i] << endl;
	}
}
ll sum2[100]={};
ll num2[100]={};
ll count2(ll n){
	ll pren = 0,pres=0,m,p;
	for(int i = 62;i>=0;i--){
		// if(n<(1ll<<i)) continue;
		p = 1ll<<i;
		num2[i] = n/p;
		sum2[i] = num2[i]*(num2[i]+1)/2*p-pres;
		pres = num2[i]*(num2[i]+1)/2*p;
		num2[i] = num2[i]-pren;
		pren = n/p;
		// cout << i << ' ' << num2[i] << ' ' << sum2[i] << endl;
	}
}
bool ck(ll x){
    for(int y:path){
        if(y==0){
            x=(x+1)/2;
        }else{
            x/=2;
        }
    }
    return x<=0;
}
ll tmpnum[60];
ll tmpsum[60];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(sum,0,sizeof(sum));
        memset(num,0,sizeof(num));
        memset(sum2,0,sizeof(sum2));
        memset(num2,0,sizeof(num2));
        path.clear();
        ll n,x;
        cin>>n>>x;
        ll acu=n*(n+1)/2;
        while(x!=1){
            if(x&1)path.push_back(1);
            else path.push_back(0);
            x/=2;
        }
        reverse(path.begin(),path.end());
        // for(int x:path){
        //     cout<<x;
        // }
        // cout<<endl;
        count(n);
        ll l=0,r=n;
        while(l<r){
            ll mid=(l+r+1)>>1;
            // cout<<mid<<endl;
            if(ck(mid)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        // for(int j=0;j<=n;j++)cout<<' '<<ck(j)<<'\n';
        // cout<<"!!!!!"<<endl;
        // cout<<'!'<<l<<'\n';
        count2(l);
        for(int j=0;j<=62;j++){
            num[j]-=num2[j];
            sum[j]-=sum2[j];
            // if(sum[j])cout<<j<<' '<<num[j]<<' '<<sum[j]<<endl;
        }
        ll ans=n*(n+1)/2-l*(l+1)/2;
        ll val=0;
        ll cnt=n-l;
        for(int x:path){
            ans/=2;
            if(x){
                ans-=cnt;
            }else{
                ans+=cnt;
            }
        }
        ans+=val;
        // num[0]=(n+1)/2;
        // sum[0]=num[0]*(1+((n&1) ? n : n-1))/2;
        // for(int i=1;i<=62;i++){
        //     ll now=1ll<<i;
        // }
        // int ncnt=0;
        // for(int x:path){
        //     ll tsum=0;
        //     ll tnum=0;
        //     if(x==1){
        //         sum[0]=(sum[0]-num[0])/2;
        //         // if((sum[0]-num[0])&1){
        //         //     cout<<"djasklfjakls"<<endl;
        //         // }
        //     }else{
        //         sum[0]=(sum[0]+num[0])/2;
        //         // if((sum[0]+num[0])&1){
        //         //     cout<<sum[0]<<' '<<num[0]<<endl;
        //         // }
        //     }
        //     sum[0]=0;
        //     num[0]=0;
        //     for(int j=1;j<=62;j++){
        //         num[j-1]+=num[j];
        //         sum[j-1]+=sum[j]/2;
        //         num[j]=0;
        //         sum[j]=0;
        //     }
        //     sum[0]=tsum;
        //     num[0]=tnum;
        //     // ncnt++;
        //     // cout<<ncnt<<"-----------------------\n";
        //     // for(int j=0;j<=50;j++){
        //     //     if(num[j]){
        //     //         cout<<j<<' '<<num[j]<<' '<<sum[j]<<endl;
        //     //     }
        //     // }
        // }
        // ll ans=0;
        // for(int j=0;j<=62;j++){
        //     // if(sum[j])cout<<j<<' '<<num[j]<<' '<<sum[j]<<endl;
        //     ans+=sum[j];
        // }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}
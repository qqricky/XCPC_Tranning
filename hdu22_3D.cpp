#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define int ll
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int pai[100];
ll len[N];
ll pre[25][N];
ll n,h;
ll t[N];
ll ans;
ll d[20][N];
const double delta=0.980;
const double eps=1e-12;
bool check(int mid){
	int i;
	int st=0;
	ll now=0;
	for(i=1;i<=n;i++){
		int f=mid-st+1;
		if(f<0)continue;
		if(f>len[pai[i]])f=len[pai[i]];
		now=now+(pre[pai[i]][f]);
		st+=t[pai[i]];
	}
    // cout<<now<<endl;
	return now>=h;
}
ll suan(){
	ll l=0;
	ll r=5e6;
	while(l<r){
		//cout<<l<<' '<<r<<endl;;
		int mid=l+r>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
    if(l==5e6)l=1e18;
    return l;
}

ll calc()
{
    return suan();
}
void SA()
{
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%n+1;
        int y=rand()%n+1;
        // while(x==y){
        //     y=rand()%n+1;
        // }
        swap(pai[x],pai[y]);
        // for(int i=1;i<=n;i++){
        //     cout<<pai[i]<<' ';
        // }
        // cout<<endl;
        ll tmp=suan();
        ll del=tmp-ans;
        if(del<0){
            ans=tmp;
        }
        else if(exp(-del/T)*RAND_MAX<=rand()){
            swap(pai[x],pai[y]);
        }
    }
}
signed main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));srand(rand());srand(rand());
    int T;
    cin>>T;
    int val=T;
    double t0=(double)clock()/CLOCKS_PER_SEC;
    while(T--){
        cin>>n>>h;
        for(int i=1;i<=n;i++){
            cin>>t[i]>>len[i];
            for(int j=1;j<=len[i];j++){
                cin>>d[i][j];
            }
            pre[i][0]=0;
            for(int j=1;j<=len[i];j++){
                pre[i][j]=d[i][j]+pre[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            pai[i]=i;
        }
        ans=1e18;
        // SA();
        while((double)clock()/CLOCKS_PER_SEC-t0<4.0/val){
//            random_shuffle(pai+1,pai+n+1);
            SA();
        }
        t0=(double)clock()/CLOCKS_PER_SEC;
        if(ans==1e18)cout<<-1<<'\n';
        else cout<<ans<<'\n'; 
    }
    // cout.flush();
    // system("pause");
    return 0;
}
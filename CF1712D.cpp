#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
// #pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N];
ll b[N];
struct node
{
    int x,pos;
}nd[N];
bool cmp(node a,node b){
    if(a.x==b.x)return a.pos<b.pos;
    return a.x<b.x;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            nd[i].pos=i;
            nd[i].x=a[i];
            b[i]=a[i];
        }
        if(k==n){
            ll ans=1000000000;
            cout<<ans<<'\n'; 
            continue;
        }
        sort(a+1,a+n+1);
        if(k>1){
            sort(nd+1,nd+n+1,cmp);
            a[0]=0,a[n+1]=0;
            b[0]=0,b[n+1]=0;
            ll res=0;
            for(int i=1;i<n;i++){
                res=max(res,min(b[i],b[i+1]));
            }
            for(int i=1;i<k;i++){
                b[nd[i].pos]=1000000000;
                res=max(res,b[nd[i].pos-1]);
                res=max(res,b[nd[i].pos+1]);
            }
            ans=min(2*a[k],(ll)1000000000);
            ll val=nd[k].x;
            for(int j=k;j<=n;j++){
                if(nd[j].x!=val)break;
                res=max(res,b[nd[j].pos-1]);
                res=max(res,b[nd[j].pos+1]);
            }
            ans=max(ans,min(res,2*a[k+1]));
        }
        else if(n==2){
            ans=a[n];
        }
        else{
            a[0]=0,a[n+1]=0;
            b[0]=0,b[n+1]=0;
            sort(nd+1,nd+n+1,cmp);
            ll res=0;
            for(int i=1;i<n;i++){
                res=max(res,min(b[i],b[i+1]));
            }
            ll val=nd[1].x;
            for(int j=1;j<=n;j++){
                if(nd[j].x!=val)break;
                res=max(res,b[nd[j].pos-1]);
                res=max(res,b[nd[j].pos+1]);
            }
            ans=min(2*a[1],a[n]);
            ans=max(ans,min(res,2*a[k+1]));
            // if(a[1]!=a[2]){
            //     int p=pos[a[1]];
            //     ll r=b[p+1];
            //     ll l=b[p-1];
            //     ans=min(2*a[1],a[n]);
            //     ans=max(ans,min(2*a[2],max(l,r)));
            // }else{
            //     ans=min(2*a[1],a[n]);
            // }
            // ans=min(ans,(ll)1000000000);
        }
        cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}
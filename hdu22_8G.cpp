#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimise(2)
const int N=2e5+10;
const int INF=2147483640;
using namespace std;
struct edge{
	int u;
	int v;
	int val;
}edg[2000005];
int cnt=0;
int to[50004];
int shu[50004];
int f[50004];
int n;
unordered_map<short,bool>is[50004];
set<int>s[50004];
bool cmp(edge &a,edge &b){
	return a.val<b.val;
}
void made()
{
    int i;
    for(i=0; i<=n; i++)
        f[i]=i;
}
int find(int x)
{
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}
ll  kru(int n)
{
    sort(edg+1,edg+1+cnt,cmp);
     made();
    ll m=0,ans=0;
    int i,j;
    for(i=1; i<=cnt; i++)
    {
        int xx=find(edg[i].u);
        int yy=find(edg[i].v);
        if(xx==yy)
            continue;
        m++;
        ans +=edg[i].val;
        f[yy]=xx;
        if(m==n-1)
            break;
    }
    if(m<n-1){
        int k=12;
        while(1){
            k=(k+5)%998244353;
        }
    }
    else return ans;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int i;
        for(i=1;i<=n;i++){
        	cin>>shu[i];
        	to[shu[i]]=i;
            // is[i].clear();
            s[i].clear();
		}
		cnt=0;
		for(i=1;i<=n;i++){
			int j;
            int mi=INF;
            int too=n;
			for(j=max(i-250,1);j<=min(n,(int)i+250);j++){
                if(i==j)continue;
                // if(is[i][j]||is[j][i])continue;
                if(s[min(i,j)].count(max(i,j)))continue;
                int tmp=abs(j-i)*abs(shu[j]-shu[i]);
				if(tmp>n)continue;
                if(tmp<mi){
                    mi=tmp;
                    too=j;
                }
				// edg[++cnt].u=i;
				// edg[cnt].v=j;
				// edg[cnt].val=(j-i)*abs(shu[j]-shu[i]);
			}
            // for(j=i-1;j<=min(n,(int)i+250);j++){
            //     int tmp=(j-i)*abs(shu[j]-shu[i]);
			// 	if(tmp>n)continue;
            //     if(tmp<mi){
            //         mi=tmp;
            //         too=j;
            //     }
			// 	// edg[++cnt].u=i;
			// 	// edg[cnt].v=j;
			// 	// edg[cnt].val=(j-i)*abs(shu[j]-shu[i]);
			// }
            edg[++cnt].u=i;
            edg[cnt].v=too;
            edg[cnt].val=mi;
            s[min(i,too)].insert(max(i,too));
            // is[i][too]=1;is[too][i]=1;
		}
		for(i=1;i<=n;i++){
			int j;
            int mi=INF;
            int too=n;
			for(j=max(1,j-250);j<=min(n,(int)i+250);j++){
                if(i==j)continue;
                if(s[min(to[i],to[j])].count(max(to[i],to[j])))continue;
                int tmp=abs(to[i]-to[j])*abs(j-i);
				if(tmp>n)continue;
                if(tmp<mi){
                    mi=tmp;
                    too=to[j];
                }
				// edg[++cnt].u=to[i];
				// edg[cnt].v=to[j];
				// edg[cnt].val=abs(to[i]-to[j])*(j-i);
			}
            s[min(to[i],too)].insert(max(to[i],too));
            // is[to[i]][too]=is[too][to[i]]=1;
            edg[++cnt].u=to[i];
            edg[cnt].v=too;
            edg[cnt].val=mi;
		}
		cout<<kru(n)<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}
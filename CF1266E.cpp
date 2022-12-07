#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
unordered_map<int,int>v[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>q;
    while(q--){
        int s,t,u;
        cin>>s>>t>>u;
        if(v[s][t]){
            a[v[s][t]]++;
            if(a[v[s][t]]>0)sum++;
            v[s][t]=0;
        }
        v[s][t]=u;
        if(a[u]>0)sum--;
        a[u]--;
        cout<<sum<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}
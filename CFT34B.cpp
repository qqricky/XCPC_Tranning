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
int dis[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    int ans=0,ts=INF;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        dis[x]++;
        dis[x+y+1]--;
    }
    for(int i=1;i<=2e5;i++)dis[i]+=dis[i-1];
    for(int i=0;i<=480;i++){
        int cnt=0;
        for(int j=i;j<=2e5;j+=x){
            if(dis[j])cnt++;
        }
        if(cnt<ts){
            ts=cnt;
            ans=i;
        }
    }
    cout<<ans<<' '<<ts;
    cout.flush();
    //system("pause");
    return 0;
}
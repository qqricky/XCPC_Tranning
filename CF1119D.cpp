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
ll s[N];
vector<ll>dis;
ll sum[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    dis.push_back(1e18);
    for(int i=2;i<=n;i++){
        dis.push_back(s[i]-s[i-1]);
    }
    sort(dis.begin(),dis.end());
    sum[0]=dis[0]*n;
    for(int i=1;i<n;i++){
        
    }
    cout.flush();
    system("pause");
    return 0;
}
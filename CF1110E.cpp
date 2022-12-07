#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N];
ll b[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    map<ll,int>mp;
    bool flag=1;
    if(a[1]!=b[1]||a[n]!=b[n])flag=0;
    for(int i=2;i<=n;i++){
        mp[a[i]-a[i-1]]++;
    }
    for(int i=2;i<=n;i++){
        mp[b[i]-b[i-1]]--;
        if(mp[b[i]-b[i-1]]<0)flag=0;
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    cout.flush();
    //system("pause");
    return 0;
}
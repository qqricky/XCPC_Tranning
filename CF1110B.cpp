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
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1)v.push_back(a[i]-a[i-1]-1);
    }
    if(k>=n){
        cout<<n<<'\n';
        return 0;
    }
    ll ans=a[n]-a[1]+1;
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<k-1;i++){
        ans-=v[i];
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}
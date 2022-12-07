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
set<ll>v[100];
ll a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        int n;
        cin>>n;
        ll b;
        for(int i=0;i<=100;i++){
            v[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>b;
            a[i]=b;
            ll ori=b;
            int cnt=0;
            while(b%2==0){
                b/=2;
                cnt++;
            }
            v[cnt].insert(ori);
        }
        int ma=0;
        int pos;
        for(int i=0;i<=100;i++){
            if(v[i].size()>ma){
                ma=v[i].size();
                pos=i;
            }
        }
        cout<<n-ma<<'\n';
        for(int i=1;i<=n;i++){
            if(v[pos].count(a[i])==0){
                cout<<a[i]<<' ';
            }
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}
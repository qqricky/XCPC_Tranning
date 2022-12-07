#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll cnt[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v;
    ll ans=2;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i){
                v.push_back(n/i);
                break;
            }
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    if(v.size()==0){
        
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<cnt[n]<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}
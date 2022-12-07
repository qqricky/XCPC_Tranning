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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        if(n==1&&m==0){
            cout<<"YES\n";
            continue;
        }
        if(k<=2){
            cout<<"NO\n";
        }
        else if(k==3){
            if(m==n*(n-1)/2)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(m<=n*(n-1)/2&&m>=n-1)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}
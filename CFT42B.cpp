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
int a[5003];
unordered_map<ll,pair<int,int> >mp;
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
    sort(a+1,a+n+1);
    int ans=2;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            int dis=a[i]-a[j];
            if(mp[dis].first==j){
                mp[dis].second++;
                mp[dis].first=i;
                ans=max(ans,mp[dis].second);
            }
            else{
                mp[dis].first=i;
            }
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}
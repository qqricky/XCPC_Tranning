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
int b[N];
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
        map<int,pair<int,int> >mp;
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(x==1){
            cout<<"YES\n";
            continue;
        }
        for(int i=1;i<=n;i++)b[i]=a[i];
        sort(a+1,a+n+1);
        a[0]=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                mp[a[i]].first=i;
                mp[a[i]].second=i;
                continue;
            }
            mp[a[i]].second=max(mp[a[i]].second,i);
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(max(i-1,n-i)>=x){
                if(mp[b[i]].first>n-x&&mp[b[i]].second<x+1){
                    flag=0;
                    break;
                }
            }
            else{
                if(mp[b[i]].first>i||i>mp[b[i]].second){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}
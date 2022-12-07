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
        map<int,int>mp;
        ll n,m;
        cin>>n>>m;
        ll tot=0;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            mp[x]++;
            tot+=x;
        }
        if(tot<n){
            cout<<-1<<'\n';
            continue;
        }
        ll sum=0;
        bool flag=1;
        int ans=0;
        for(int i=0;i<=62;i++){
            //sum+=(1<<i)*mp[(1<<i)];
            if((n>>i)&1){
                if(mp[1<<i]){
                    mp[1<<i]--;
                    //continue;
                }
                else{
                    int pos;
                    for(int j=i+1;j<=62;j++){
                        if(mp[(1<<j)]>0){
                            pos=j;
                            break;
                        }
                    }
                    mp[1<<pos]--;
                    ans+=pos-i;
                    for(int j=i;j<pos;j++){
                        mp[1<<j]++;
                    }
                    //sum+=(1<<i);
                }
            }
            mp[1<<(i+1)]+=mp[(1<<i)]/2;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}
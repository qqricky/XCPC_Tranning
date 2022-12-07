#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
unordered_map<int,int>num;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        num.clear();
        int x;
        cin>>x;
        set<int>s;
        int r=0;
        ll ans=0;int mx=0;
        int mi=INF;
        for(int i=1;i<=n;i++){
            s.insert(a[i]);
            mx=max(mx,a[i]);
            mi=min(mi,a[i]);
            num[a[i]]++;
            if(mx-mi>x){
                r=i;
                break;
            }
        }
        if(r==0){
            cout<<0<<'\n';
            continue;
        }
        ans+=n-r+1;
        for(int i=1;i<=n;i++){
            num[a[i]]--;
            if(num[a[i]]==0){
                s.erase(a[i]);
                if(a[i]==mx){
                    mx=*s.rbegin();
                }else if(a[i]==mi){
                    mi=*s.begin();
                }
            }
            while(mx-mi<=x){
                r++;
                s.insert(a[r]);
                mx=max(mx,a[r]);
                mi=min(mi,a[r]);
                num[a[r]]++;
            }
            if(r>n){
                break;
            }
            ans+=n-r+1;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}
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
int n;
int p[N],f[N];
set<pair<int,int> >s;
bool vis[N]={};
int ans[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>f[i];
    for(int i=1;i<=n;i++){
        s.insert(make_pair(p[i],i));
    }
    int num=0;
    sort(f+1,f+n+1);
    for(int i=1;i<=n;i++){
        auto pr=make_pair(f[i],0);
        auto it=s.lower_bound(pr);
        if(it==s.begin())continue;
        it--;
        if(it!=s.end()){
            ans[(*it).second]=f[i];
            s.erase(it);
            vis[i]=1;
        }
    }
    int pos=n;
    for(int i=1;i<=n;i++){
        if(!ans[i]){
            while(vis[pos])pos--;
            vis[pos]=1;
            ans[i]=f[pos];
        }
    }
    //for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    //cout<<endl;
    for(int i=1;i<=n;i++){
        int ma=0,pos;
        for(int j=i+1;j<=n;j++){
            int f1=(ans[i]>p[i]);
            int f2=(ans[j]>p[j]);
            int f3=(ans[j]>p[i]);
            int f4=(ans[i]>p[j]);
            // if(ans[i]==5&&ans[j]==9){
            //     cout<<ans[i]<<' '<<p[i]<<endl;
            //     cout<<ans[j]<<' '<<p[j]<<endl;
            //     cout<<f1<<f2<<f3<<f4<<endl;
            // }
            if(f1+f2==f3+f4){
                if(ans[j]>ma){
                    ma=ans[j];
                    pos=j;
                }
            }
        }
        if(ans[i]<ma){
            swap(ans[i],ans[pos]);
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout.flush();
    //system("pause");
    return 0;
}
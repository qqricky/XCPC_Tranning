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
int f[N];
vector<int>mp[N];
int ind[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int>s;
        memset(ind,0,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++)mp[i].clear();
        int cnt=n;
        for(int i=1;i<=n;i++){
            cin>>ind[i];
            if(!ind[i]){
                s.insert(i);
                f[i]=1;
                continue;
            }
            for(int j=1;j<=ind[i];j++){
                int x;
                cin>>x;
                mp[x].push_back(i);
            }
        }
        for(int i=1;i<=n;i++)sort(mp[i].begin(),mp[i].end());
        int ans=1;
        set<int>ss;
        while(!s.empty()||!ss.empty()){
            auto it=s.begin();
            int u=*it;
            //cout<<"waht "<<u<<endl;
            s.erase(it);
            cnt--;
            for(int i=0;i<mp[u].size();i++){
                int val=mp[u][i];
                ind[val]--;
                if(ind[val]==0){
                    if(val>u){
                        f[val]=f[u];
                        s.insert(val);
                    }
                    else{
                        f[val]=f[u]+1;
                        ss.insert(val);
                    }
                    ans=max(ans,f[val]);
                }
            }
            if(s.empty()){
                s=ss;
                ss.clear();
            }
        }
        if(cnt){
            cout<<-1<<'\n';
            continue;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}
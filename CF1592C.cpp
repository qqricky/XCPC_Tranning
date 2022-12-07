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
int val[N];
vector<int>mp[N];
int flag;
int acu;
map<int,int>mpp;
void dfs(int now,int fa){
    if(mp[now].size()==1&&now!=1){
        mpp[val[now]]++;
        return ;
    }
    for(int j=0;j<mp[now].size();j++){
        if(mp[now][j]==fa)continue;
        dfs(mp[now][j],now);
        val[now]^=val[mp[now][j]];
    }
    if(mpp[acu]>1)flag=1;
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
        mpp.clear();
        flag=0;
        int n,k;
        cin>>n>>k;
        int x,y;
        acu=0;
        int pre=0;
        for(int i=1;i<=n;i++){
            mp[i].clear();
            cin>>val[i];
            acu^=val[i];
        }
        //cout<<acu<<endl;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        dfs(1,0);
        if(acu==0||flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}
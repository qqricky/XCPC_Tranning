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
vector<bool>ans;
bool dfs(vector<bool>v,ll now,ll sum,int cnt){
    if(sum==n){
        ans=v;
        return 1;
    }
    //cout<<sum<<' '<<now<<endl;
    if(cnt>3||abs(sum)>n+100)return 0;
    if(sum<n){
        v.push_back(0);
        if(dfs(v,now+1,sum-now*now,cnt+1));
        v.pop_back();
        v.push_back(1);
        if(dfs(v,now+1,sum+now*now,0))return 1;
    }
    else{
        v.push_back(1);
        if(dfs(v,now+1,sum+now*now,cnt+1));
        v.pop_back();
        v.push_back(0);
        if(dfs(v,now+1,sum+now*now,0))return 1;
    }
    return 0;
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
    while(t--)
    {
        cin>>n;
        vector<bool>v;
        dfs(v,1,0,0);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    //cout.flush();
    system("pause");
    return 0;
}
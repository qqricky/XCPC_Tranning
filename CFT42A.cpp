#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int f[N]={};
vector<int>v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r,s,p;
    cin>>r>>s>>p;
    set<int>st;
    int ans=0;
    for(int i=1;i<=N-1;i++)f[i]=i;
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        int val;
        if(y>s){
            val=r-x+1+y-s;
        }
        else{
            val=(r-x)+1+s-y+1;
        }
        v.push_back(val);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int val:v){
        ans=max(ans,f[val]);
        f[val]=f[f[val]+1];
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}
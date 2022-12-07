#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
unordered_map<string,string>mp;
string pos[N];
unordered_map<string,int>val;
int n;
string st;
void dfs(string now,int rk){
    if(rk>n)return;
    pos[rk]=now;
    dfs(mp[now],rk+1);
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>st>>n;
    for(int i=1;i<=n;i++){
        string x,y;
        int z;
        cin>>x>>z>>y;
        mp[x]=y;
        val[x]=z;
    }
    if(n==1){
        cout<<st<<' '<<val[st]<<" -1";
        return 0;
    }
    dfs(st,1);
    int l=1,r=n-1;
    int pace=1;
    cout<<pos[n]<<' '<<val[pos[n]]<<' ';
    while(l<=r){
        if(pace){
            cout<<pos[l]<<'\n';
            cout<<pos[l]<<' '<<val[pos[l]]<<' ';
            l++;
        }
        else{
            cout<<pos[r]<<'\n';
            cout<<pos[r]<<' '<<val[pos[r]]<<' ';
            r--;
        }
        pace^=1;
    }
    cout<<"-1";
    cout.flush();
    //system("pause");
    return 0;
}
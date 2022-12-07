#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int now=1;
int rk=1;
bool vis[N]={};
bool v[N]={};
vector<int>mp[N];
int f[N]={};
int ex;
bool find(int no){
    if(v[no])return 0;
    if(!vis[no]){
        now=no;
        cout<<no<<'\n';
        return 1;
    }
    for(int j=0;j<mp[no].size();j++){
        if(v[mp[no][j]])continue;
        if(find(mp[no][j]))return 1;
    }
    return 0;
}
inline void fd(int no){
    while(!find(no)){
        v[no]=1;
        no=f[no];
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int q;
    read(q);
    while(q--){
        int tp;
        read(tp);
        if(tp==1){
            int x;
            read(x);
            mp[x].push_back(++rk);
            f[rk]=x;
        }
        else{
            int x;
            read(x);
            vis[x]=1;
            if(x==now){
                fd(x);
            }
            else{
                cout<<now<<'\n';
            }
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}
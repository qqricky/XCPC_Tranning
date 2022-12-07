#pragma GCC optimise(2)
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a,b,n;
bool ck(ll x,int y){
    ll ans=1;
    while(y){
        if(y&1)ans*=x;
        if(ans>=n)return 1;
        y>>=1;
        x*=x;
    }
    return 0;
}
short dfs(int x,int y){
    if(ck(x,y))return 1;
    if(x==1&&ck(2,y))return 3;
    short f1=dfs(x+1,y);
    if(f1==0)return 1;
    short f2=dfs(x,y+1);
    if(f2==0)return 1;
    if(f1==3||f2==3)return 3;
    return 0;
}
short dfs2(int x,int y){
    if(ck(x,y))return 1;
    if(x==1&&ck(2,y))return 3;
    short f1=dfs2(x,y+1);
    if(f1==0)return 1;
    short f2=dfs2(x+1,y);
    if(f2==0)return 1;
    if(f1==3||f2==3)return 3;
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>n;
    if(a==1&&ck(2,b)){
        cout<<"Missing\n";
        return 0;
    }
    short f1;
    if(b==1||a!=1){
        f1=dfs2(a,b);
    }
    else{
        f1=dfs(a,b);
    }
    if(f1==1){
        cout<<"Masha\n";
    }
    else if(f1==3){
        cout<<"Missing\n";
    }
    else{
        cout<<"Stas\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}
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
bool dfs(int x,int y){
    if(ck(x,y))return 1;
    if(x==1&&ck(x+1,y))return 1;
    if((dfs(x+1,y)==0)||(dfs(x,y+1)==0))return 1;
    return 0;
}
bool dfs2(int x,int y){

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
    }
    else if(a==1){
        if(dfs(2,b)==0){
            cout<<"Masha\n";
        }
        else{
            if(dfs(2,b+1)==0){
                cout<<"Stas\n";
            }
            else{
                cout<<"Missing\n";
            }
        }
    }
    else if(dfs(a,b)){
        cout<<"Masha\n";
    }
    else{
        cout<<"Stas\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}
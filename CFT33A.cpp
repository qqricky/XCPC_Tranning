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
int t;
int vis[10][10];
bool dfs(int now,int val){
    if(now==7){
        if(val==(1<<6)-1){
            return 1;
        }
        return 0;
    }
    for(int j=0;j<6;j++){
        if(vis[now][j]){
            if(dfs(now+1,val|(1<<j)))return 1;
        }
    }
    return 0;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        string str;
        for(int i=1;i<=6;i++){
            cin>>str;
            for(char ch:str){
                if(ch=='h'){
                    vis[i][0]=1;
                }
                else if(ch=='a'){
                    vis[i][1]=1;
                }
                else if(ch=='r'){
                    vis[i][2]=1;
                }
                else if(ch=='b'){
                    vis[i][3]=1;
                }
                else if(ch=='i'){
                    vis[i][4]=1;
                }
                else if(ch=='n'){
                    vis[i][5]=1;
                }
            }
        }
        bool flag=dfs(1,0);
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}
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
bool vis[1070][1070];
int mid;
int ck(int x,int y,int len){
    int val=0;
    for(int i=y;i<=y+len-1;i++){
        if(vis[x][i])return -1;
        val+=abs(x-mid)+abs(i-mid);
    }
    return val;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    mid=(k+1)/2;
    for(int i=1;i<=n;i++){
        int num;
        int xx,yy;
        bool can=0;
        int fac=INF;
        cin>>num;
        for(int i=1;i<=k;i++){
            for(int j=1;j+num-1<=k;j++){
                int tmp=ck(i,j,num);
                if(tmp==-1)continue;
                else{
                    can=1;
                }
                if(tmp<fac){
                    fac=tmp;
                    xx=i,yy=j;
                }
            }
        }
        if(can){
            cout<<xx<<' '<<yy<<' '<<yy+num-1<<'\n';
            for(int i=yy;i<=yy+num-1;i++){
                vis[xx][i]=1;
            }
        }
        else{
            cout<<-1<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}
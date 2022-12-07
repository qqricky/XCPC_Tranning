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
int de[1050]={};
bool vi[1050][1050]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        de[x]++,de[y]++;
        vi[x][y]=vi[y][x]=1;
    }
    int res=INF;
    for(int q=1;q<=n*(n-1)/2-m;q++){
        int mm=-1;
        int xx,yy;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!vi[i][j]){
                    if(de[i]+de[j]>mm){
                        mm=de[i]+de[j];
                        xx=i;
                        yy=j;
                    }
                }
            }
        }
        vi[xx][yy]=vi[yy][xx]=1;
        de[xx]++;
        de[yy]++;
        // cout<<mm<<' '<<xx<<' '<<yy<<endl;
        res=min(res,mm);
    }
    cout<<res;
    cout.flush();
    system("pause");
    return 0;
}
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
int f1[2002];
int f2[2002];
int getfa1(int x)
{
    return x==f1[x] ? x : f1[x]=getfa1(f1[x]);
}
int getfa2(int x)
{
    return x==f2[x] ? x : f2[x]=getfa2(f2[x]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m1,m2;
    cin>>n>>m1>>m2;
    bool ff=0;
    for(int i=1;i<=n;i++){
        f1[i]=i;
        f2[i]=i;
    }
    int x,y;
    for(int i=1;i<=m1;i++){
        cin>>x>>y;
        int xx=getfa1(x);
        int yy=getfa1(y);
        if(xx==yy){
            ff=1;
        }
        if(xx<yy){
            f1[yy]=xx;
        }
        else{
            f1[xx]=yy;
        }
    }
    for(int i=1;i<=m2;i++){
        cin>>x>>y;
        int xx=getfa2(x);
        int yy=getfa2(y);
        if(xx==yy){
            ff=1;
        }
        if(xx<yy){
            f2[yy]=xx;
        }
        else{
            f2[xx]=yy;
        }
    }
    // if(ff){
    //     cout<<0;
    //     return 0;
    //     //system("pause");
    // }
    int ans=0;
    vector<int>ansx;
    vector<int>ansy;
    for(int i=1;i<=n;i++){
        int now=getfa1(i);
        int noww=getfa2(i);
        for(int j=1;j<=n;j++){
            int k=getfa1(j);
            int kk=getfa2(j);
            if(now!=k&&noww!=kk){
                ans++;
                ansx.push_back(i);
                ansy.push_back(j);
                if(now<k){
                    f1[k]=now;
                }
                else{
                    f1[now]=k;
                }
                if(noww<kk){
                    f2[kk]=noww;
                }
                else{
                    f2[noww]=kk;
                }
            }
        }
    }
    cout<<ans<<'\n';
    for(int i=0;i<ans;i++){
        cout<<ansx[i]<<' '<<ansy[i]<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}
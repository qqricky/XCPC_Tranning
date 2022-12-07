#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int v[150];
int f[150];
struct edge
{
    int s,t;
    double len;
}eg[5005];
double x[150];
double y[150];
bool cmp(edge a,edge b)
{
    return a.len<b.len;
}
int get(int x)
{
    return x==f[x] ? x : f[x]=get(f[x]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int tot=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        double diss;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                diss=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                if(diss>=10.0&&diss<=1000.0){
                    tot++;
                    eg[tot].s=j;
                    eg[tot].t=i;
                    eg[tot].len=diss;
                }
            }
        }
        sort(eg+1,eg+tot+1,cmp);
        int x1,x2;
        double ans=0;
        int cnt=0;
        for(int i=1;i<=tot;i++){
            x1=get(eg[i].s);
            x2=get(eg[i].t);
            if(x1!=x2){
                ans+=eg[i].len;
                f[x1]=x2;
                cnt++;
            }
        }
        if(cnt==-1)printf("%.1lf\n",ans*100);
        else printf("oh!\n");
    }
    //system("pause");
    return 0;
}
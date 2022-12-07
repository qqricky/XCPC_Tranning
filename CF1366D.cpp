#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 1e4
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int ans[2][N];
int pri[N];
int p[1070];
int cnt=0;
int ncnt=0;
bool vis[N];
void init() {
  for (int i = 2; i <= MAXN; ++i) {
    if (!vis[i]) {
      pri[++ncnt] = i;
    }
    for (int j = 1; j < ncnt; ++j) {
      if (1ll * i * pri[j] >= MAXN) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt=0;
        for(int j=1;j<=ncnt&&pri[j]*pri[j]<=a[i];j++){
            if(a[i]%pri[j]==0){
                p[++cnt]=pri[j];
                while(a[i]%pri[j]==0)a[i]/=pri[j];
            }
        }
        if(a[i]>1)p[++cnt]=a[i];
        if(cnt<2){
            ans[0][i]=-1;
            ans[1][i]=-1;
        }else{
            if(p[1]!=2){
                ans[0][i]=p[1];
                ans[1][i]=p[2];
            }else{
                int tmp=1;
                for(int j=2;j<=cnt;j++){
                    tmp*=p[j];
                }
                ans[0][i]=2;
                ans[1][i]=tmp;
            }
        }
    }
    for(int j=0;j<=1;j++){
        for(int i=1;i<=n;i++){
            cout<<ans[j][i]<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}
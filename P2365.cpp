#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int t[N];
int c[N];
int f[N];
int sumt[N];
int sumc[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    cin>>n>>s;
    sumc[0]=0;
    sumt[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        sumc[i]=sumc[i-1]+c[i];
        sumt[i]=sumt[i-1]+t[i];
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            f[i]=min(f[i],f[j]+sumt[i]*(sumc[i]-sumc[j])+(sumc[n]-sumc[j])*s);
        }
    }
    cout<<f[n]<<endl;
    //system("pause");
    return 0;
}
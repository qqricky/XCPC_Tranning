#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int a[N]={};
int v[10000070]={};
int f[N][21];
int l[N][21];
int divide(int x)
{
    int y=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            if(cnt&1)y*=i;
        }
    }
    if(x>1){
        y*=x;
    }
    return y;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ans=0;
    while(t--)
    {
        memset(f,0x3f,sizeof(f));
        int tmp;
        int n,k;
        ans=1;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            a[i]=divide(tmp);
            //cout<<a[i]<<endl;
        }
        for(int x=0;x<=k;x++){
            int j=1;
            int cnt=0;
            for(int i=1;i<=n;i++){
                v[a[i]]++;
                if(v[a[i]]>1)cnt++;
                while(cnt>x){
                    if(v[a[j]]>1)cnt--;
                    v[a[j]]--;
                    j++;
                    //cout<<j<<endl;
                }
                l[i][x]=j;
            }
            for(int i=1;i<=n;i++)v[a[i]]=0;
        }
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int x=0;x<=k;x++){
                for(int kk=0;kk<=x;kk++){
                    f[i][x]=min(f[i][x],f[l[i][x-kk]-1][kk]+1);
                }
            }
        }
        int ans=INF;
        for(int i=0;i<=k;i++)ans=min(ans,f[n][i]);
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}
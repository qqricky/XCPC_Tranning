#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[5005][5005];
int a[5005];
int pre[5005];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int pos=0;
        int tmp;
        memset(f,0x3f,sizeof(f));
        memset(pre,0,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp==a[pos])continue;
            a[++pos]=tmp;
            f[pos][pos]=0;
            f[pos-1][pos]=1;
        }
        map<int,int>mp;
        for(int i=1;i<=pos;i++){
            pre[i]=mp[a[i]];
            mp[a[i]]=i;
        }
        for(int len=3;len<=pos;len++){
            for(int i=1;i<=pos-len+1;i++){
                int j=i+len-1;
                if(a[i]!=a[j]){
                    f[i][j]=min(f[i][j],min(f[i+1][j]+1,f[i][j-1]+1));
                    int v=j;
                    while(v>i){
                        v=pre[v];
                        f[i][j]=min(f[i][j],f[v][j]+f[i][v-1]+1);
                    }
                }
                else{
                    f[i][j]=min(f[i][j],f[i+1][j-1]+1);
                    int val=j;
                    while(val!=i){
                        val=pre[val];
                        f[i][j]=min(f[i][j],f[val][j]+f[i][val-1]);
                    }
                }
                //cout<<i<<' '<<j<<'Q'<<f[i][j]<<endl;
            }
        }
        cout<<f[1][pos]<<endl;
    }
    //system("pause");
    return 0;
}
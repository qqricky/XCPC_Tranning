#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int mm[12][1<<11]={};
ll f[12][1<<11];
int check(int x,int k)
{
    int a[13]={};
    int pos=0;
    while(x){
        a[++pos]=x%2;
        x>>=1;
    }
    a[k+1]=1;
    pos=0;
    for(int i=1;i<=k+1;i++){
        if(a[i]==1){
            if((i-pos-1)&1){
                return 0;
            }
            else{
                pos=i;
            }
        }
    }
    return 1;
}
void pre_work(int x)
{
    for(int i=0;i<= (1<<x) -1;i++){
        if(check(i,x))mm[x][i]=1;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    for(int i=1;i<=11;i++)pre_work(i);
    cin>>n>>m;
    while(m+n)
    {
        memset(f,0,sizeof(f));
        f[0][0]=1;
        //ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j< (1<<m);j++){
                for(int k=0;k< (1<<m) ;k++){
                    if(((k&j)==0) && mm[m][k|j]==1){
                        // if(i==1&&j==0){
                        //     cout<<k<<endl;
                        //     // cout<<f[i-1][k]<<endl;
                        //     // cout<<f[n][0]<<endl;
                        // }
                        f[i][j]+=f[i-1][k];
                    }
                }
            }
        }
        cout<<f[n][0]<<endl;
        cin>>n>>m;
    }
    //system("pause");
    return 0;
}
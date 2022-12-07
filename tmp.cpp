#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e6;
const ll mod=1e9+7;
ll ans=0;
int pos;
int p[N+2]={};
bool check[N+5];
int n;
void init(){
    int t;
    check[1]=true;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            p[++p[0]]=i;
        }
        for(int j=1;j<=p[0];j++){
            t=i*p[j];
            if(t>n){
                break;
            }
            check[t]=true;
            if(i%p[j]==0){
                break;
            }
        }
    }
}
void dfs(int val,int x,ll ji)
{
    val=(val*10%mod+p[x])%mod;
    //cout<<val<<endl;
    //cout<<ji<<endl;
    ans=(ans+val)%mod;
    for(int i=x;i<=pos;i++){
        if(ji*p[i]<=n)dfs(val,i,ji*p[i]);
    }
}
    
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>n;
    init();
    k=n;
    for(int j=1;j<=k;j++){
    n=j;
        ans=0;
    pos=1;
    while(p[pos]<=n&&p[pos]!=0)pos++;
    pos--;
    for(int i=1;i<=pos;i++)dfs(0,i,p[i]);
        cout<<ans%mod<<',';
    }
    cout<<endl<<"/////////////////////////////////";
    //system("pause");
    return 0;
}
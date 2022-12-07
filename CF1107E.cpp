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
ll f[105][105][105];
int ne[105];
ll a[106];
ll v[106]={};
int num[2][106]={};
int n;
string str;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v[j]=max(v[j],v[j-i]+a[i]);
        }
    }
    int pos0=n+1,pos1=n+1;
    for(int i=n;i>=1;i--){
        f[i][i][1]=0;
        if(str[i]=='1'){
            ne[i]=pos1;
            pos1=i;
        }
        else{
            ne[i]=pos0;
            pos0=i;
        }
    }
    for(int i=1;i<=n;i++){
        num[1][i]=num[1][i-1];
        num[0][i]=num[0][i-1];
        if(str[i]=='1'){
            num[1][i]++;
        }
        else{
            num[0][i]++;
        }
    }
}
ll dfs(int l,int r,int pre){
    if(l>r)return 0;
    if(l==r)return v[pre+1];
    if(f[l][r][pre])return f[l][r][pre];
    ll ans=0;
    if(str[l+1]!=str[l]){
        ans=dfs(l+1,r,0)+v[pre+1];
    }
    for(int i=l+1;i<=r;i++){
        if(str[i]==str[l]){
            ans=max(ans,dfs(l+1,i-1,0)+dfs(i,r,pre+1));
        }
    }
    return f[l][r][pre]=ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>str;
    str=' '+str+' ';
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(f,0,sizeof(f));
    init();
    cout<<dfs(1,n,0);
    cout.flush();
    //system("pause");
    return 0;
}
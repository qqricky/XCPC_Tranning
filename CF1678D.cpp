#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
bool is[N]={};
int anss[N];
int acu[N];
int res[N];
int a[N];
int c[2*N];
int n,m;
int pre[N];
void add(int x,int val){
    for(int i=x;i<=n*m;i+=(i&-i)){
        c[i]+=val;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i;i-=(i&-i)){
        res+=c[i];
    }
    return res;
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
    while(t--){
        memset(is,0,sizeof(bool)*(m+5));
        memset(c,0,sizeof(int)*(n*m*2));
        cin>>n>>m;
        int ans=0;
        acu[0]=0;
        for(int i=0;i<n*m;i++){
            char ch;
            cin>>ch;
            acu[i+1]=acu[i];
            if(ch=='1'){
                ans+=(is[i%m]==0);
                is[i%m]=1;
                a[i]=1;
                acu[i+1]++;
            }
            else{
                a[i]=0;
            }
            anss[i+1]=ans;
        }
        res[0]=0;
        for(int i=1;i<=n*m;i++){
            res[i]=res[max(0,i-m)];
            if(acu[i]-acu[max(0,i-m)]>0){
                res[i]++;
            }
            cout<<res[i]+anss[i]<<' ';
        }
        cout<<'\n';
        // int pos=0;
        // int st=0;
        // while(st<n*m&&a[st]==0)st++;
        // for(int i=0;i<st;i++){
        //     cout<<anss[i]<<' ';
        // }
        // if(st!=n*m)cout<<anss[st]+1<<' ';
        // add(0,1);
        // for(int i=st+1;i<n*m;i++){
        //     int val=ask(i%m);
        //     if(a[i]){
        //         int len=i-pre[i];
        //     }
        //     cout<<anss[i]+val<<' ';
        // }
    }
    cout.flush();
    //system("pause");
    return 0;
}
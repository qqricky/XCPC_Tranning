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
int n;
string str;
ll add[20][1<<18]={};
const ll mod=998244353;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
bool vis[20]={};
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(str[i]=='?');
    }
    for(int len=1;len<=n;len++){
        for(int j=1;j+len-1<=n;j++){
            memset(vis,0,sizeof(vis));
            int l=j;
            int r=l+len-1;
            int cn=0;
            int cn1=0;
            bool flag=1;
            while(l<=r){
                cn1+=(str[l]=='?');
                if(r!=l)cn1+=(str[r]=='?');
                if(str[l]=='?'&&str[r]=='?'){
                    cn++;
                }
                else if(str[l]!='?'&&str[r]!='?'){
                    if(str[l]!=str[r]){
                        flag=0;
                        break;
                    }
                }
                else if(str[l]!='?'){
                    vis[str[l]-'a']=1;
                }
                else{
                    vis[str[r]-'a']=1;
                }
                l++,r--;
            }
            if(!flag)continue;
            int base=0;
            int num=0;
            for(int i=0;i<17;i++){
                if(vis[i]){
                    num++;
                    base+=(1<<i);
                }
            }
            for(int i=num;i<=17;i++){
                ll val=powq(i,cn)*powq(i,cnt-cn1)%mod;
                // if(val>0){
                //     cout<<i<<' '<<base<<' '<<val<<" from : "<<cn<<' '<<cnt-cn1<<endl;
                //     cout<<"to  :"<<j<<' '<<j+len-1<<endl;
                // }
                // if(i==2){
                //     cout<<base<<' '<<val<<" ... "<<cn<<' '<<cnt-cn1<<' '<<j<<' '<<j+len-1<<endl;
                // }
                add[i][base]=(add[i][base]+val)%mod;
            }
        }
    }
    for(int k=1;k<=17;k++){
        for(int j=0;j<17;j++){
            for(int i=0;i<(1<<18)-1;i++){
                if(!((i>>j)&1)){
                    add[k][i^(1<<j)]=(add[k][i^(1<<j)]+add[k][i])%mod;
                }
            }
        }
    }
    // for(int k=1;k<=17;k++){
    //     for(int i=1;i<(1<<17);i++){
    //         for(int j=0;j<17;j++){
    //             if((i>>j)&1){
    //                 int ii=i^(1<<j);
    //                 if(ii!=0){
    //                     add[k][i]=(add[k][i]+add[k][ii])%mod;
    //                 }
    //             }
    //         }
    //         容斥
    //         for(int j=0;j<17;j++){
    //             for(int jj=j+1;jj<17;jj++){
    //                 if(((i>>j)&1) && ((i>>jj)&1)){
    //                     int ii=i^(1<<j)^(1<<jj);
    //                     if(ii==0)continue;
    //                     add[k][i]=(add[k][i]-add[k][ii]+mod)%mod;
    //                 }
    //             }
    //         }
    //     }
    // }
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
    str=' '+str;
    solve();
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        memset(vis,0,sizeof(vis));
        int num=0;
        for(char ch:s){
            vis[ch-'a']=1;
            // cout<<ch-'a'<<' ';
        }
        int base=0;
        for(int i=0;i<17;i++){
            if(vis[i]){
                num++;
                base+=(1<<i);
            }
        }
        cout<<(add[num][base])%mod<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}
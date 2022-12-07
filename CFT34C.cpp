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
int f[2*N][20]={};
int g[2*N][20]={};
int tl[2*N];
int tr[2*N];
int pl[2*N];
int pr[2*N];
int a[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a[0]=-INF;
    a[n+1]=-INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //calc f
    int val=-INF;
    int pos=0;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            tl[i]=val;
            pl[i]=pos;
        }
        else{
            pos=i;
            val=a[i];
        }
        if(a[i]==-1||a[i+1]==-1||a[i+1]>=a[i]){
            f[i][0]=1;
        }
    }
    // for(int i=1;i+1<=n;i++){
    //     f[i][1]=(f[i][0]&&f[i+1][0]);
    // }
    // for(int i=2;i<=n;i++){
    //     if(a[i]==-1){
    //         if(a[i-1]>a[i+1])f[i-1][1]=0;
    //     }
    // }
    // for(int i=1;i+1<=n;i++){
    //     f[i][2]=(f[i][1]&&f[i+2][1]);
    // }
    //end calc f

    //clac g
    val=-INF;
    pos=n+1;
    for(int i=n;i>=1;i--){
        if(a[i]==-1){
            tr[i]=val;
            pr[i]=pos;
        }
        else{
            pos=i;
            val=a[i];
        }
        if(a[i]==-1||a[i-1]==-1||a[i-1]>=a[i]){
            g[i][0]=1;
        }
    }
    // for(int i=n;i-1>=1;i--){
    //     g[i][1]=(g[i][0]&&g[i-1][0]);
    // }
    // for(int i=n-1;i>=1;i--){
    //     if(a[i]==-1){
    //         if(a[i-1]<a[i+1])g[i+1][1]=0;
    //     }
    // }
    //  for(int i=1;i+1<=n;i++){
    //     g[i][2]=(g[i][1]&&g[i+2][1]);
    // }
    //end calc g

    for(int j=1;j<=17;j++){
        for(int i=1;i+(1<<j)<=n;i++){
            if(f[i][j-1]&&f[i+(1<<(j-1))][j-1]){
                if(a[i+(1<<(j-1))]==-1){
                    if(tl[i+(1<<(j-1))]<=tr[i+(1<<(j-1))]){
                        f[i][j]=1;
                    }
                    else if(pl[i+(1<<(j-1))]<i||pr[i+(1<<(j-1))]>i+(1<<j)){
                        f[i][j]=1;
                    }
                }
                else{
                    f[i][j]=1;
                }
            }
        }
    }
    for(int j=1;j<=17;j++){
        for(int i=n;i-(1<<j)>=1;i--){
            if(g[i][j-1]&&g[i-(1<<(j-1))][j-1]){
                if(a[i-(1<<(j-1))]==-1){
                    if(tl[i-(1<<(j-1))]>=tr[i-(1<<(j-1))]){
                        g[i][j]=1;
                    }
                    else if(pl[i-(1<<(j-1))]<i-(1<<j)||pr[i-(1<<(j-1))]>i){
                        g[i][j]=1;
                    }
                }
                else{
                    g[i][j]=1;
                }
            }
        }
    }
    bool flag=0;
    for(int len=3;len<=n;len++){
        bool fl=1;
        int i;
        for(i=1;i+len-1<=n;i+=len){
            int r=i+len-1;
            int l=i;
            if(f[l][0]==0||g[r][0]==0){
                fl=0;
                break;
            }
            for(int j=17;j>=0;j--){
                if(f[l][j]){
                    l+=(1<<j);
                }
                if(g[r][j]){
                    r-=(1<<j);
                }
            }
            if(l<r){
                fl=0;
                break;
            }
        }
        int l=i;
        int r=n;
        if(l==n+1)goto ed;
        if(r-l+1<3)fl=0;
        if(f[l][0]==0||g[r][0]==0){
            fl=0;
        }
        for(int j=17;j>=0;j--){
            if(f[l][j]){
                l+=(1<<j);
            }
            if(g[r][j]){
                r-=(1<<j);
            }
        }
        if(l<r){
            fl=0;
        }
        ed:;
        if(fl){
            //cout<<len<<endl;
            flag=1;
            break;
        }
    }
    if(flag)cout<<"Y";
    else cout<<"N";
    cout.flush();
    //system("pause");
    return 0;
}
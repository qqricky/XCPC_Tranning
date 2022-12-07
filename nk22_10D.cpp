#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int a[N],b[N];
int  f[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ncnt=0;
        memset(f,0,sizeof(int)*(n+2));
        a[0]=114514;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[i-1])b[++ncnt]=a[i];
        }
        for(int i=ncnt+1;i<=2*ncnt;i++){
            b[i]=b[i-ncnt];
        }
        bool flag=0;
        for(int i=1;i<=2*ncnt;i++){
            if(i>ncnt&&f[i-ncnt]>=f[i]){
                flag=1;
                break;
            }
            if((b[i+1]+1)%3==b[i]){
                f[i+1]++;
            }else if(b[i+1]==(b[i]+1)%3){
                f[i]--;
            }
            f[i+1]+=f[i];
        }
        if(flag){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}
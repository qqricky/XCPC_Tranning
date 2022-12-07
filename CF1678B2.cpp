#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int b[N];
int fr[N];
int to[N];
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            if(ch=='1')a[i]=1;
            else a[i]=0;
        }
        int cnt=1;
        int pre=a[1];
        a[n+1]=114514;
        int ans=0;
        int anss=0;
        int is=0;
        int last=0;
        int ncnt=0;
        for(int i=2;i<=n+1;i++){
            if(a[i]!=pre){
                anss++;
                if((cnt+is)&1){
                    is=1;
                    ans++;
                }
                else{
                    // if(is&&(cnt%2==1)&&last==2){
                    //     anss--;
                    // }
                    // else if(cnt==1){
                    //     anss--;
                    // }
                    is=0;
                }
                b[++ncnt]=cnt;
                cnt=1;
                pre=a[i];
            }
            else{
                cnt++;
            }
        }
        //cout<<anss<<'\n';
        if(ncnt==2&&n==2){
            cout<<ans<<' '<<1<<'\n';
            continue;
        }
        if(b[1]==1){
            if(b[2]==1){
                b[2]--;
                b[1]++;
            }
            else if(b[2]==2&&(b[3]%2==1)){
                b[2]--;
                b[1]++;
            }
            else{
                anss--;
                b[2]++;
            }
        }
        else{
            if(b[1]&1){
                b[2]--;
            }
        }
        for(int i=2;i<=ncnt;i++){
            if(b[i]==1&&b[i+1]%2==1){
                anss-=2;
                b[i+1]++;
                b[i+1]+=2;
            }
            else if(b[i]&1){
                b[i+1]--;
            }
            else if(b[i]==0){
                if(i==ncnt){
                    anss--;
                    break;
                }
                anss-=2;
                b[i+1]+=b[i-1];
            }
        }
        //if(b[ncnt]==1&&b[ncnt-1]!=0)anss--;
        cout<<ans<<' '<<anss<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}
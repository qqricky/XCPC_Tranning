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
int a[N];
int st[2][N];
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
        int num1=0;
        int num2;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]&1){a[i]=1;num1++;}
            else a[i]=0;
        }
        num2=n-num1;
        if(abs(num2-num1)>1){
            cout<<-1<<'\n';
            continue;
        }
        int cnt=0;
        int ans=INF;
        int now=1;
        if(num1==num2){
            for(int i=1;i<=n;i++){
                if(a[i]){
                    cnt+=abs(i-now);
                    now+=2;
                }
            }
            ans=0;
            now=2;
            for(int i=1;i<=n;i++){
                if(a[i]){
                    ans+=abs(i-now);
                    now+=2;
                }
            }
            cnt=min(ans,cnt);
        }
        else if(num1>num2){
            cnt=0;
            now=1;
            for(int i=1;i<=n;i++){
                if(a[i]){
                    cnt+=abs(i-now);
                    now+=2;
                }
            }
        }
        else{
            cnt=0;
            now=2;
            for(int i=1;i<=n;i++){
                if(a[i]){
                    cnt+=abs(i-now);
                    now+=2;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}
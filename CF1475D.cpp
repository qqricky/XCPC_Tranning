#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
ll a[N];
ll b[N];
ll c[N];
ll d[N];
int n,m;
ll sum;
int ck(int x)
{
    if(sum+b[x]>=m)return 1;
    else return 0;
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
    while(t--)
    {
        int n,m;
        int ans=INF;
        cin>>n>>m;
        b[0]=0;
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)cin>>d[i];
        int pos1=0;
        int pos2=0;
        for(int i=1;i<=n;i++){
            if(d[i]==1){
                a[++pos1]=c[i];
            }
            else{
                b[++pos2]=c[i];
            }
        }
        sort(a+1,a+pos1+1,greater<int>());
        sort(b+1,b+pos2+1,greater<int>());
        for(int i=1;i<=pos2;i++){
            b[i]+=b[i-1];
        }
        sum=0;
        a[0]=0;
        for(int i=0;i<=pos1;i++){
            sum+=a[i];
            if(sum>=m){
                ans=min(ans,i);
                break;
            }
            int k=lower_bound(b+1,b+pos2+1,m-sum)-b;
            if(k==pos2+1)continue;
            ans=min(ans,i+2*k);
        }
        if(ans==INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    //std::system("pause");
    return 0;
}
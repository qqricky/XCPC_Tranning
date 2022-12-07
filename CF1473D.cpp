#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int t;
int mis[N];
int mas[N];
int mit[N];
int mat[N];
int a[N];
int sum[N];
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
        cin>>n>>m;
        sum[0]=0;
        char ch;
        mis[0]=0;
        mas[0]=0;
        for(int i=1;i<=n;i++){
            cin>>ch;
            if(ch=='+')a[i]=1;
            else a[i]=-1;
            sum[i]=sum[i-1]+a[i];
            mis[i]=min(mis[i-1],sum[i]);
            mas[i]=max(mas[i-1],sum[i]);
        }
        int lsum=0;
        int lmin=0;
        int lmax=0;
        for(int i=n;i>=1;i--){
            lsum-=a[i];
            lmin=min(lmin,lsum);
            lmax=max(lmax,lsum);
            mat[i]=lmax-lsum;
            mit[i]=lmin-lsum;
        }
        int x,y;
        mat[n+1]=0;
        mit[n+1]=0;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            int h=max(mas[x-1],sum[x-1]+mat[y+1]);
            int l=min(mis[x-1],sum[x-1]+mit[y+1]);
            cout<<h-l+1<<endl;
        }
    }
    //system("pause");
    return 0;
}
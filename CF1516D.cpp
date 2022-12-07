#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int f[N][30];
int go[N];
int gcd(int a,int b)
{
    return b? gcd(b,a%b) : a;
}
map<int,int>mp;
int pos=0;
void del(int x)
{
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0){
                mp[i]--;
                x/=i;
            }
        }
    }
    if(x>1)mp[x]--;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int l1,r;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1;
    int tmp=a[1];
    for(int i=2;i*i<=tmp;i++){
        while(tmp%i==0){
            tmp/=i;
            mp[i]++;
        }
    }
    if(tmp>1)mp[tmp]++;
    for(int i=1;i<=n;i++)f[i][1]=n;
    for(int i=2;i<=n;i++){
        tmp=a[i];
        for(int j=2;j*j<=tmp;j++){
            if(tmp%j==0){
                while(mp[j]){
                    f[l][1]=i-1;
                    //cout<<l<<endl;
                    del(a[l]);
                    l++;
                }
                while(tmp%j==0){
                    mp[j]++;
                    tmp/=j;
                }
            }
        }
        if(tmp>1){
                while(mp[tmp]){
                    f[l][1]=i-1;
                    del(a[l]);
                    l++;
                }
                mp[tmp]++;
            }
    }
    f[n][1]=n;
    for(int i=1;i<=20;i++)f[n+1][i]=n;
    for(int i=2;i<=20;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]+1][i-1];
            //cout<<j<<"   "<<(1<<(i-1))<<"QQ"<<f[j][i]<<endl;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l1>>r;
        int cnt=0;
        int pos=l1;
        for(int j=20;j>=1;j--){
            if(f[pos][j]<r){
                //cout<<f[pos][j]<<'Q'<<j<<endl;
                cnt+=1ll<<(j-1);
                pos=f[pos][j]+1;
            }
        }
        cout<<cnt+1<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}
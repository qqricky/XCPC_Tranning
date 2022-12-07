#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
ll f[N];
ll sumt[N];
ll sumc[N];
ll x[N];
ll y[N];
int ncnt=0;
int query(ll k)
{
    //cout<<k<<endl;
    //cout<<"ncnt : "<<ncnt<<endl;
    if(ncnt==0)return 0;
    if(y[1]-y[0]>=k*(x[1]-x[0]))return 0;
    if(y[ncnt]-y[ncnt-1]<=k*(x[ncnt]-x[ncnt-1]))return ncnt;
    int mid;
    int l=0;
    int r=ncnt;
    //cout<<l<<"      "<<r<<endl;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(y[mid+1]-y[mid]==k*(x[mid+1]-x[mid]))return mid;
        if(y[mid+1]-y[mid]<k*(x[mid+1]-x[mid]))l=mid+1;
        else r=mid;
        //cout<<mid<<endl;
    }
    return l;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,s;
    cin>>n>>s;
    sumc[0]=0;
    sumt[0]=0;
    for(int i=1;i<=n;i++){
        int t,c;
        cin>>t>>c;
        sumc[i]=sumc[i-1]+c;
        sumt[i]=sumt[i-1]+t;
    }
    x[ncnt]=0;
    y[ncnt]=0;
    f[0]=0;
    for(int i=1;i<=n;i++){
        int kk=query(s+sumt[i]);
        //cout<<kk<<endl;
        f[i]=y[kk]+sumt[i]*(sumc[i]-x[kk])+(sumc[n]-x[kk])*s;
        if(ncnt>0){
            //cout<<(f[i]-y[ncnt])*(x[ncnt]-x[ncnt-1])<<"  :  "<<(y[ncnt]-y[ncnt-1])*(sumc[i]-x[ncnt])<<endl;
            while(ncnt>0&&((f[i]-y[ncnt])*(x[ncnt]-x[ncnt-1])<=(y[ncnt]-y[ncnt-1])*(sumc[i]-x[ncnt]))){
                ncnt--;
            }
            x[++ncnt]=sumc[i];
            y[ncnt]=f[i];
        }
        else{
            x[++ncnt]=sumc[i];
            y[ncnt]=f[i];
        }
    }
    cout<<f[n]<<endl;
    //system("pause");
    return 0;
}
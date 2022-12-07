#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
string s[N];
// struct mm
// {
//     int mi;
//     int i;
//     int ma;
// }mi[N];
// bool cmp(mm x,mm y)
// {
//     return x.mi<y.mi;
// }
// bool operator <(const mm &a,const int &b){
//     return a.mi<b;
// }
// bool operator <(const int&a,const mm & b){
//     return a<b.mi;
// }
ll ma[N]={};
ll mi[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    ll tmp;
    memset(mi,0x3f,sizeof(mi));
    memset(ma,0,sizeof(ma));
    for(int i=1;i<=n;i++){
        cin>>k;
        mi[i]=INF;
        for(int j=1;j<=k;j++){
            cin>>tmp;
            mi[i]=min(mi[i],tmp);
            if(tmp>mi[i]){ma[i]=INF;mi[i]=-1;}
            ma[i]=max(ma[i],tmp);
        }
    }
    std::sort(ma+1,ma+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        // if(v[mi[i].i]){
        //     ans+=n;
        //     // int g=lower_bound(mi+1,mi+n+1,mi[i].ma)-mi;
        //     // int kk=n-g+1;
        //     // cout<<ma[i]<<endl;
        //     // for(int j=g;j<=n;j++)cout<<mi[i].mi<<' ';
        //     // ans+=kk;
        //     continue;
        // }
        int g=upper_bound(ma+1,ma+n+1,mi[i])-ma;
        //cout<<mi[i]<<endl;
        //cout<<mi[i].mi<<"////";
        //cout<<mi[i].ma<<"////";
        //cout<<i<<'Q'<<n-g+1<<endl;
        ans+=n-g+1;
    }
    cout<<ans<<endl;
    //std::system("pause");
    return 0;
}
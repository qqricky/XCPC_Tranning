#include <bits/stdc++.h>
#define ll long long
const int N=2e5+10; 
using namespace std;
int n,k;
int a[N];
int sum[N];
int mii[N];
int ck(int val)
{
    int pos=0;
    sum[0]=0;
    mii[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=val)sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
        mii[i]=min(mii[i-1],sum[i]);
        if(i>=k){
            if(i>k){
                if(sum[i]-mii[i-k]>0)return 1;
            }
            else{
                if(sum[i]>0)return 1;
            }
        }
    }
    return 0;

}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1;
    int r=n;
    while(l+1<r)
    {
        int mid=(l+r)>>1;
        if(ck(mid))l=mid;
        else r=mid;
    }
    if(ck(r))cout<<r;
    else cout<<l;
    cout<<endl;
    //system("pause");
    return 0;
}
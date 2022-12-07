#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
std::ostream& operator<<(std::ostream& os, __int128 t) {
    if (t==0) return os << "0";
    if (t<0) {
        os<<"-";
        t=-t;
    }
    int a[50],ai=0;
    memset(a,0,sizeof a);
    while (t!=0){
        a[ai++]=t%10;
        t/=10;
    }
    for (int i=1;i<=ai;i++) os<<abs(a[ai-i]);
    return os<<"";
}
 
void print(__int128 x)
{
    if (x>9) print(x/10);
    putchar('0'+x%10);
}
ll n,x,m,k;
ll rr[10000007];
void solve(){
    ll s = 0,sr = 0,st=0,res = n;
    int l=-1,r = n/k+1;
    while(r-l>1){
        int mid = l+r>>1;
        if((n-k*mid+m-1)/m<k) r = mid;
        else l = mid;
    }
    st = r;
    sr = n-st*k;
    sr+=k;
    ll ans = (sr+n)*r/2;
    n -= st*k;
    for(int i = m;i >= 1;--i){
        rr[i] = n/i;
        n-=n/i;
    }
    sort(rr+1,rr+1+m);
    ll sum = 0;
    for(int i = 1;i <= m;++i){
        //cout << rr[i] << ' ';
        sum += rr[i];
        ans += st*rr[i]; 
        ans += sum;
    }
    if(ans>=x){
        printf("YES %d",ans);
        //print(ans);
        cout << endl;
    } else printf("NO\n");
}
int main(){
    while(~scanf("%d%d%d%d",&n,&m,&k,&x)) solve();
    return 0;
}
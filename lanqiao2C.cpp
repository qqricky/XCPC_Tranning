#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int a[N];
int b[N];
ll sum[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int mi=INF;
    int ed=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sum[a[i]+1]++;
        ed=min(ed,a[i]+b[i]);
    }
    int ans=mi+1;
    while(1){
        sum[ans]+=sum[ans-1];
        if(m<sum[ans]||ans>ed){
            ans--;
            break;
        }
        m-=sum[ans];
        ans++;
    }
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int d[N];
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
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            d[a[i]%m]++;
        }
        if(m==1){
            cout<<1<<endl;
            continue;
        }
        int cnt=0;
        if(d[0])cnt++;
        for(int i=1;i<=m/2;i++){
            int k=m-i;
            if(d[i]==d[k]&&d[k]==0)continue;
            if(i==k){
                cnt++;
                continue;
            }
            if(d[i]>d[k]){
                cnt+=d[i]-d[k];
            }
            else if(d[k]>d[i]){
                cnt+=d[k]-d[i];
            }
            else{
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}
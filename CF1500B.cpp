#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int a[N];
int d[N+5];
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
        memset(d,0,sizeof(d));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]){
                d[max(1,i-a[i]+1)]++;
                d[i+1]--;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=d[i];
            if(sum>0)cout<<1<<' ';
            else cout<<0<<' ';
        }
        cout<<"\n";
    }
    //system("pause");
    return 0;
}
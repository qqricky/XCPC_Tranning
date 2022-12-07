#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int pos[N];
double pb[N];
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
        for(int i=1;i<=n;i++)cin>>a[i];
        int poss=n;
        a[0]=114514;
        while(a[poss]==poss)poss--;
        double ans=1;
        if(poss==0){
            poss=n+1;
            ans=0;
        }
        for(int i=1;i<=m;i++){
            cin>>pos[i]>>pb[i];
            if(pos[i]>=poss){
                ans*=(1-pb[i]);
            }
        }
        cout<<fixed<<setprecision(6)<<(1-ans)<<endl;
    }
    //system("pause");
    return 0;
}
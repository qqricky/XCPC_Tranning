#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N]={};
int divide(int x)
{
    int y=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            if(cnt&1)y*=i;
        }
    }
    if(x>1){
        y*=x;
    }
    return y;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ans=0;
    while(t--)
    {
        int tmp;
        int n,k;
        ans=1;
        cin>>n>>k;
        cin>>tmp;
        int g=divide(tmp);
        a[1]=g;
        set<int>s;
        s.insert(g);
        for(int i=2;i<=n;i++){
            cin>>tmp;
            g=divide(tmp);
            if(s.count(g)>0){
                ans++;
                s.clear();
                s.insert(g);
            }
            else{
                s.insert(g);
            }
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}
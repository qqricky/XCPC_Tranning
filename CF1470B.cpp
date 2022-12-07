#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5;
//int a[N];
//int num[N];
int divide(int n)
{
    int m=0;
    int p[102];
    int c[102];
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            p[++m]=i,c[m]=0;
            while(n%i==0)n/=i,c[m]++;
        }
    }
    if(n>1)p[++m]=n,c[m]=1;
    int k=1;
    for(int i=1;i<=m;i++)
        if(c[i]&1)k*=p[i];
    return k;
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
    while(t--)
    {
        int n;
        cin>>n;
        int tmp;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            mp[divide(tmp)]++;
        }
        auto it=mp.begin();
        int ans1=0;
        int ans2=0;
        while(it!=mp.end()){
            //cout<<it->first<<endl;
            ans1=max(ans1,it->second);
            if((it->first)!=1)
            {
            if((it->second) & 1){
                ans2=max(ans2,it->second);
            }
            else{
                mp[1]+=(it->second);
            }
            }
            it++;
        }
        ans2=max(ans2,mp[1]);
        mp.clear();
        int q;
        cin>>q;
        for(int i=1;i<=q;i++){
            ll w;
            cin>>w;
            if(w)cout<<ans2<<"\n";
            else cout<<ans1<<"\n";
        }
    }
    //system("pause");
}
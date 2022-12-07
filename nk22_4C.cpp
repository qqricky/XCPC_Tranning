#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
ll sum=0;
int num[N];
int anss=0;
vector<pair<int,int> >ans;
vector<pair<int,int> >res;
int ck(int lev,int n){
    for(int i=1;i<=n;i++){
        num[i]=(n-i+1);
    }
    ll acu=sum/lev;
    ans.clear();
    for(int i=1;i<=lev;i++){
        int now=0;
        for(int j=n;j>=1;j--){
            if(num[j]&&now+j<=acu){
                ans.push_back(make_pair(now,i-1));
                ans.push_back(make_pair(now+j,i));
                num[j]--;
                now+=j;
                j++;
            }
        }
        if(now<acu){
            return 0;
        }
    }
    return acu*2+lev*2;
}
int solve(int n){
    sum=0;
    anss=INF;
    for(int i=1;i<=n;i++){
        sum+=i*(n-i+1);
    }
    int mx=sum/n;
    int lev=1;
    for(int i=mx;i>=1;i--){
        if(sum%i)continue;
        int now=ck(i,n);
        if(now<anss){
            anss=now;
            res=ans;
        }
    }
    return anss;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        res.clear();
        int k=solve(n);
        cout<<k<<'\n';
        for(int i=0;i<res.size();i+=2){
            cout<<res[i].first<<' '<<res[i].second<<' ';
            cout<<res[i+1].first<<' '<<res[i+1].second<<'\n';
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}
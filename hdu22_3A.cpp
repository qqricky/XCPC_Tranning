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
struct node
{
    int l,r;
}nd[N];
bool cmp(node &a,node &b){
    return a.l<b.l;
}
priority_queue<int>s;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int ts=1;ts<=t;ts++){
        while(s.size())s.pop();
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>nd[i].l>>nd[i].r;
        }
        sort(nd+1,nd+n+1,cmp);
        ll ans=0;
        int mx=0;
        int now=1;
        while(now<=n){
            if(s.size()==0){
                s.push(-nd[now].r);
                mx=nd[now].r;
            }else if(nd[now].l<=mx){
                s.push(-nd[now].r);
                mx=min(mx,nd[now].r);
            }else{
                int num=s.size();
                int cnt=(num/k);
                cnt*=k;
                if(cnt){
                    ans+=num/k;
                    // cout<<s.size()<<' '<<cnt<<endl;
                    for(int j=1;j<=cnt;j++){
                        s.pop();
                    }
                    if(!s.empty()){
                        mx=-s.top();
                    }
                    now--;
                }else{
                    ans++;
                    while(s.size())s.pop();
                    now--;
                }
            }
            now++;
        }
        if(s.size()){
            int num=s.size();
            ans+=num/k;
            if(num%k){
                ans++;
            }
        }
        cout<<ans;
        if(ts!=t)cout<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}
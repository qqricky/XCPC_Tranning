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
    string name,col;
    ll val;
    bool operator<(const node &b)const{
        return val<b.val;
    }
}nd[N];
string bo[10];
struct nod
{
    ll val;
    ll pct;
    string name;
}sel[1070];
map<string,ll>mp1;
map<string,ll>mp2;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cout.tie(0);
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        for(int i=1;i<=n;i++){
            std::cin>>nd[i].name>>nd[i].col>>nd[i].val;
        }
        for(int i=1;i<=30;i++){
            sel[i].val=0;
            sel[i].pct=0;
        }
        string power;
        for(int i=1;i<=5;i++){
            std::cin>>bo[i];
            sel[2*i].name=bo[i];
            sel[2*i-1].name=bo[i];
        }
        std::cin>>power;
        priority_queue<pair<ll,string> >a;
        priority_queue<pair<ll,string> >b;
        mp1.clear();mp2.clear();
        for(int i=1;i<=n;i++){
            bool can=1;
            for(int j=1;j<=5;j++){
                if(nd[i].name==bo[j]){
                    can=0;
                    if(nd[i].col==power){
                        sel[j*2].val=max(sel[j*2].val,nd[i].val);
                        sel[j*2].pct=30;
                    }else{
                        sel[j*2-1].val=max(sel[j*2-1].val,nd[i].val);
                        sel[j*2-1].pct=10;
                    }
                }
            }
            if(can){
                if(nd[i].col==power){
                    mp1[nd[i].name]=max(mp1[nd[i].name],nd[i].val);
                }else{
                    mp2[nd[i].name]=max(mp2[nd[i].name],nd[i].val);
                }
            }
        }
        for(auto pr:mp1){
            a.push(make_pair(pr.second,pr.first));
        }
        for(auto pr:mp2){
            b.push(make_pair(pr.second,pr.first));
        }
        int now=10;
        for(int j=1;j<=5;j++){
            if(a.empty())break;
            sel[++now].val=a.top().first;
            sel[now].name=a.top().second;
            a.pop();
            sel[now].pct=20;
        }
        for(int j=1;j<=5;j++){
            if(b.empty())break;
            sel[++now].val=b.top().first;
            sel[now].name=b.top().second;
            b.pop();
            sel[now].pct=0;
        }
        ll ans=0;
        for(int y=1;y<=now;y++){
            for(int u=y+1;u<=now;u++){
                for(int i=u+1;i<=now;i++){
                    for(int o=i+1;o<=now;o++){
                        for(int p=o+1;p<=now;p++){
                            set<string>s;
                            s.insert(sel[y].name);s.insert(sel[u].name);s.insert(sel[i].name);s.insert(sel[o].name);s.insert(sel[p].name);
                            if(s.size()!=5)continue;
                            ll res=sel[y].val+sel[u].val+sel[i].val+sel[o].val+sel[p].val;
                            ll sum=sel[y].pct+sel[u].pct+sel[i].pct+sel[o].pct+sel[p].pct;
                            ll tmp=res;
                            res+=sum*res/100;
                            // res+=sel[y].pct*tmp/100+sel[u].pct*tmp/100+sel[i].pct*tmp/100+sel[o].pct*res/100+sel[p].pct*res/100;
                            ans=max(ans,res);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}
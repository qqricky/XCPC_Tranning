#include <bits/stdc++.h>
#define ll unsigned long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll n,x;
int ans=INF;
unordered_map<ll,int>mp;
void dfs(ll now,int step){
    set<int>s;
    ll tmp=now;
    int len=0;
    while(tmp){
        s.insert(tmp%10);
        tmp/=10;
        len++;
    }
    if(len>=n){
        ans=min(ans,step);
    }
    for(auto it=s.rbegin();it!=s.rend();it++){
        int x=*it;

    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    queue<pair<ll,int> >q;
    q.push(make_pair(x,0));
    while(q.size()){
        auto pr=q.front();
        q.pop();
        ll now=pr.first;
        int step=pr.second;
        ll tmp=now;
        int len=0;
        set<int>s;
        while(tmp){
            s.insert(tmp%10);
            tmp/=10;
            len++;
        }
        for(int x:s){
            if(x>1){
                ll ne=x*now;
                if(mp[ne]==0){
                    mp[ne]=step+1;
                    q.push(make_pair(ne,step+1));
                }
                else{
                    mp[ne]=min(mp[ne],step+1);
                }
            }
        }
        if(len>=n){
            ans=step;
            goto ed;
        }
    }
    ed:;
    cout<<(ans==INF ? -1 : ans);
    cout.flush();
    // system("pause");
    return 0;
}
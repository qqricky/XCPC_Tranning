#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
string s;
struct Node{
    ll sum, len;
    int fail;
    bool st;
    int ch[26]={};
    Node() {}
}pam[N];
ull fac[N];
ull hs[N];
const ull base=131;
int ans[N]={};
int ind[N]={};
ull gethash(int l, int r){
    return hs[r] - hs[l - 1] * fac[r - l + 1];
}
int last;
int ncnt;
int New(int len) {
    ncnt++;
    pam[ncnt].len = len;
    pam[ncnt].st=0;
    pam[ncnt].sum=0;
    for(int j=0;j<=25;j++){
        pam[ncnt].ch[j]=0;
    }
    return ncnt;
}
int getfail(int pre, int now) {
    while (s[now - pam[pre].len - 1] != s[now])pre=pam[pre].fail;
    return pre;
}
void dfs(int u)
{
    map<int,int>mp;
    mp[pam[u].len]=1;
    //cout<<pam[u].len<<' ';
    while(u!=1){
        u=pam[u].fail;
        mp[pam[u].len]++;
        //cout<<pam[u].len<<' ';
    }
    //cout<<endl;
    for(auto i=mp.begin();i!=mp.end();i++){
        if(mp[(i->first+1)/2]>0){
            ans[i->first]++;
        }
    }
}
inline bool judge(int ed,int len)
{
    if(len==1)return 1;
    int half=(len+1)/2;
    if(gethash(ed - len + 1, ed - len + half) == gethash(ed - half + 1, ed))return 1;
    return 0;
}
void build() {
    ncnt = 1;
    pam[0].len = 0; pam[1].len = -1;
    pam[0].fail = 1; pam[1].fail = 0;
    for(int i=0;i<=25;i++)pam[0].ch[i]=pam[1].ch[i]=0;
    last = 0;
    for (int i=1;i<s.length();i++) {
        int cur = getfail(last, i);
        if (pam[cur].ch[s[i] - 'a'] == 0) {
            int now = New(pam[cur].len + 2);
            pam[now].fail = pam[getfail(pam[cur].fail, i)].ch[s[i] - 'a'];
            pam[cur].ch[s[i] - 'a'] = now;
            if(judge(i,pam[now].len))pam[now].st=1;
            else pam[now].st=0;
        }
        last = pam[cur].ch[s[i] - 'a'];
        //cout<<last<<endl;
        //cout<<pam[last].len<<endl;
        pam[last].sum++;
    }
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for(int i = 1;i <= 300005; ++i) fac[i] = fac[i - 1] * base;
    while(cin>>s){
        int n=s.length();
        s=' '+s;
        hs[0]=0;
        memset(ans,0,sizeof(int)*(n+1));
        for(int i = 1;i <= n; ++i) hs[i] = hs[i-1] * base + s[i];
        build();
        //cout<<ncnt<<endl;
        for(int i=ncnt;i>=2;i--){
            pam[pam[i].fail].sum+=pam[i].sum;
            if(pam[i].st){
                ans[pam[i].len]+=pam[i].sum;
            }
        }
        for(int i=1;i<n;i++)cout<<ans[i]<<' ';
        cout<<ans[n]<<"\n";
        cout.flush();
    }
    //system("pause");
    return 0;
}
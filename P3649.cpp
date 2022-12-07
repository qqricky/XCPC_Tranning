#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
string s;
struct Node{
    int sum, len;
    int fail;
    int ch[26]={};
    Node() {}
}pam[N];
int ind[N]={};
int last;
int ncnt;
int New(int len) {
    ncnt++;
    pam[ncnt].len = len;
    pam[ncnt].fail = 0;
    for(int j=0;j<=25;j++){
        pam[ncnt].ch[j]=0;
    }
    return ncnt;
}
int getfail(int pre, int now) {
    while (s[now - pam[pre].len - 1] != s[now])pre=pam[pre].fail;
    return pre;
}

void build() {
    ncnt = 1;
    pam[0].len = 0; pam[1].len = -1;
    pam[0].fail = 1; pam[1].fail = 0;
    last = 0;
    for (int i=0;i<s.length();i++) {
        int cur = getfail(last, i);
        if (pam[cur].ch[s[i] - 'a'] == 0) {
            int now = New(pam[cur].len + 2);
            pam[now].fail = pam[getfail(pam[cur].fail, i)].ch[s[i] - 'a'];
            pam[cur].ch[s[i] - 'a'] = now;
        }
        last = pam[cur].ch[s[i] - 'a'];
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
    cin>>s;
    build();
    queue<int>q;
    for(int i=2;i<=ncnt;i++)if(!ind[i])q.push(i);
    ll ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        pam[pam[u].fail].sum+=pam[u].sum;
        ind[pam[u].fail]--;
        if(ind[pam[u].fail]==0){
            q.push(pam[u].fail);
            ans=max(ans,(ll)pam[u].len*pam[u].sum);
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
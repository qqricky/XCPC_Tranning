#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10;
using namespace std;
string s;
struct Node{
    int sum, len;
    int fail;
    int trans;
    int cost;
    int ch[26]={};
    Node() {}
}pam[N];
int last;
int ncnt;
int ans;
int go[]={0,0,'C'-'A','G'-'A','T'-'A'};
int New(int len) {
    ncnt++;
    pam[ncnt].len = len;
    pam[ncnt].fail = 0;
    pam[ncnt].trans=0;
    pam[ncnt].cost=len;
    pam[ncnt].ch[0]=pam[ncnt].ch['C'-'A']=pam[ncnt].ch['G'-'A']=pam[ncnt].ch['T'-'A']=0;
    pam[1].ch[0]=pam[1].ch['C'-'A']=pam[1].ch['G'-'A']=pam[1].ch['T'-'A']=0;
    return ncnt;
}
inline int getfail(int pre, int now) {
    while (s[now - pam[pre].len - 1] != s[now])pre=pam[pre].fail;
    return pre;
}
inline int getfail2(int pre,int now,int len){
    while (pam[pre].len>len/2 || s[now - pam[pre].len - 1] != s[now])pre=pam[pre].fail;
    return pre;
}
void build() {
    ncnt = 1;
    pam[0].len = 0; pam[1].len = -1;
    pam[0].fail = 1; pam[1].fail = 0;
    pam[0].ch[0]=pam[0].ch['C'-'A']=pam[0].ch['G'-'A']=pam[0].ch['T'-'A']=0;
    pam[1].ch[0]=pam[1].ch['C'-'A']=pam[1].ch['G'-'A']=pam[1].ch['T'-'A']=0;
    // pam[0].trans = pam[0].fail;
    // pam[1].trans = pam[1].fail;
    last = 0;
    for (int i=0;i<s.length();i++) {
        int cur = getfail(last, i);
        if (pam[cur].ch[s[i] - 'A'] == 0) {
            int now = New(pam[cur].len + 2);
            //if(pam[now].len==1)pam[now].cost=1;
            int tt=getfail(pam[cur].fail, i);
            pam[now].fail = pam[tt].ch[s[i] - 'A'];
            if(pam[now].len<=2)pam[now].trans=pam[now].fail;
            else{
                int to=pam[cur].trans;
                while(s[i-pam[to].len-1]!=s[i]||((pam[to].len+2)<<1)>pam[now].len)to=pam[to].fail;
                pam[now].trans=pam[to].ch[s[i]-'A'];
            }
            pam[cur].ch[s[i] - 'A'] = now;
        }
        last = pam[cur].ch[s[i] - 'A'];
        // if(pam[last].trans!=0&&pam[last].trans!=1)
        //     pam[last].cost=pam[pam[last].trans].cost+(pam[last].len-2*pam[pam[last].trans].len)/2+1;
        // else if(pam[last].len%2==0)
        //     pam[last].cost=pam[last].len/2+1;
        // pam[last].cost=min(pam[last].cost,pam[pam[last].fail].cost+pam[last].len-pam[pam[last].fail].len);                        
        // ans=max(ans,pam[last].len-pam[last].cost);
    }
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
        cin>>s;
        ans=0;
        build();
        pam[0].cost=0;
        pam[1].cost=0;
        queue<int>q;
        for(int i=1;i<=4;i++){
            if(pam[0].ch[go[i]]!=0){
                q.push(pam[0].ch[go[i]]);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            //if(pam[u].trans!=0&&pam[u].len>2)
            pam[u].cost=min(pam[u].cost,pam[pam[u].trans].cost+(pam[u].len-2*pam[pam[u].trans].len)/2+1);
            for(int i=1;i<=4;i++){
                if(pam[u].ch[go[i]]!=0){
                    pam[pam[u].ch[go[i]]].cost=min(pam[pam[u].ch[go[i]]].cost,pam[u].cost+1);
                    q.push(pam[u].ch[go[i]]);
                }
            }
            //cout<<pam[u].len-pam[u].cost<<"  ww  "<<pam[u].len<<endl;
            ans=max(ans,pam[u].len-pam[u].cost);
        }
        cout<<s.length()-ans<<"\n";
    }
    //system("pause");
    return 0;
}
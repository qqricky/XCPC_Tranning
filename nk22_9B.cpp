#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=4e5+10;
using namespace std;
string s;
struct Node{
    int sum, len;
    int fail;
    int ch[41]={};
    Node() {}
}pam[N];
int ind[N]={};
int last;
int ncnt;
int num[41]={};
int pos[10]={};
int New(int len) {
    ncnt++;
    pam[ncnt].len = len;
    pam[ncnt].fail = 0;
    pam[ncnt].sum=0;
    for(int j=0;j<=40;j++){
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
        if (pam[cur].ch[s[i] - 'a'+12] == 0) {
            // cout<<i<<' ';
            int now = New(pam[cur].len + 2);//新建节点
            pam[now].fail = pam[getfail(pam[cur].fail, i)].ch[s[i] - 'a'+12];//找到最长回文后缀
            ind[pam[now].fail]++;
            pam[cur].ch[s[i] - 'a'+12] = now;//父子相认
            // cout<<pam[now].len<<endl;
        }
        last = pam[cur].ch[s[i] - 'a'+12];//更新last
        if(i<pos[1]){
            pam[last].sum|=(1<<0);
        }else if(i<pos[2]){
            pam[last].sum|=(1<<1);
        }else if(i<pos[3]){
            pam[last].sum|=(1<<2);
        }else if(i<pos[4]){
            pam[last].sum|=(1<<3);
        }else{
            pam[last].sum|=(1<<4);
        }
        // cout<<i<<' '<<pam[last].len<<' '<<pam[last].sum<<endl;
    }
}
int cnt[41]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    string str;
    cin>>k;
    cin>>s;pos[1]=s.length();
    for(int i=2;i<=k;i++){
        cin>>str;
        if(i==2){
            s=s+"_`"+str;
            pos[2]=s.length();
        }
        else if(i==3){
            s=s+'X'+'Y'+str;
            pos[3]=s.length();
        }
        else if(i==4){
            s=s+'Z'+'['+str;
            pos[4]=s.length();
        }
        else{
            s=s+"]^"+str;
            pos[5]=s.length();
        }
    }
    // s=' '+s;
    build();
    queue<int>q;
    ll ans=0;
    for(int i=2;i<=ncnt;i++)if(!ind[i]){
        q.push(i);
        // if(pam[i].sum==((1<<k)-1))ans++;
    }
    while(!q.empty())
    {
        int u=q.front();
        if(u!=0&&u!=1&&pam[u].sum==(1<<k)-1)ans++;
        q.pop();
        pam[pam[u].fail].sum|=pam[u].sum;
        ind[pam[u].fail]--;
        if(ind[pam[u].fail]==0){
            q.push(pam[u].fail);
            // if(pam[u].sum==(1<<k)-1){
            //     ans++;
            // }
        }
    }
    cout<<ans<<'\n';
    // cout.flush();
    // system("pause");
    return 0;
}
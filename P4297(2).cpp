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
    int ch[26]={};
    Node() {}
}pam[N];
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
    // pam[0].trans = pam[0].fail;
    // pam[1].trans = pam[1].fail;
    last = 0;
    for (int i=0;i<s.length();i++) {
        int cur = getfail(last, i);
        if (pam[cur].ch[s[i] - 'a'] == 0) {
            int now = New(pam[cur].len + 2);
            int tt=getfail(pam[cur].fail, i);
            pam[now].fail = pam[tt].ch[s[i] - 'a'];
            if(pam[now].len<=2)pam[now].trans=pam[now].fail;
            else{
                int to=pam[cur].trans;
                while(s[i-pam[to].len-1]!=s[i]||((pam[to].len+2)<<1)>pam[now].len)to=pam[to].fail;
                pam[now].trans=pam[to].ch[s[i]-'a'];
            }
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
    int n;
    cin>>n;
    cin>>s;
    build();
    int ans=0;
    for(int i=ncnt;i>=2;i--){
        if(pam[i].len%4==0){
            //  cout<<pam[i].len<<' ';
            //  cout<<pam[pam[i].trans].len<<endl;
            if(pam[pam[i].trans].len==pam[i].len/2){
                ans=max(ans,pam[i].len);
            }
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}
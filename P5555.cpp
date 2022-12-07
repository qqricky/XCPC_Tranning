#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optmise(2);
const int N=3e5+10; 
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
string s;
string s2;
struct Node{
    int sum=0;
    int len;
    int fail;
    int ch[26]={};
    Node() {}
}pam[N],pam2[N];
int last;
int ncnt;
int last2;
int ncnt2;
int New(int len) {
    ncnt++;
    pam[ncnt].len = len;
    pam[ncnt].fail = 0;
    pam[ncnt].sum=0;
    for(int j=0;j<=25;j++){
        pam[ncnt].ch[j]=0;
    }
    return ncnt;
}
int New2(int len) {
    ncnt2++;
    pam2[ncnt2].len = len;
    pam2[ncnt2].fail = 0;
    pam2[ncnt2].sum=0;
    for(int j=0;j<=25;j++){
        pam2[ncnt2].ch[j]=0;
    }
    return ncnt2;
}
int getfail(int pre, int now) {
    while (s[now - pam[pre].len - 1] != s[now])pre=pam[pre].fail;
    return pre;
}
int getfail2(int pre, int now) {
    while (s2[now - pam2[pre].len - 1] != s2[now])pre=pam2[pre].fail;
    return pre;
}
void build() {
    ncnt = 1;
    pam[0].len = 0; pam[1].len = -1;
    pam[0].fail = 1; pam[1].fail = 0;
    last = 0;
    for(int i=0;i<=25;i++)pam[0].ch[i]=pam[1].ch[i]=0;
    for (int i=0;i<s.length();i++) {
        int cur = getfail(last, i);
        if (pam[cur].ch[s[i] - 'a'] == 0) {
            int now = New(pam[cur].len + 2);
            //if(i==s.length()-1)cout<<pam[now].len<<"  "<<pam[now].sum<<" id "<<now<<endl;
            pam[now].fail = pam[getfail(pam[cur].fail, i)].ch[s[i] - 'a'];
            //cout<<"waht  "<<pam[8].sum<<endl;
            //cout<<"to "<<now<<endl;
            //ind[pam[now].fail]++;
            pam[cur].ch[s[i] - 'a']=now;
            //cout<<"endwaht  "<<pam[8].sum<<endl;
        }
        last = pam[cur].ch[s[i] - 'a'];
        //if(i==s.length()-1)cout<<ncnt<<"    "<<last<<endl;
        //cout<<pam[last].sum<<endl;
        //if(pam[last].len==7)cout<<pam[last].sum<<endl;
        pam[last].sum++;
    }
}
void build2() {
    ncnt2 = 1;
    pam2[0].len = 0; pam2[1].len = -1;
    pam2[0].fail = 1; pam2[1].fail = 0;
    last2 = 0;
    for(int i=0;i<=25;i++)pam2[0].ch[i]=pam2[1].ch[i]=0;
    for (int i=0;i<s2.length();i++) {
        int cur = getfail2(last2, i);
        if (pam2[cur].ch[s2[i] - 'a'] == 0) {
            int now = New2(pam2[cur].len + 2);
            pam2[now].fail = pam2[getfail2(pam2[cur].fail, i)].ch[s2[i] - 'a'];
            pam2[cur].ch[s2[i] - 'a']=now;
        }
        last2 = pam2[cur].ch[s2[i] - 'a'];
        pam2[last2].sum++;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s2;
    cin>>s;
    build();
    build2();
    int ans=0;
    int num=1;
    // for(int i=ncnt;i;i--){
    //     pam[pam[i].fail].sum+=pam[i].sum;
    // }
    // for(int i=ncnt;i;i--){
    //     pam2[pam2[i].fail].sum+=pam2[i].sum;
    // }
    queue<pair<int,int> >q;
    q.push(make_pair(1,1));
    q.push(make_pair(0,0));
    // queue<int>qq;
    // qq.push(1),qq.push(0);
    // while(!qq.empty()){
    //     int u=qq.front();
    //     qq.pop();
    //     cout<<pam2[u].len<<' '<<pam2[u].sum<<endl;
    //     for(int i=0;i<=25;i++){
    //         if(pam2[u].ch[i]){
    //             qq.push(pam2[u].ch[i]);
    //         }
    //     }
    // }
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        //cout<<pam[u.first].len<<endl;
        if(pam[u.first].len>ans){
            ans=pam[u.first].len;
            num=1;
        }
        else if(pam[u.first].len==ans){
            num++;
            //cout<<num<<endl;
        }
        for(int i=0;i<=25;i++){
            if(pam[u.first].ch[i]&&pam2[u.second].ch[i]){
                q.push(make_pair(pam[u.first].ch[i],pam2[u.second].ch[i]));
            }
        }
        //cout<<u.first<<' '<<u.second<<endl;
    }
    cout<<ans<<' '<<num;
    //cout.flush();
    //system("pause");
    return 0;
}
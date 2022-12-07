#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
struct state {
  int len, link ,val;
  map<int, int> next;
};
const int MAXLEN = 200005;
state st[MAXLEN * 2];
int sz, last;
ll ans;
void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
  st[0].next.clear();
}
void sam_extend(int c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  st[cur].next.clear();
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next.clear();
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
  cout<<"# "<<st[cur].len-st[st[cur].link].len<<endl;
}
struct node
{
  int val,num;
};
node que[N*2];
int ncnt=0;
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
        sam_init();
        ncnt=0;
        int n;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sam_extend(a[i]);
        }
        int num=0;
        // memset(vis,0,sizeof(bool)*(sz+2));
        // while(q.size()){
        //     num++;
        //     // if(num>=1e8){
        //     //     cout<<num<<endl;
        //     //     break;
        //     // }
        //     auto pr=q.front();
        //     q.pop();
        //     int now=pr.first;
        //     int val=pr.second;
        //     ans+=pr.second;
        //     for(auto x:st[now].next){
        //         if(x.second){
        //             int nv=max(val,x.first);
        //             if(!vis[x.second]){
        //                 q.push(make_pair(x.second,nv));
        //                 vis[x.second]=1;
        //             }
        //             else{
        //                 ans+=nv;
        //             }
        //         }
        //     }
        // }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}
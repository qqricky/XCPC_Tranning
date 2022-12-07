#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10;
using namespace std;
ll ans=0;
struct state {
	int len,link;
	int ch[26]={};
};
state st[2*N];
int sz, last;
void sam_init() {
	//ind[0]=INF;
   	sz = last = 0;
   	st[0].len = 0;
   	st[0].link = -1;
}
void sam_extend (char cc) {
    int c=cc-'a';
	int cur = ++sz;
	st[cur].len = st[last].len + 1;
	//qq.push(cur);
	int p;
	for (p=last; p!=-1 && !st[p].ch[c]; p=st[p].link)
		st[p].ch[c] = cur;
	if (p == -1){
		st[cur].link = 0;
    }
	else {
		int q = st[p].ch[c];
		if (st[p].len + 1 == st[q].len){
		    st[cur].link = q;
        }
		else {
		int clone = ++sz;
			st[clone].len = st[p].len + 1;
            for(int j=0;j<=25;j++)
			    st[clone].ch[j] = st[q].ch[j];
			st[clone].link = st[q].link;
			//ind[st[clone].link]++;
			for (; p!=-1 && st[p].ch[c]==q; p=st[p].link)
			    st[p].ch[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
string str;
string s;
ll sum[200100]={};
ll dp[200100][24];
void stt(int n) {
    for (int i = 0; i <= n; i++)
        dp[i][0] = sum[i];
    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}
ll mm[200010];
ll rmq(int x,int y){
    int k=mm[y-x+1];
    if(x==0){
        x++;
        k=mm[y-x+1];
        return min(min(0ll,dp[x][k]),dp[y-(1<<k)+1][k]);
    }
    // cout<<x<<' '<<y<<' '<<k<<endl;
    return min(dp[x][k],dp[y-(1<<k)+1][k]);
}
ll query(int l, int r) {
    int k = log2(r - l + 1);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    cin>>str;
    int len=str.size();
	//cout<<len<<endl;
    str=' '+str;
    sam_init();
    for(int i=1;i<=len;i++)sam_extend(str[i]);
    for(int i=1;i<=m;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    mm[0]=-1;
    for(int i=1;i<=m;i++){
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp[i][0]=sum[i];
    }
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    // stt(m);
    // cout<<query(0,3)<<endl;
    for(int i=1;i<=k;i++){
        cin>>s;
        int now=0;
        ll ans=0;
        int val=0;
        // cout<<"!    :"<<i<<'\n';
        for(int j=0;j<s.length();j++){
            while(st[now].ch[s[j]-'a']==0&&now!=-1){
                now=st[now].link;
            }
            if(now==-1){
                val=0;
                now=0;
                continue;
            }
            val=min(val,st[now].len);
            now=st[now].ch[s[j]-'a'];
            // if(now==0)continue;
            val++;
            // cout<<j<<' '<<val<<'\n';
            // cout<<sum[j+1]<<' '<<query(j+1-val,j+1)<<'\n';
            // cout<<"val:"<<val<<"  : ";
            // cout<<j<<' '<<sum[j+1]<<' '<<query(j+1-val,j+1)<<'\n';
            ans=max(ans,sum[j+1]-rmq(j+1-val,j+1));
        }
        cout<<ans<<'\n';
    }
    cout.flush();
	system("pause");
    return 0;
}
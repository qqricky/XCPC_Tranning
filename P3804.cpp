#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10;
using namespace std;
ll ans=0;
queue<int>qq;
int ind[2*N]={};
struct state {
	int len,link;
	int ch[26]={};
    int cnt;
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
	st[cur].cnt=1;
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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int len=str.size();
	//cout<<len<<endl;
    str=' '+str;
    sam_init();
    for(int i=1;i<=len;i++)sam_extend(str[i]);
	for(int i=1;i<=sz;i++){
		ind[st[i].link]++;
	}
	for(int i=0;i<=sz;i++)if(!ind[i])qq.push(i);
	while(!qq.empty()){
		int u=qq.front();
		if(st[u].cnt>1)
			ans=max(ans,1ll*st[u].cnt*st[u].len);
		//cout<<st[u].cnt<<"   "<<st[u].len<<endl;
		qq.pop();
			st[st[u].link].cnt+=st[u].cnt;
			ind[st[u].link]--;
			if(ind[st[u].link]==0&&st[u].link!=0){
				qq.push(st[u].link);
			}
	}
    cout<<ans<<endl;
	//system("pause");
    return 0;
}
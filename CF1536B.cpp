#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10;
using namespace std;
queue<int>qq;
int ind[2*N]={};
struct state {
	int len,link;
	int ch[26]={};
    int cnt;
};
state st[2*N];
int d[2*N]={};
int sz, last;
bool vis[2*N]={};
void sam_init() {
	//ind[0]=INF;
   	sz = last = 0;
   	st[0].len = 0;
   	st[0].link = -1;
    for(int i=0;i<=25;i++)st[0].ch[i]=0;
   	++sz;
}
void sam_extend (char cc) {
    int c=cc-'a';
	int cur = sz++;
    for(int i=0;i<=25;i++)st[cur].ch[i]=0;
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
		int clone = sz++;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char ch;
        sam_init();
        for(int i=1;i<=n;i++){
            cin>>ch;
            sam_extend(ch);
        }
        queue<pair<int,string>>q;
        q.push(make_pair(0,""));
        while(!q.empty()){
            pair<int,string> u=q.front();
            q.pop();
            for(int i=0;i<=25;i++){
                if(st[u.first].ch[i]==0){
                    cout<<u.second<<(char)(i+'a')<<endl;
                    goto end;
                }
                q.push(make_pair(st[u.first].ch[i],u.second+(char)('a'+i)));
            }
        }
        end:;
    }
    //cout.flush();
	//system("pause");
    return 0;
}
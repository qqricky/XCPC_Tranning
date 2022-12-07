#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=6e5+10;
using namespace std;
int a[N/2];
struct state {
	int len,link;
	map<int,int> next;
};
state st[N*2];
int sz=0, last=0;
void sam_init() {
   sz = last = 0;
   st[0].len = 0;
   st[0].link = -1;
   ++sz;
}
void sam_extend (int c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
		st[cur].link = q;
		else {
		int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
			st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
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
    sam_init();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sam_extend(a[i]);
    }
    for(int i=1;i<=n;i++)sam_extend(a[i]);
    int now=0;
    for(int i=1;i<=n;i++){
        auto it=st[now].next.begin();
        cout<<it->first<<' ';
        now=it->second;
    }
    cout.flush();
    //system("pause");
    return 0;
}
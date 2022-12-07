#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

struct state {
	int len,link;
	map<char,int> next;
};
const int MAXLEN = 100000;
state st[MAXLEN*2];
int sz, last;
void sa_init() {
   sz = last = 0;
   st[0].len = 0;
   st[0].link = -1;
   ++sz;
	/*
	// 若关于不同的字符串多次建立后缀自动机，就需要执行这些代码：
	for (int i=0; i<MAXLEN*2; ++i)
		st[i].next.clear();
	*/
}
void sa_extend (char c) {
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
    
    //system("pause");
    return 0;
}
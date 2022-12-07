#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long lolong;
inline int input() { int x; scanf("%d", &x); return x; }
inline lolong linput() { lolong x; scanf("%lld", &x); return x; }

const int maxn = 100005;

struct Juice {
	int d, p, l;
};
Juice ju[maxn];

lolong qg[maxn], ql[maxn];
int ans[maxn];
int shit[maxn], shit_l[maxn], shit_r[maxn];
lolong bit_p[maxn], bit_l[maxn];

inline void add(int p, int l, int typ) {
	for(int k = p; k < maxn; k += k & -k) {
		bit_p[k] += 1ll * p * l * typ;
		bit_l[k] += l * typ;
	}
}

inline lolong query_p(int p) {
	lolong res = 0;
	for(int k = p; k; k -= k & -k)
		res += bit_p[k];
	return res;
}

inline lolong query_l(int p) {
	lolong res = 0;
	for(int k = p; k; k -= k & -k)
		res += bit_l[k];
	return res;
}

bool cmp(Juice a, Juice b) {
	return a.d < b.d;
}

void solve(int l, int r, int L, int R) {
	if(L == R) {
		for(int i = l; i <= r; i ++)
			ans[shit[i]] = ju[L].d;
		add(ju[L].p, ju[L].l, 1);
		return;
	}

	int M = (L + R + 1) >> 1;

	for(int i = M; i <= R; i ++)
		add(ju[i].p, ju[i].l, 1);

	int lp = 0, rp = 0;

	for(int i = l; i <= r; i ++) {
		int id = shit[i];

		int ll = 0, rr = maxn - 1;
		while(ll < rr) {
			int mid = (ll + rr) >> 1;
			if(query_l(mid) >= ql[id])
				rr = mid;
			else
				ll = mid + 1;
		}
		cout<<shit[i]<<"  :  "<<ll<<endl;
		lolong now_l = query_l(ll), now_p = query_p(ll);
		if(now_l >= ql[id] and now_p - (now_l - ql[id]) * ll <= qg[id]){
			cout<<id<<endl;
			shit_r[++ rp] = id;
		}
		else
			shit_l[++ lp] = id;
	}

	for(int i = 1; i <= lp; i ++)
		shit[l + i - 1] = shit_l[i];
	for(int i = 1; i <= rp; i ++)
		shit[l + lp + i - 1] = shit_r[i];

	for(int i = M; i <= R; i ++)
		add(ju[i].p, ju[i].l, -1);
	cout<<rp<<endl;
	solve(l + lp, r, M, R);
	solve(l, l + lp - 1, L, M - 1);
}

int main() {
	int n = input(), q = input();

	for(int i = 1; i <= n; i ++) {
		ju[i].d = input();
		ju[i].p = input();
		ju[i].l = input();
	}

	ju[0].d = -1;
	ju[0].p = 1;
	ju[0].l = 1;

	std::sort(ju, ju + n + 1, cmp);

	for(int i = 1; i <= q; i ++) {
		qg[i] = linput();
		ql[i] = linput();
		shit[i] = i;
	}

	solve(1, q, 0, n);

	for(int i = 1; i <= q; i ++)
		printf("%d\n", ans[i]);
    system("pause");
    return 0;
}
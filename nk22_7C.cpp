#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int n, m, maxn;
int c[N];
long long sum=0;
int cnt[4000010]={};
long long ans1[N];

struct query {
  int l, r, id;

  bool operator<(const query &x) const {
    if (l / maxn != x.l / maxn) return l < x.l;
    return (l / maxn) & 1 ? r < x.r : r > x.r;
  }
} a[N];

void add(int i) {
  sum += cnt[i];
  cnt[i]++;
}

void del(int i) {
  cnt[i]--;
  sum -= cnt[i];
}

int main() {
    scanf("%d %d", &n, &m);
    maxn = sqrt(n);
    c[0]=0;
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i=1;i<=n;i++){
        c[i]^=c[i-1];
    }
    for (int i = 0; i < m; i++){
         scanf("%d %d", &a[i].l, &a[i].r), a[i].id = i;
         a[i].l--;
    }
    sort(a, a + m);
    for (int i = 0, l = 1, r = 0; i < m; i++) {
        if (a[i].l == a[i].r) {
          ans1[a[i].id] = 1;
          continue;
        }
        while (l > a[i].l) add(c[--l]);
        while (r < a[i].r) add(c[++r]);
        while (l < a[i].l) del(c[l++]);
        while (r > a[i].r) del(c[r--]);
        ll len=r-l+1;
        ans1[a[i].id] = len*(len-1)/2;
        ans1[a[i].id]-=sum;
    }
    for (int i = 0; i < m; i++) {
        printf("%lld\n", ans1[i]);
    }
    // system("pause");
    return 0;
}
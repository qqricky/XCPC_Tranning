#include <bits/stdc++.h>

using ll = long long;
using std::max;
using std::min;
const int maxn = 3e5 + 10;
const ll inf = 1ll << 62;
int n, m, i, j, k, tot;
char s[maxn];
int v[maxn], fa[maxn], id[maxn];
int cnt[maxn], sa[maxn], sec[maxn], he[maxn], rnk[maxn];
ll mn[maxn], mx[maxn], sz[maxn], ans1[maxn], ans2[maxn];
using namespace std;
inline void radix_sort()
{
  for (int i = 0; i <= m; i++)
    cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    cnt[rnk[sec[i]]]++;
  for (int i = 1; i <= m; i++)
    cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--)
    sa[cnt[rnk[sec[i]]]--] = sec[i];
}
inline void get_sa()
{
  m = 122, radix_sort();
  for (int l = 1, tot; l <= n; m = tot, l <<= 1)
  {
    tot = 0;
    for (int i = n - l + 1; i <= n; i++)
      sec[++tot] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > l)
        sec[++tot] = sa[i] - l;
    radix_sort();
    std::swap(rnk, sec), rnk[sa[1]] = tot = 1;
    for (int i = 2; i <= n; i++)
      rnk[sa[i]] = (sec[sa[i]] == sec[sa[i - 1]] && sec[sa[i] + l] == sec[sa[i - 1] + l]) ? tot : ++tot;
    if (tot == n)
      break;
  }
}
inline void get_he()
{
  for (int i = 1; i <= n; i++)
    rnk[sa[i]] = i;
  for (int i = 1, k = 0; i <= n; i++)
  {
    if (rnk[i] == 1)
      continue;
    if (k)
      k--;
    int j = sa[rnk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
      k++;
    he[rnk[i]] = k;
  }
}

int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
inline void Union(int u, int v)
{
  int ru = find(u), rv = find(v);
  int x = he[u];
  ans1[x] += 1ll * sz[ru] * sz[rv];
  ans2[x] = max(ans2[x], max(1ll * mx[ru] * mx[rv], 1ll * mn[ru] * mn[rv]));
  mx[ru] = max(mx[ru], mx[rv]), mn[ru] = min(mn[ru], mn[rv]);
  fa[rv] = ru, sz[ru] += sz[rv];
  //cout<<x<<' '<<ans1[x]<<' '<<sz[ru]<<" "<<sz[rv]<<endl;
}

int main()
{
  scanf("%d\n%s", &n, s + 1);
  for (int i = 1; i <= n; i++)
    scanf("%d", v + i);
  for (int i = 1; i <= n; i++)
    rnk[i] = s[i], sec[i] = i;
  get_sa(), get_he();
  for (int i = 1; i <= n; i++)
    id[i] = fa[i] = i, ans1[i] = 0, ans2[i] = -inf, sz[i] = 1, mx[i] = mn[i] = v[sa[i]];
  std::sort(id + 1, id + n + 1, [](int a, int b)
            { return he[a] > he[b]; });
  // for(int i=1;i<=n;i++){
  //   cout<<i<<' '<<sz[i]<<' '<<mx[i]<<' '<<mn[i]<<he[i]<<fa[i]<<endl;
  // }
  for (int i = 1, x, y; i <= n; i++)
    if (find(id[i]) != find(id[i] - 1))
    {
      Union(id[i], id[i] - 1);
    }
  for (int i = n - 2; i >= 0; i--)
    ans1[i] += ans1[i + 1], ans2[i] = max(ans2[i], ans2[i + 1]);
  for (int i = 0; i < n; i++)
    printf("%lld %lld\n", ans1[i], !ans1[i] ? 0 : ans2[i]);
  system("pause");
  return 0;
}
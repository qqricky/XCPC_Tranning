#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N = 3e5 + 10;
using namespace std;
int rk[3 * N], sa[3 * N], bu[N], x[N], y[N];
int h[N];
void sort(int *rk, int *a, int *b, int n, int m)
{
    //rk是要排序的串，a是要排序的字符的下标，其顺序是第二关键字
    for (int i = 0; i <= m; i++)
        bu[i] = 0;
    for (int i = 0; i < n; i++)
        bu[rk[a[i]]]++;
    for (int i = 1; i <= m; i++)
        bu[i] += bu[i - 1];
    for (int i = n - 1; i >= 0; i--)
        b[--bu[rk[a[i]]]] = a[i];
}
bool cmp3(int *r, int x, int y)
{
    return r[x] == r[y] && r[x + 1] == r[y + 1] && r[x + 2] == r[y + 2];
}
bool cmpt(int *r, int x, int y)
{ //比较两类后缀的大小
    if (r[x] != r[y])
        return r[x] < r[y];
    if (x % 3 == 1)
        return bu[x + 1] < bu[y + 1];
    else
        return !cmpt(r, y + 1, x + 1);
}
void DC3(int *rk, int *sa, int n, int m)
{
    bool h = (n % 3 == 1);
    if (h)
        rk[n++] = 0;
    //如果n%3==1，在原串末尾增加一个空的A类后缀，以防递归排序越界
    int *rn = rk + n + 2, *san = sa + n, ln = 0, p;
    //ln: B类后缀的数量
    for (int i = 0; i < n; i++)
        if (i % 3)
            x[ln++] = i;
    rk[n] = rk[n + 1] = 0; //在原串后增加两个空字符，方便处理
    sort(rk + 2, x, y, ln, m);
    sort(rk + 1, y, x, ln, m);
    sort(rk, x, y, ln, m);
    int ta = 0, td = (n + 1) / 3;
//ta: A类后缀的数量
//td: i%3==1的后缀的数量
#define F(x) (x / 3) + (x % 3 == 1 ? 0 : td)
    //利用三个字符构造新串
    //F(x): 原串的后缀x在新串中的位置
    rn[F(y[0])] = p = 1;
    for (int i = 1; i < ln; i++)
    {
        if (!cmp3(rk, y[i], y[i - 1]))
            p++;
        rn[F(y[i])] = p;
    }
    if (p < ln)
        DC3(rn, san, ln, p); //递归对B类后缀进行排序
    else
        for (int i = 0; i < ln; i++)
            if (rn[i])
                san[rn[i] - 1] = i;
    for (int i = 0; i < ln; i++)
        if (san[i] < td)
            y[ta++] = san[i] * 3;
    //对于所有i%3==1的后缀，其排名是之前一个A类后缀排序用的第二关键字
    sort(rk, y, x, ta, m);
#define G(x) (x >= td ? (x - td) * 3 + 2 : x * 3 + 1)
    //G(x): 新串的后缀x在原串中的位置
    for (int i = 0; i < ln; i++)
        bu[y[i] = G(san[i])] = i; //这里的bu[x]就是B类后缀x的排名
    bu[n] = -1;
    int i = 0, j = h;
    p = 0; //如果h等于1，则第一个A类后缀是为了防止越界加入的，归并时去除
    while (i < ta && j < ln)
    {
        if (cmpt(rk, y[j], x[i]))
            sa[p++] = y[j++];
        else
            sa[p++] = x[i++];
    }
    while (i < ta)
        sa[p++] = x[i++];
    while (j < ln)
        sa[p++] = y[j++];
}
ll val[N];
ll anss[N] = {};
ll ans[N] = {};
int fa[N];
ll ma[N];
ll mi[N];
int sz[N];
int id[N];
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
// void merge(int x, int y, int len)
// {
//     int xx = find(x), yy = find(y);
//     if (xx < yy)
//     {
//         ans[len] += sz[xx] * sz[yy];
//         anss[len] = max(anss[len], max(ma[xx] * ma[yy], mi[xx] * mi[yy]));
//         ma[xx] = max(ma[yy], ma[xx]);
//         mi[xx] = min(mi[yy], mi[xx]);
//         fa[yy] = xx;
//         sz[xx] += sz[yy];
//     }
//     else if (xx > yy)
//     {
//         ans[len] += sz[xx] * sz[yy];
//         // if(len==1){
//         //     cout<<ans[len]<<' '<<sz[xx]<<' '<<sz[yy]<<endl;
//         // }
//         anss[len] = max(anss[len], max(ma[xx] * ma[yy], mi[xx] * mi[yy]));
//         ma[yy] = max(ma[yy], ma[xx]);
//         mi[yy] = min(mi[yy], mi[xx]);
//         fa[xx] = yy;
//         sz[yy] += sz[xx];
//     }
// }
inline void Union(int u, int v)
{
    int ru = find(u), rv = find(v);
    int x = h[u];
    ans[x] += 1ll * sz[ru] * sz[rv];
    anss[x] = max(anss[x], max(1ll * ma[ru] * ma[rv], 1ll * mi[ru] * mi[rv]));
    ma[ru] = max(ma[ru], ma[rv]), mi[ru] = min(mi[ru], mi[rv]);
    fa[rv] = ru, sz[ru] += sz[rv];
    //cout<<x<<' '<<ans[x]<<' '<<sz[ru]<<' '<<sz[rv]<<endl;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // std::cout.tie(0);
    int t, n, q;
    t = 1;
    while (t--)
    {
        string str;
        cin >> n >> str;
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
            //cout<<i<<' '<<val[i]<<endl;
        }
        //cout<<"waht"<<endl;
        for (int i = 0; i < n; i++)
        {
            rk[i] = str[i] - 'a' + 1;
        }
        DC3(rk, sa, n, 26);
        for (int i = n; i >= 1; i--)
            sa[i] = sa[i - 1] + 1;
        for (int i = 1; i <= n; i++)
            rk[sa[i]] = i;
        str = ' ' + str;
        for (int i = 1, k = 0; i <= n; ++i)
        {
            if (k)
                --k;
            while (str[i + k] == str[sa[rk[i] - 1] + k])
                ++k;
            h[rk[i]] = k;
        }
        h[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            ma[i] = mi[i] = val[sa[i]];
            fa[i] = i;
            sz[i] = 1;
            id[i] = i;
            anss[i] = -INF;
        }
        // for(int i=1;i<=n;i++){
        //     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        //     dp[i][0]=h[i];
        // }
        // for(int j=1;j<=mm[n];j++)
        //     for(int i=1;i+(1<<j)-1<=n;i++){
        //         dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        //     }
        // h[n+1]=-114514;
        //for(int i=1;i<=n;i++)cout<<h[i]<<' ';
        //cout<<endl;
        sort(id + 1, id + n + 1, [](int a, int b)
                  { return h[a] > h[b]; });
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << ' ' << sz[i] << ' ' << ma[i] << ' ' << mi[i] << h[i] << fa[i] << endl;
        // }
        for (int i = 1, x, y; i <= n; i++)
            if (find(id[i]) != find(id[i] - 1))
            {
                Union(id[i], id[i] - 1);
            }
        //cout<<endl;
        for (int i = n - 2; i >= 0; i--)
            ans[i] += ans[i + 1], anss[i] = max(anss[i], anss[i + 1]);
        // for(int i=n-1;i>=1;i--){
        //     ans[i-1]+=ans[i];
        //     anss[i-1]=max(anss[i-1],anss[i]);
        // }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ' << (ans[i] ? anss[i] : 0) << '\n';
    }
    //cout.flush();
    //std::system("pause");
    return 0;
}
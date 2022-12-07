/*
 * @Author: csc
 * @Date: 2021-04-08 23:20:34
 * @LastEditTime: 2021-04-09 00:26:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code_formal\niucow\icpc_21_km_A.cpp
 */
#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define sf(n) scanf("%d", &n)
#define sff(n1, n2) scanf("%d %d", &n1, &n2)
#define sfff(n1, n2, n3) scanf("%d %d %d", &n1, &n2, &n3)
#define sl(n) scanf("%lld", &n)
#define sll(n1, n2) scanf("%lld %lld", &n1, &n2)
#define slll(n1, n2, n3) scanf("%lld %lld %lld", &n1, &n2, &n3)
#define for0(i, n) for (i = 0; i < n; i++)
#define for1n(i, n) for (i = 1; i <= n; i++)
#define forab(i, a, b) for (i = a; i <= b; i++)
#define forba(i, a, b) for (i = b; i >= a; i--)
#define pb push_back
#define fi first
#define se second
#define int long long
#define endl '\n'
#define vi vector<int>
#define vii vector<vector<int>>
#define pt pair<int, int>
#define mem(ara, n) memset(ara, n, sizeof(ara))
#define memb(ara) memset(ara, false, sizeof(ara))
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define sz(x) x.size()
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
namespace fastIO
{
    inline void input(int &res)
    {
        char c = getchar();
        res = 0;
        int f = 1;
        while (!isdigit(c))
        {
            f ^= c == '-';
            c = getchar();
        }
        while (isdigit(c))
        {
            res = (res << 3) + (res << 1) + (c ^ 48);
            c = getchar();
        }
        res = f ? res : -res;
    }
    inline int qpow(int a, int b)
    {
        int ans = 1, base = a;
        while (b)
        {
            if (b & 1)
                ans = (ans * base % mod + mod) % mod;
            base = (base * base % mod + mod) % mod;
            b >>= 1;
        }
        return ans;
    }
    int fact(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * 1ll * i % mod;
        }
        return res;
    }
    int C(int n, int k)
    {
        return fact(n) * 1ll * qpow(fact(k), mod - 2) % mod * 1ll * qpow(fact(n - k), mod - 2) % mod;
    }
}
using namespace fastIO;
 
using namespace std;
 
int n, k;
char s[N];
bool vis[N];
int v[N], L[N], R[N];
 
struct data
{
    int l, r, val;
} a[N];
 
priority_queue<pt, vector<pt>, greater<pt>> q;
 
signed main()
{
    int _ = 1;
    //input(_);
    while (_--)
    {
        input(n), input(k);
        int ans = 0, sum = 0, i;
        sc("%s", s + 1);
 
        forab(i, 1, n - 1)
        {
            a[i].val = (s[i] != 'a') + (s[i + 1] != 'c');
            a[i].l = i - 1, a[i].r = i + 1;
            L[i] = R[i] = i;
            q.push({a[i].val, i});
        }
        a[0].val = a[n].val = 1e9;
 
        forab(i, 1, n / 2)
        {
            while (vis[q.top().second])
                q.pop();
            pt p = q.top();
            q.pop();
            sum += p.first;
 
            if (sum <= k)
                ans = i;
            else
                break;
 
            v[L[p.second]] ^= 1, v[R[p.second] + 1] ^= 1;
            L[p.second] = L[a[p.second].l];
            R[p.second] = R[a[p.second].r];

            vis[a[p.second].l] = vis[a[p.second].r] = 1;
            a[p.second].val = a[a[p.second].l].val + a[a[p.second].r].val - a[p.second].val;
            a[p.second].l = a[a[p.second].l].l,a[a[p.second].l].r = p.second;
            a[p.second].r = a[a[p.second].r].r,a[a[p.second].r].l = p.second;
            q.push({a[p.second].val, p.second});   
        }
        pr("%lld\n", ans);
        forab(i, 1, n)
        {
            v[i] ^= v[i - 1];
            if (v[i])
                s[i] = 'a', s[i + 1] = 'c';
        }
        cout << s + 1 << endl;
    }
 
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
char s[MAXN << 1], t[MAXN << 1];
int n, m, num[MAXN << 1];
void init() {
    n = strlen(s);
    t[0] = '$';
    for(int i = 1; i <= 2 * n; i += 2) {
        t[i] = '#';
        t[i + 1] = s[i / 2];
    }
    t[2 * n + 1] = '#';
    t[2 * n + 2] = '!';
    m = 2 * n + 1;
    int mx = 0, id = 0;
    memset(num, 0, sizeof num);
    for(int i = 1; i <= m; i++) {
        if(mx > i) num[i] = min(mx - i, num[2 * id - i]);
        else num[i] = 1;
        while(t[i - num[i]] == t[i + num[i]]) num[i]++;
        if(i + num[i] > mx) {
            mx = i + num[i];
            id = i;
        }
    }
}
int f[MAXN];
void update(int x) {
    while(x < MAXN) {
        f[x]++;
        x += x & -x;
    }
}
int query(int x) {
    int res = 0;
    while(x) {
        res += f[x];
        x -= x & -x;
    }
    return res;
}
vector<int> G[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        init();
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 2; i <= m; i += 2) {
            int x = i / 2 - 1, r = (num[i] - 1) / 2;
            if(t[i] != '#') {
                num[x] = r;
                if(r) G[x - r].push_back(x);
            } else num[x] = 0;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < G[i].size(); j++) update(G[i][j]);
            ans += query(min(n, i + num[i])) - query(i);
        }
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int p[N], n, tot;
vector<int> loop[N], big;
vector<pair<int, int>> ans;
bool v[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) {
        if (v[i] || p[i] == i)continue;
        tot++;
        for (int j = i; !v[j]; j = p[j])
            loop[tot].push_back(j), v[j] = true;
        if ((int) loop[tot].size() > 2)big.push_back(tot);
    }
    if (!tot)return puts("0"), 0;
    if (!big.empty()) {
        puts("2");
        for (int x = 1; x <= tot; x++) {
            if ((int) loop[x].size() < 3) {
                ans.emplace_back(loop[x][0], loop[x][1]);
                continue;
            }
            for (int i = 1, j = (int) loop[x].size() - 1; i < j; i++, j--)
                ans.emplace_back(loop[x][i], loop[x][j]);
        }
        printf("%d", (int) ans.size());
        for (pair<int, int> x:ans)printf(" %d %d", x.first, x.second);
        puts(""), ans.clear();
        for (int x:big) {
            ans.emplace_back(loop[x][1], loop[x][0]);
            for (int i = 2, j = (int) loop[x].size() - 1; i < j; i++, j--)
                ans.emplace_back(loop[x][i], loop[x][j]);
        }
        printf("%d", (int) ans.size());
        for (pair<int, int> x:ans)printf(" %d %d", x.first, x.second);
    } else {
        puts("1");
        printf("%d", tot);
        for (int x = 1; x <= tot; x++)
            printf(" %d %d", loop[x][0], loop[x][1]);
    }
    system("pause");
    return 0;
}

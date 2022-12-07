# include <bits/stdc++.h>
# define RG register
# define IL inline
# define Fill(a, b) memset(a, b, sizeof(a))
using namespace std;

typedef long long ll;
const int _(5010), __(1e6 + 10), INF(2e9);

IL ll Read(){
    char c = '%'; ll x = 0, z = 1;
    for(; c > '9' || c < '0'; c = getchar()) if(c == '-') z = -1;
    for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    return x * z;
}

int n, p, q, id[50][50], tmp[__], mp[50][50], num, ans[__], len;
int cnt, fst[_], w[__], to[__], nxt[__], dis[_], vis[_], S, T, cost[__], pe[_], pv[_], max_flow;
queue <int> Q;

IL void Add(RG int u, RG int v, RG int f, RG int co){
    cost[cnt] = co; w[cnt] = f; to[cnt] = v; nxt[cnt] = fst[u]; fst[u] = cnt++;
    cost[cnt] = -co; w[cnt] = 0; to[cnt] = u; nxt[cnt] = fst[v]; fst[v] = cnt++;
}

IL bool Bfs(){
    Q.push(S); Fill(dis, 127); dis[S] = 0; vis[S] = 1;
    while(!Q.empty()){
        RG int u = Q.front(); Q.pop();
        for(RG int e = fst[u]; e != -1; e = nxt[e]){
            if(!w[e] || dis[to[e]] <= dis[u] + cost[e]) continue;
            dis[to[e]] = dis[u] + cost[e];
            pe[to[e]] = e; pv[to[e]] = u;
            if(!vis[to[e]]) vis[to[e]] = 1, Q.push(to[e]);
        }
        vis[u] = 0;
    }
    if(dis[T] >= dis[T + 1]) return 0;
    RG int ret = INF;
    for(RG int u = T; u != S; u = pv[u]) ret = min(ret, w[pe[u]]);
    for(RG int u = T; u != S; u = pv[u]) w[pe[u]] -= ret, w[pe[u] ^ 1] += ret;
    max_flow += ret;
    return 1;
}

IL void Dfs(RG int x, RG int y){
    RG int Id = id[x][y], d0 = id[x + 1][y], d1 = id[x][y + 1];
    for(RG int e = fst[Id + num]; e != -1; e = nxt[e]){
        if(tmp[e] >= w[e ^ 1]) continue;
        if(to[e] == d0){
            ++tmp[e]; ans[++len] = 0;
            Dfs(x + 1, y);
            return;
        }
        if(to[e] == d1){
            ++tmp[e]; ans[++len] = 1;
            Dfs(x, y + 1);
            return;
        }
    }
        
}

int main(RG int argc, RG char *argv[]){

    Fill(fst, -1);
    n = Read(); q = Read(); p = Read();
    for(RG int i = 1; i <= p; ++i)
        for(RG int j = 1; j <= q; ++j)
            id[i][j] = ++num;
    T = num + num + 1;
    for(RG int i = 1; i <= p; ++i)
        for(RG int j = 1; j <= q; ++j)
            mp[i][j] = Read();
    Add(S, id[1][1], n, 0); Add(id[p][q] + num, T, n, 0);
    for(RG int i = 1; i <= p; ++i)
        for(RG int j = 1; j <= q; ++j){
            if(mp[i][j] == 1) continue;
            if(!mp[i][j]) Add(id[i][j], id[i][j] + num, INF, 0);
            else Add(id[i][j], id[i][j] + num, INF, 0), Add(id[i][j], id[i][j] + num, 1, -1);
        }
    for(RG int i = 1; i <= p; ++i)
        for(RG int j = 1; j <= q; ++j){
            if(mp[i][j] == 1) continue;
            if(i < p && mp[i + 1][j] != 1) Add(id[i][j] + num, id[i + 1][j], INF, 0);
            if(j < q && mp[i][j + 1] != 1) Add(id[i][j] + num, id[i][j + 1], INF, 0);
        }
    while(Bfs());
    for(RG int i = 1; i <= max_flow; ++i){
        len = 0; Dfs(1, 1);
        for(RG int j = 1; j <= len; ++j) printf("%d %d\n", i, ans[j]);
    }
    return 0;
    cout.flush();
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define Pi acos(-1.0)
#define Inf 0x3f3f3f3f
#define Fir first
#define Sec second
#define Mid ll + (rr - ll >> 1)
#define Lson id << 1, ll, Mid
#define Rson id << 1 | 1, Mid + 1, rr
#define Lowbit(x) (x & -x)
#define Qcin std::ios::sync_with_stdio(false); std::cin.tie(nullptr)
#define Fin freopen("_input.txt", "r", stdin)
#define Fout freopen("_output.txt", "w", stdout)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

using std::cin; using std::cout; using std::endl;
using std::max; using std::min;

int t, n, k, tot, ans;
char d[10];
int cnt[5];

int f(char ch){
    if(ch == 'A')   return 1;
    if(ch == 'B')   return 2;
    if(ch == 'G')   return 3;
    else if(ch=='P')   return 4;
    else  return 0;
}

int main(){
    scanf("%d", &t);
    char s[2]; int x;
    while(t--){
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(d,0,sizeof(d));
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i){
            scanf("%s%d", s, &x);    
            int u = i % k;
            cnt[f(d[u])] = 0;
            d[u] = s[0];
            cnt[f(s[0])] += x;
            for(int j = 1; j <= 4; ++j){
                if(cnt[j] == 5) ++ans;
            }
        }
        printf("%d\n", ans);
    }

    system("pause");
    return 0;
}

/*
1
5 1
A 5
B 5
G 5
P 5
G 5
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 5005;
int T, n, tag[N], s[N];
long long f[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)scanf("%d", &tag[i]);
        for (int i = 1; i <= n; i++)scanf("%d", &s[i]);
        memset(f + 1, 0, sizeof(long long) * n);
        for (int i = 1; i <= n; i++){
            //cout<<f[i]<<endl;
            for (int j = i - 1; j >= 1; j--) {
                if (tag[i] == tag[j])continue;
                long long tmp = f[i];
                f[i] = max(f[i],f[j] + abs(s[i] - s[j]));
                f[j] = max(f[j], tmp + abs(s[i] - s[j]));
            }
        }
        printf("%lld\n", *max_element(f + 1, f + 1 + n));
    }
    system("pause");
    return 0;
}

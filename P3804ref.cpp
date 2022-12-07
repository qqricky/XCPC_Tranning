#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define INF 0x3f3f3f3f
const int Maxn=1e6+10;
using namespace std;
int to[Maxn << 1][26], len[Maxn << 1], link[Maxn << 1], cnt = 1, last = 1;
LL siz[Maxn << 1], Max;

void extend(int c) {
  int cur = ++cnt; len[cur] = len[last] + 1;
  int p = last;
  while(p && (!to[p][c])) {
    to[p][c] = cur;
    p = link[p];
  }
  if(!p) link[cur] = 1;
  else {
    int q = to[p][c];
    if(len[p] + 1 == len[q]) link[cur] = q;
    else {
      int cl = ++cnt; len[cl] = len[p] + 1;
      for(int i = 0; i < 26; ++i) to[cl][i] = to[q][i];
      link[cl] = link[q]; link[q] = link[cur] = cl;
      while(p && to[p][c] == q) to[p][c] = cl, p = link[p];
    }
  }
  last = cur;
  siz[cur] = 1;
}
int ind[Maxn];
queue<int> que;
string str;
int main() {
  cin >> str; int n = str.size();
  string s=str;
  cout<<n<<"wwwwwwwwwwwwwwww"<<endl;
  for(int i = 0; i < n; ++i) extend(s[i] - 'a');
  for(int i = 2; i <= cnt; ++i) ind[link[i]]++;
  for(int i = 1; i <= cnt; ++i) if(!ind[i]) que.push(i);
  while(!que.empty()) {
    int t = que.front(); que.pop();
    cout<<siz[t]<<"      "<<len[t]<<endl;
    if(siz[t] > 1) Max = max(Max, 1ll * siz[t] * len[t]);
    siz[link[t]] += siz[t];
    ind[link[t]]--; if(!ind[link[t]] && link[t]) que.push(link[t]); 
  }
  printf("%lld", Max);
  system("pause");
  return 0;
}
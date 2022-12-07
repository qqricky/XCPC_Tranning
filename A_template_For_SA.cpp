#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int rk[3*N], sa[3*N], bu[N], x[N], y[N];
int dp[N][30];
int mm[N];
int h[N];
void sort(int *rk, int *a, int *b, int n, int m) {
	for (int i = 0; i <= m; i++) bu[i] = 0;
	for (int i = 0; i < n; i++) bu[rk[a[i]]]++;
	for (int i = 1; i <= m; i++) bu[i] += bu[i-1];
	for (int i = n-1; i >= 0; i--) b[--bu[rk[a[i]]]] = a[i];
}
bool cmp3(int *r, int x, int y) {
	return r[x] == r[y] && r[x+1] == r[y+1] && r[x+2] == r[y+2];
}
bool cmpt(int* r, int x, int y) {
	if (r[x] != r[y]) return r[x] < r[y];
	if (x%3 == 1) return bu[x+1] < bu[y+1];
	else return !cmpt(r, y+1, x+1);
}
void DC3(int *rk, int *sa, int n, int m) {
	bool h = (n%3 == 1); if (h) rk[n++] = 0;
	int *rn = rk+n+2, *san = sa+n, ln = 0, p;
	for (int i = 0; i < n; i++)
		if (i % 3) x[ln++] = i;
	rk[n] = rk[n+1] = 0; 
	sort(rk+2, x, y, ln, m);
	sort(rk+1, y, x, ln, m);
	sort(rk, x, y, ln, m);
	int ta = 0, td = (n+1)/3;
	#define F(x) (x/3)+(x%3==1?0:td)
	rn[F(y[0])] = p = 1;
	for (int i = 1; i < ln; i++) {
		if (!cmp3(rk, y[i], y[i-1])) p++;
		rn[F(y[i])] = p;
	}
	if (p < ln) DC3(rn, san, ln, p);
	else for (int i = 0; i < ln; i++)
		if (rn[i]) san[rn[i]-1] = i;
	for (int i = 0; i < ln; i++)
		if (san[i] < td) y[ta++] = san[i]*3;
	sort(rk, y, x, ta, m);
	#define G(x) (x>=td?(x-td)*3+2:x*3+1)
	for (int i = 0; i < ln; i++)
		bu[y[i] = G(san[i])] = i;
	bu[n] = -1;
	int i = 0, j = h; p = 0;
	while (i < ta && j < ln) {
		if (cmpt(rk, y[j], x[i])) sa[p++] = y[j++];
		else sa[p++] = x[i++];
	}
	while (i < ta) sa[p++] = x[i++];
	while (j < ln) sa[p++] = y[j++];
}
int rmq(int x,int y){
    int k=mm[y-x+1];
    return min(dp[x][k],dp[y-(1<<k)+1][k]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t,n,q;
    cin>>t;
    while(t--){
        string str;
        cin>>n;
        cin>>str;
        for(int i=0;i<n;i++){
            rk[i]=str[i]-'a'+1;
        }
        DC3(rk,sa,n,26);
        for(int i=n;i>=1;i--)sa[i]=sa[i-1]+1;
        for(int i=1;i<=n;i++)rk[sa[i]]=i;
        str=' '+str;
        for (int i = 1, k = 0; i <= n; ++i) {
          if (k) --k;
          while (str[i + k] == str[sa[rk[i] - 1] + k]) ++k;
          h[rk[i]] = k; 
        }
        h[1]=0;
        mm[0]=-1;
        for(int i=1;i<=n;i++){
            mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
            dp[i][0]=h[i];
        }
        for(int j=1;j<=mm[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++){
                dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            }
        h[n+1]=-114514;
    }
	cout.flush();
    //system("pause");
    return 0;
}
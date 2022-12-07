#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
int rk[3*N], sa[3*N], bu[N], x[N], y[N];
void sort(int *rk, int *a, int *b, int n, int m) {
	//rk是要排序的串，a是要排序的字符的下标，其顺序是第二关键字
	for (int i = 0; i <= m; i++) bu[i] = 0;
	for (int i = 0; i < n; i++) bu[rk[a[i]]]++;
	for (int i = 1; i <= m; i++) bu[i] += bu[i-1];
	for (int i = n-1; i >= 0; i--) b[--bu[rk[a[i]]]] = a[i];
}
bool cmp3(int *r, int x, int y) {
	return r[x] == r[y] && r[x+1] == r[y+1] && r[x+2] == r[y+2];
}
bool cmpt(int* r, int x, int y) { //比较两类后缀的大小
	if (r[x] != r[y]) return r[x] < r[y];
	if (x%3 == 1) return bu[x+1] < bu[y+1];
	else return !cmpt(r, y+1, x+1);
}
void DC3(int *rk, int *sa, int n, int m) {
	bool h = (n%3 == 1); if (h) rk[n++] = 0;
	//如果n%3==1，在原串末尾增加一个空的A类后缀，以防递归排序越界
	int *rn = rk+n+2, *san = sa+n, ln = 0, p;
	//ln: B类后缀的数量
	for (int i = 0; i < n; i++)
		if (i % 3) x[ln++] = i;
	rk[n] = rk[n+1] = 0; //在原串后增加两个空字符，方便处理
	sort(rk+2, x, y, ln, m);
	sort(rk+1, y, x, ln, m);
	sort(rk, x, y, ln, m);
	int ta = 0, td = (n+1)/3;
	//ta: A类后缀的数量
	//td: i%3==1的后缀的数量
	#define F(x) (x/3)+(x%3==1?0:td)
	//利用三个字符构造新串
	//F(x): 原串的后缀x在新串中的位置
	rn[F(y[0])] = p = 1;
	for (int i = 1; i < ln; i++) {
		if (!cmp3(rk, y[i], y[i-1])) p++;
		rn[F(y[i])] = p;
	}
	if (p < ln) DC3(rn, san, ln, p); //递归对B类后缀进行排序
	else for (int i = 0; i < ln; i++)
		if (rn[i]) san[rn[i]-1] = i;
	for (int i = 0; i < ln; i++)
		if (san[i] < td) y[ta++] = san[i]*3;
	//对于所有i%3==1的后缀，其排名是之前一个A类后缀排序用的第二关键字
	sort(rk, y, x, ta, m);
	#define G(x) (x>=td?(x-td)*3+2:x*3+1)
	//G(x): 新串的后缀x在原串中的位置
	for (int i = 0; i < ln; i++)
		bu[y[i] = G(san[i])] = i; //这里的bu[x]就是B类后缀x的排名
	bu[n] = -1;
	int i = 0, j = h; p = 0; //如果h等于1，则第一个A类后缀是为了防止越界加入的，归并时去除
	while (i < ta && j < ln) {
		if (cmpt(rk, y[j], x[i])) sa[p++] = y[j++];
		else sa[p++] = x[i++];
	}
	while (i < ta) sa[p++] = x[i++];
	while (j < ln) sa[p++] = y[j++];
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int len=str.size();
    for(int i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            rk[i]=str[i]-'0'+1;
        }
        else if(str[i]>='a'&&str[i]<='z'){
            rk[i]=str[i]-'a'+37;
        }
        else{
            rk[i]=str[i]-'A'+11;
        }
    }
    DC3(rk,sa,len,65);
    for(int i=0;i<len;i++)cout<<sa[i]+1<<' ';
    cout.flush();
    //system("pause");
    return 0;
}
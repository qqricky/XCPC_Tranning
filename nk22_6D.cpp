#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
const int M = 1000000-1;
struct node{
	int id,d,ad;
	bool operator <(const node &b)const{
		d>b.d;
	}
}a[N];
int b[N];
priority_queue<node> q;
int main(){
	int n;cin >> n;
	int id = 0;
	a[0].d = 1e9;
	int tot = 1;
	for(int i = 1;i <= n;++i){
		scanf("%lld",&a[i].ad);
		a[i].d = a[i].ad;
		a[i].id = i;
		q.push(a[i]);
	}
	tot = 1;
	int mx = 0;
	node t;
	while(mx!=a[n].id){
		t = q.top();q.pop();
		b[tot++] = t.id;
		mx = max(mx,t.id); 
		t.d = tot+t.ad-1;
		q.push(t);
	}
	printf("%lld\n",tot-1);
	for(int i = 1;i < tot-1;++i) printf("%lld ",b[i]);printf("%lld\n",b[tot-1]);
	return 0;
}
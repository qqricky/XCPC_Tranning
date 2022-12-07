#include<bits/stdc++.h>
#define ll long long
#define next next_
#define y1 yy
using namespace std;
vector<int> pos[100010];
int n,c[100010],next[100010],a,b,ans;
int main(){
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=n;i>=1;i--)
		pos[c[i]].push_back(i);
	for(int i=1;i<=n;i++){
		if(c[a]==c[i]){
			if(c[b]!=c[i]){
				ans++;
				b=i;
			}
			pos[c[i]].pop_back();
		}
		else if(c[b]==c[i]){
			if(c[a]!=c[i]){
				ans++;
				a=i;
			}
			pos[c[i]].pop_back();
		}
		else{
			if(!pos[c[a]].size()){
				ans++;
				b=i;
			}
			else if(!pos[c[b]].size()){
				ans++;
				a=i;
			}
			else if(pos[c[a]].back()<pos[c[b]].back()){
				ans++;
				a=i;
			}
			else{
				ans++;
				b=i;
			}
			pos[c[i]].pop_back();
		}
	}
	cout<<ans;
	return 0;
}

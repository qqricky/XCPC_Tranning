#include<bits/stdc++.h>
#define int long long
using namespace std;
int len,t,r[10000005],ans[10000005];
char s[10000005],ss[10000005];
void manacher(){
	int maxr=0,pos=0;
	for(int i=1;i<=len;i++){
		if(i<maxr)r[i]=min(r[(pos<<1)-i],maxr-i);
		else r[i]=1;
		for(;s[i-r[i]]==s[i+r[i]];++r[i]);
		if(maxr<r[i]+i)maxr=r[i]+i,pos=i;
	}
}
signed main(){
	scanf("%d",&t);
	while(t--){
		memset(r,0,sizeof(r));
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
		memset(ss,0,sizeof(ss));
		scanf("%s",ss+1);
		int lens=strlen(ss+1),ji;
		s[0]=s[1]='#';ji=1;
		for(int i=1;i<=lens;i++)s[++ji]=ss[i],s[++ji]='#';
		len=strlen(s);
		manacher();
		for(int i=1;i<=len;i++)--r[i];
		for(int i=lens;i>=1;i--){
			int ri=r[i*2];
			if(ri){
				ri>>=1;
				if(i+ri==lens)ans[i]=1;
				if(ans[i+ri]&&i-ri==1)ans[i]=1;
			}
		}
		for(int i=1;i<=lens;i++)if(ans[i])printf("%d ",i);puts("");
	}
}
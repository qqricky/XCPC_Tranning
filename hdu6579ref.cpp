#include<bits/stdc++.h>
#define M 500009
using namespace std;
int read(){
	int f=1,re=0;char ch;
	for(ch=getchar();!isdigit(ch)&&ch!='-';ch=getchar());
	if(ch=='-'){f=-1,ch=getchar();}
	for(;isdigit(ch);ch=getchar()) re=(re<<3)+(re<<1)+ch-'0';
	return re*f;
}
int pos[M][32],p[M][32],t,n,m,lastans;
void insert(int val,int num,int po){
	for(int i=30;i>=0;i--){
		if(val&(1ll<<i)){
			if(!p[num][i]){p[num][i]=val,pos[num][i]=po;return;}
			else if(pos[num][i]<po){
				swap(val,p[num][i]);
				swap(po,pos[num][i]);
			}val^=p[num][i];
		}
	}return;
}
int query(int l,int r){
	int ans=0;
	for(int i=30;i>=0;i--)
		if(pos[r][i]>=l&&(p[r][i]^ans)>ans) ans^=p[r][i];
	return ans;
}
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();lastans=0;
		memset(p,0,sizeof(p));
		memset(pos,0,sizeof(pos));
		for(int i=1;i<=n;i++){
			int x=read();
			for(int j=0;j<=30;j++)
				p[i][j]=p[i-1][j],pos[i][j]=pos[i-1][j];
			insert(x,i,i);
		}
		for(int i=1;i<=m;i++){
			int opt=read();
			if(opt){
				int x=read()^lastans;n++;
				for(int j=0;j<=30;j++)
					p[n][j]=p[n-1][j],pos[n][j]=pos[n-1][j];
				insert(x,n,n);
			}
			else{
				int l=(read()^lastans)%n+1;
                int r=(read()^lastans)%n+1;
                if(l>r) swap(l,r);
                printf("%d\n",lastans=query(l,r));
			}
		}
	}
    system("pause");
    return 0;
}

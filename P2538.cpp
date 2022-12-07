#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int f[55][55];
int con[55];
int n,m,k;
int ncnt=0,cath[55]={};
int prob[55];
int ans;
const double delta=0.993;
const double eps=1e-10;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void Floyed()
{
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int calc()
{
    int anss=0;
    for(int i=1;i<=n;i++){
        if(cath[i])continue;
        int dis=INF;
        for(int j=1;j<=n;j++){
            if(cath[j])
            dis=min(dis,f[i][j]);
        }
        anss=max(anss,dis);
    }
    return anss;
}

void SA()
{
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%k+1;
        int y=rand()%(ncnt-k)+1;
        swap(prob[x],prob[y+k]);
        cath[prob[x]]=1;
        cath[prob[y+k]]=0;
        int tmp=calc();
        int del=tmp-ans;
        if(del<0){
            ans=tmp;
        }
        else if(exp(-del/T)*RAND_MAX<=rand()){
            swap(prob[x],prob[y+k]);
            cath[prob[x]]=1;
            cath[prob[y+k]]=0;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    srand(time(0));srand(rand());srand(rand());
    read(n);read(m);read(k);
    ans=INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)f[i][j]=INF;
    }
    for(int i=1;i<=n;i++){
        read(con[i]);
        con[i]++;
    }
    for(int i=1;i<=n;i++){
        int tmp;
        read(tmp);
        f[i][con[i]]=min(tmp,f[i][con[i]]);
        f[con[i]][i]=min(tmp,f[con[i]][i]);
    }
    Floyed();
    for(int i=1;i<=m;i++){
        int tmp;
        read(tmp);
        tmp++;
        cath[tmp]=1;
    }
    for(int i=1;i<=n;i++){
        if(!cath[i]){
            prob[++ncnt]=i;
            if(ncnt<=k)cath[i]=1;
        }
    }
    ans=calc();
    if(m+k==n){
        cout<<ans;
        return 0;
    }
    //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
    while((double)clock()/CLOCKS_PER_SEC<10)SA();
    printf("%d",ans);
    //cout.flush();
    //system("pause");
    return 0;
}
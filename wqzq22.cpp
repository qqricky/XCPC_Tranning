#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
int c[N]={};
void add(int x,int k){
    while(x<=n){
        c[x]+=k;
        x+=(x&-x);
    }
}
int ask(int x){
    int ans=0;
    while(x>=1){
        ans+=c[x];
        x-=(x&-x);
    }
}
int h[N];//身高
int num[N];
int main()
{
    cin>>n;
    int maxn;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        //maxn是最高身高
        num[i]=ask(maxn)-ask(h[i]);//在他前面的身高从h【i】+1到无穷的小朋友的个数
        add(h[i],1);//身高为h【i】的增加了一个
    }
    memset(c,0,sizeof(c));//清空
    for(int i=n;i>=1;i--){
        num[i]+=ask(h[i]-1);//在他后面的比他矮的(身高从1-h[i]-1)
        add(h[i],1);
    }
    for(int i=1;i<=n;i++){
        num[i];//....num[i]是第i个小朋友最少需要的交换次数，以此计算对答案的贡献
    }
    cout.flush();
    //system("pause");
    return 0;
}
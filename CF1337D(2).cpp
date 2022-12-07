#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mes(x,a) memset(x,a,sizeof(x));

template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int INF = 0x3f3f3f3f;
const int N=1e5+10;

LL a[N],b[N],c[N];
LL cal(LL a,LL b,LL c)
{
    return (a - b)*(a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}
int main()
{

    int t ;
    scanf("%d",&t);
    while(t --)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0; i < n; i ++)
            scanf("%lld",&a[i]);
        for(int i = 0; i < m; i ++)
            scanf("%lld",&b[i]);
        for(int i = 0; i < k; i ++)
            scanf("%lld",&c[i]);
        LL res = 2e18 + 5;
        sort(a, a + n);
        sort(b, b + m);
        sort(c, c + k);
        for(int i = 0; i < n; i ++)
        {
            int x = lower_bound(b,b + m,a[i]) - b;
            int y = lower_bound(c,c + k,a[i]) - c;
            if(x == m)
                x -- ;
            if(y == k)
                y -- ;
            res = min(res,cal(a[i],b[x],c[y]));
            if(x > 0)
                res = min(res,cal(a[i],b[x - 1],c[y]));
            if(y > 0)
                res = min(res,cal(a[i],b[x],c[y - 1]));
        }
        for(int i = 0; i < m; i ++)
        {
            int x = lower_bound(a,a + n,b[i]) - a;
            int y = lower_bound(c,c + k,b[i]) - c;
            if(x == n)
                x -- ;
            if(y == k)
                y -- ;
            res = min(res,cal(a[x],b[i],c[y]));
            if(x > 0)
                res = min(res,cal(a[x - 1],b[i],c[y]));
            if(y > 0)
                res = min(res,cal(a[x],b[i],c[y - 1]));
        }
        for(int i = 0; i < k; i ++)
        {
            int x = lower_bound(a,a + n,c[i]) - a;
            int y = lower_bound(b,b + m,c[i]) - b;
            if(x == n)
                x -- ;
            if(y == m)
                y -- ;
            res = min(res,cal(a[x],b[y],c[i]));
            if(x > 0)
                res = min(res,cal(a[x - 1],b[y],c[i]));
            if(y > 0)
                res = min(res,cal(a[x],b[y - 1],c[i]));
        }
        printf("%lld\n",res);
    }
    return 0;
}

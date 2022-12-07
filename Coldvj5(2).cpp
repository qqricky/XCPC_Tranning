#include <bits/stdc++.h>
using namespace std;
int n,m,q,u,v,gap,del,a[100001],b[4][7000001],h[4],t[4];
int read(){    
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
    return x;
} 
int main()
{
    n=read();m=read();q=read();u=read();v=read();gap=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[1][n-i+1]=a[i];
    h[1]=h[2]=h[3]=1;t[1]=n;t[2]=0;t[3]=0;del=0;
    for(int i=1;i<=m;i++) {
        int ans=-2000000000,num=0;
        for (int j=1;j<=3;j++)
            if (h[j]<=t[j] && b[j][h[j]]>ans) ans=b[j][h[j]],num=j;
        if(i%gap==0) printf("%d ",ans+del);
        h[num]++;
        b[2][++t[2]]=(long long)(ans+del)*u/v-del-q;
        b[3][++t[3]]=ans+del-(long long)(ans+del)*u/v-del-q;
        del=del+q;
    }
    cout<<"\n";
    for(int i=1;i<=n+m;i++) {
        int ans=-0x3f3f3f3f,num=0;
        for (int j=1;j<=3;j++)
            if (h[j]<=t[j] && b[j][h[j]]>ans) ans=b[j][h[j]],num=j;
            if(i%gap==0) printf("%d ",ans+del);
            h[num]++;
    }
    //system("pause");
    return 0;
}
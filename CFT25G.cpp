#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=101;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int dd[N],ds[N],qu[N];
char str0[N],str1[N],str2[N];

int sub(int* dd,int* ds,int len1,int len2)
{
    int i;
    if (len1<len2)  return -1;
    else if (len1==len2)
        for (i=len1-1;i>=0;i--)
        {
            if (dd[i]<ds[i])
                    return -1;
            else if (dd[i]>ds[i])
                break;
        }
    for (i=0;i<len1;i++)
    {
        dd[i]-=ds[i];
        if (dd[i]<0)
        {
            dd[i]+=10;
            dd[i+1]--;
        }
    }
    for (i=len1-1;i>=0;i--)
        if (dd[i])  break;
    return i+1;
}
 
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int i,j,k;
        cin>>str0>>str1>>str2;
        int len0=strlen(str0),len1=strlen(str1),len2=strlen(str2);
        for (k=0,i=len1-1;i>=0;i--)
            dd[k++]=str1[i]-'0';
        for (k=0,i=len2-1;i>=0;i--)
            ds[k++]=str2[i]-'0';
        len1=sub(dd,ds,len1,len2);
        if (len1==-1)
        {
            printf("0\n");
            return 0;
        }
        else if (len1==0)
        {
            printf("1\n");
            return 0;
        }
        qu[0]=1;
        int times=len1-len2;
        for (i=len1-1;i>=0;i--)
        {
            if (i>=times)
                ds[i]=ds[i-times];
            else
                ds[i]=0;
        }
        len2=len1;
        for (j=0;j<=times;j++)
        {
            int tmp;
            while ((tmp=sub(dd,ds+j,len1,len2-j))>=0)
            {
                len1=tmp;
                qu[times-j]++;
            }
        }
        for (i=0;i<N;i++)
        {
            if (qu[i]>9)
            {
                qu[i+1]+=qu[i]/10; 
                qu[i]%=10;
            }       
        }
        for (i=N-1;qu[i]==0&&i>=0;i--);
        while (i>=0)
            printf("%d",qu[i--]);
        cout<<'\n';
        cout.flush();
        system("pause");
        return 0;
    }
    return 0;
}
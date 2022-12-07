#include<iostream>
#include<math.h>
using namespace std;
const int e=1e6+10; 
int prime[e];
int b[e];
int f[e];
int main()
{
    for(int i=2;i<=e;i++)
    {
        if(!b[i])
        {
            prime[++prime[0]]=i;
            b[i]=i;
        }
        for(int j=1;j<=prime[0]&&prime[j]<=i&&prime[j]<=e/i;j++)
        {
            b[prime[j]*i]=prime[j];
        }
    }
    int sum=0;
    for(int i=2;i<=e;i++)
    {
        if(b[i]==i)
        {
            int k=i,tmp=0;
            while(k)
            {
                tmp+=k%10;
                k/=10;
            }
            if(b[tmp]==tmp)
            {
                sum++;
            }
        }
        f[i]=sum;
    }
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int a,c;
        cin>>a>>c;
        printf("Case #%d: %d\n", j, f[c] - f[a-1]);
    }
    return 0;
}
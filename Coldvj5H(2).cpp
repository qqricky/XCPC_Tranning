#include<bits/stdc++.h>
using namespace std;
int a[310],d[310][310];
char mp[310][310];
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
        {
            cin>>mp[i];
            for(j=0;j<n;j++)
            {
                if(mp[i][j]=='1')
                d[i][j+1]=1;
                else
                d[i][j+1]=0;
            }
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                if(d[i][k]==1&&d[k][j]==1)	
                d[i][j]=1;
            }	
        }
        int min=0,p=0;
        for(i=1;i<=n;i++)
        {
            p=i;
            for(j=i+1;j<=n;j++)
            {
                if(a[i]>a[j]&&d[i][j]==1)
                swap(a[i],a[j]);	
            }
            
        }
        for(i=1;i<n;i++)
            cout<<a[i]<<' ';
        cout<<a[n];	
	}
	return 0;	
} 
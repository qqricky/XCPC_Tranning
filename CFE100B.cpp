#include <bits/stdc++.h>
using namespace std;
long long a[55]={};
long long b[55]={};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        long long sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=1;i<=n;i++){
            long long base=1;
            while(base<a[i])base<<=1;
            if(base>1e9||a[i]-(base>>1)<base-a[i])base>>=1;
            b[i]=base;
        }
        for(int i=1;i<n;i++)cout<<b[i]<<' ';
        cout<<b[n];
        cout<<endl;
    }
    return 0;
}
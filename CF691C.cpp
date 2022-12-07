#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd(long long x,long long y)
{
    return (y==0)?x:gcd(y,x%y); 
}
long long a[200005]={};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==1){
        long long val;
        cin>>val;
        long long now;
        for(int i=1;i<=m;i++){
            cin>>now;
            cout<<now+val<<' '; 
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long tmp=a[2]-a[1];
    for(int i=3;i<=n;i++){
            tmp=gcd(tmp,a[i]-a[i-1]);
    }
    long long val;
    for(int i=1;i<=m;i++){
        cin>>val;
        long long gc=gcd(val+a[1],tmp);
        cout<<gc<<' ';
    }
    //system("pause");
    return 0;
}
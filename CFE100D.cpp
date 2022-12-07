#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int b[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int minn=0;
        int maxn=0;
        int num=0;
        for(int i=1;i<=n;i++){
            for(int j=b[i]-1;j>b[i-1];j--)num++;
            if(!num)minn++;
            else num--;
        }
        num=0;
        b[n+1]=2*n+1;
        for(int i=n;i>=1;i--){
            for(int j=b[i]+1;j<b[i+1];j++)num++;
            if(!num)maxn++;
            else num--;
        }
        cout<<n-minn-maxn+1<<endl;
    }
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[5070];
int h[5070];
int b[5070];
int pos[5070];
int f[5070][5070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)cin>>a[i];
    int num=0;
    int num1=0;
    for(int i=1;i<=n;i++){
        if(a[i]){
            h[++num]=i;
        }
        else{
            b[++num1]=i;
        }
    }
    for(int i=0;i<=num1;i++){
        f[0][i]=0;
    }
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num1;j++){
            f[i][j]=min(f[i][j-1],f[i-1][j-1]+abs(h[i]-b[j]));
        }
    }
    cout<<f[num][num1];
    //system("pause");
    return 0;
}
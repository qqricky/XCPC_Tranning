#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[2008][2008]={};
int n=2000;
inline void draw(int x,int y)
{
    for(int i=x;i<=n&&y<=n;i++,y++){
        a[i][y]=1;
    }
}
int fib[2004];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt=0;
    fib[1]=2;
    fib[2]=3;
    int k=2;
    int pos;
    int t=1;
    for(int i=n-1;i>=1;i-=k){
        draw(i,1);
        k+=2;
        pos=i-k;
    }
    pos=-pos;
    pos++;
    for(int i=1+pos;i<=n;i+=k){
        draw(1,i);
        k+=2;
    }
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<a[i][j];
            if(a[i][j]==1)cnt++;
            //printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("%d",cnt);
    //cout.flush();
    system("pause");
    return 0;
}
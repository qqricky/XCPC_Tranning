#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
bool num[2*N]={};
int sum[2*N];
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;      
    ch = getchar();             
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        n=read();
        c=read();
        memset(num,0,sizeof(bool)*(c+2));
        sum[0]=0;
        int x;
        for(int i=1;i<=n;i++){
            x=read();
            num[x]=1;
        }
        for(int i=1;i<=c;i++){
            sum[i]=sum[i-1]+num[i];
        }
        bool flag=1;
        for(int i=1;i<=c;i++){
            if(num[i]){
                for(int j=1;j*i<=c;j++){
                    if(!num[j]&&(sum[min(c,i*j+i-1)]-sum[i*j-1]>0)){
                        //cout<<"! "<<i<<' '<<j<<endl;
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag)break;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    cout.flush();
    //system("pause");
    return 0;
}
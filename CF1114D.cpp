#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int ncnt=0;
int f[5050][5050];
int a[5050];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a[0]=0;
    int tmp;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        cin>>tmp;
        if(tmp!=a[ncnt])a[++ncnt]=tmp;
    }
    for(int len=2;len<=ncnt;len++){
        for(int i=1;i+len-1<=ncnt;i++){
            int j=i+len-1;
            if(a[i]==a[j])f[i][j]=min(f[i+1][j-1]+1,f[i][j]);
            f[i][j]=min(f[i][j],min(f[i+1][j]+1,f[i][j-1]+1));
        }
    }
    cout<<f[1][ncnt];
    cout.flush();
    //system("pause");
    return 0;
}
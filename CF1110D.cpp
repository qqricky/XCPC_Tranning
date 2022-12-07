#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int f[N][3][3]={};
int num[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        num[val]++;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(j+k+l>num[i])continue;
                    f[i][k][l]=max(f[i][k][l],f[i-1][j][k]+l+(num[i]-j-k-l)/3);
                }
            }
        }
    }
    cout<<f[m][0][0];
    cout.flush();
    //system("pause");
    return 0;
}
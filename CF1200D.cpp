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
int sum[2070][2070]={};
// void add(int x,int y,int a,int b){
//     sum[a][b]++;
//     sum[x-1][b]--;
//     sum[a][y-1]--;
//     sum[x-1][y-1]++;
// }
int n;
int tree[2070][2070]={};
void add(int x, int y, int z){ 
    int memo_y = y;
    while(x <= n){
        y = memo_y;
        while(y <= n)
            tree[x][y] += z, y += y & -y;
        x += x & -x;
    }
}
void range_add(int xa, int ya, int xb, int yb, int z){
    add(xa, ya, z);
    add(xa, yb + 1, -z);
    add(xb + 1, ya, -z);
    add(xb + 1, yb + 1, z);
}
int ask(int x, int y){
    int res = 0, memo_y = y;
    while(x){
        y = memo_y;
        while(y)
            res += tree[x][y], y -= y & -y;
        x -= x & -x;
    }
    return res;
}
char mp[2070][2070];
int p[2070][2070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int mi=INF,ma=0;
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='B'){
                mi=min(j,mi);
                ma=max(ma,j);
            }
        }
        if(ma!=0){
            if(ma-mi+1>k){
                continue;
            }
            int x=max(i-k+1,1);
            int y=max(ma-k+1,1);
            int a=i;
            int b=mi;
            range_add(x,y,a,b,1);
        }
        else{
            range_add(1,1,n,n,1);
        }
    }
    for(int j=1;j<=n;j++){
        int mi=INF,ma=0;
        for(int i=1;i<=n;i++){
            if(mp[i][j]=='B'){
                mi=min(i,mi);
                ma=max(ma,i);
            }
        }
        if(ma!=0){
            if(ma-mi+1>k)continue;
            int x=max(ma-k+1,1);
            int y=max(j-k+1,1);
            int a=mi;
            int b=j;
            range_add(x,y,a,b,1);
        }
        else{
            range_add(1,1,n,n,1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,ask(i,j));
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}
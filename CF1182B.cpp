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
char mp[505][505];
int a=0,b=0;
bool flag;
bool v[505][505];
int n,m;
bool ck(int x,int y){
    if(x<1||x>n||y<1||y>m)return 0;
    if(v[x][y])return 0;
    if(mp[x][y]!='*')return 0;
    return 1;
}
void find(int x,int y){
    v[x][y]=1;
    if(mp[x][y]=='*'&&mp[x+1][y]=='*'&&mp[x][y+1]=='*'&&mp[x-1][y]=='*'&&mp[x][y-1]=='*'){
        a=x;
        b=y;
        return;
    }
    if(ck(x+1,y)){
        find(x+1,y);
    }
    if(ck(x,y+1)){
        find(x,y+1);
    }
    if(ck(x-1,y)){
        find(x-1,y);
    }
    if(ck(x,y-1)){
        find(x,y-1);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    flag=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            cnt+=(mp[i][j]=='*');
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='*'&&!v[i][j]){
                find(i,j);
            }
        }
    }
    if(a+b){
        int l=a,r=a;
        int up=b,down=b;
        while(mp[a][up]=='*')up++;
        while(mp[a][down]=='*')down--;
        while(mp[l][b]=='*')l--;
        while(mp[r][b]=='*')r++;
        up--;down++;l++;r--;
        cnt-=up-down+r-l+1;
        if(cnt)flag=0;
    }
    else{
        flag=0;
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}
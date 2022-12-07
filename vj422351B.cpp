#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int f[105][105]={};
int cnt=0;
int n,m;
int X,Y;
int ck(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
    else return 0;
}
void goo(int x,int y)
{   
    f[x][y]=1;
    cnt++;
    if(ck(x+1,y)&&!f[x+1][y])goo(x+1,y);
    if(ck(x-1,y)&&!f[x-1][y])goo(x-1,y);
    if(ck(x,y-1)&&!f[x][y-1])goo(x,y-1);
    if(ck(x,y+1)&&!f[x][y+1])goo(x,y+1);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    while(n!=0){
    cnt=0;
    memset(f,0,sizeof(f));
    char ch;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch;
            if(ch=='#')f[i][j]=1;
            else if(ch=='@'){
                X=i;
                Y=j;
            }
        }
    }
    goo(X,Y);
    cout<<cnt<<"\n";
    cin>>m>>n;
    }
    //system("pause");
    return 0;
}
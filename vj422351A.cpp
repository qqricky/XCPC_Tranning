#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int f[105][105]={};
int cnt=0;
int n,m;
int ck(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
    else return 0;
}
void goo(int x,int y)
{   
    f[x][y]=cnt;
    if(ck(x+1,y)&&!f[x+1][y])goo(x+1,y);
    if(ck(x-1,y)&&!f[x-1][y])goo(x-1,y);
    if(ck(x,y-1)&&!f[x][y-1])goo(x,y-1);
    if(ck(x,y+1)&&!f[x][y+1])goo(x,y+1);
    if(ck(x+1,y+1)&&!f[x+1][y+1])goo(x+1,y+1);
    if(ck(x-1,y+1)&&!f[x-1][y+1])goo(x-1,y+1);
    if(ck(x+1,y-1)&&!f[x+1][y-1])goo(x+1,y-1);
    if(ck(x-1,y-1)&&!f[x-1][y-1])goo(x-1,y-1);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    char ch;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch;
            if(ch=='.')f[i][j]=100000;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!f[i][j]){
                cnt++;
                goo(i,j);
            }
        }
    }
    cout<<cnt;
    //system("pause");
    return 0;
}
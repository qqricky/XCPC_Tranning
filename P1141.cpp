#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e3+2;
int a[N][N]={};
long long ans[N][N]={};
int tmp[N*N+N][2]={};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int num=0;
void dfs(int x,int y)
{
    ans[x][y]=1;
    tmp[++num][0]=x;
    tmp[num][1]=y;
    for(int i=0;i<=3;i++){
        int x1=x+dir[i][0];
        int y1=y+dir[i][1];
        if(x1<1||x1>n||y1<1||y1>n)continue;
        if(a[x1][y1]==a[x][y])continue;
        if(ans[x1][y1]>0)continue;
        dfs(x1,y1);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    char ch;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        scanf("%c",&ch);
        a[i][j]=ch-'0';
    }
    for(int i=1;i<=m;i++){
        int cauchy1,cauchy2;
        scanf("%d %d",&cauchy1,&cauchy2);
        if(ans[cauchy1][cauchy2]>0)printf("%d\n",ans[cauchy1][cauchy2]);
        else{
            num=0;
            memset(tmp,0,sizeof(tmp));
            dfs(cauchy1,cauchy2);
            for(int j=1;j<=num;j++){
                ans[tmp[j][0]][tmp[j][1]]=num;
            }
            printf("%d\n",num);
        }
    }
    //system("pause");
    return 0;
}
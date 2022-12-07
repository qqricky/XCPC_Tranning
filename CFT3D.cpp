#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f1[N];
int f2[N];
int find1(int x)
{
    return (x==f1[x]||f1[x]==0) ? x : f1[x]=find1(f1[x]);
}
int find2(int x)
{
    return (x==f2[x]||f2[x]==0) ? x : f2[x]=find2(f2[x]);
}
vector<int>od;
vector<int>id;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)f1[i]=f2[i]=i;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        if(x==s){
            int z=find1(y);
            if(z==0){
                f2[z]=s;
            }
            else f2[x]=f2[y]=s;
        }
        else if(y==s){
            int g=find2(x);
            if(g==0){
                f1[g]=s;
            }
            f1[x]=f1[y]=s;
        }
        else{
            int d=find1(y);
            int q=find2(y);
            int a=find1(x);
            int b=find2(x);
            if(d==x){
                f1[q]=f2[q]=0;
            }
            else{
                f1[x]=d;
                f2[y]=b;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(find1(i)!=s)cnt++;
        if(find2(i)!=s)cnt++;
    }
    cout<<cnt<<endl;
    //system("pause");
    return 0;
}
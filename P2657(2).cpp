#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int f[12][12]={};
void prework()
{
    for(int i=0;i<=9;i++)f[1][i]=1;
    for(int i=2;i<=10;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(abs(j-k)>=2){
                    f[i][j]+=f[i-1][k];
                }
            }
        }
    }
}
ll goo(int x)
{
    int pos=0;
    int dic[12]={};
    while(x)
    {
        dic[++pos]=x%10;
        x/=10;
    }
    ll ans=0;
    for(int i=1;i<=pos-1;i++){
        for(int j=1;j<=9;j++){
            ans+=f[i][j];
        }
    }
    for(int j=1;j<dic[pos];j++)ans+=f[pos][j];
    for(int i=pos-1;i>=1;i--){
        for(int j=0;j<=dic[i]-1;j++){
            if(abs(dic[i+1]-j)>=2)ans+=f[i][j];
        }
        if(abs(dic[i+1]-dic[i])<2)break;
    }
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prework();
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    cout<<goo(b+1)-goo(a);
    //system("pause");
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[6]={};
int n;
int ck(int x,int b,int c,int d)
{
    int y[5];
    for(int i=1;i<=4;i++)y[i]=a[i];
    if(x){
        y[1]--;
        y[2]--;
    }
    if(b){
        y[2]--;
        y[3]--;
    }
    if(c){
        y[3]--;
        y[4]--;
    }
    if(d){
        y[4]--;
        y[1]--;
    }
    for(int i=1;i<=4;i++){
        if(y[i]<0||y[i]>n-2)return 0;
    }
    return 1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int flag=0;
        for(int i=1;i<=4;i++)cin>>a[i];
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=1;k++){
                    for(int l=0;l<=1;l++){
                        if(ck(i,j,k,l))flag=1;
                    }
                }
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}
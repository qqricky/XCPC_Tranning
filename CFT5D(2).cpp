#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int cha(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    int x2,y2;
    cin>>x>>y>>x2>>y2;
    int a,b;
    int t;
    cin>>t;
    if(x>x2){
        swap(x,x2);
        swap(y,y2);
    }
    int flag=0;
    double aa;
    if(x==x2)flag=1;
    else aa=(double)(y2-y)/(x2-x);
    while(t--)
    {
        cin>>a>>b;
        if(a<x||a>x2){
            cout<<"No"<<endl;
            continue;
        }
        if(flag){
            if(b<=max(y,y2)&&b>=min(y,y2))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        double bb=(double)(b-y)/(double)(a-x);
        if(aa!=bb)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    
    //system("pause");
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
int f[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[8];
    ll sum=0;
    for(int i=1;i<=6;i++){cin>>a[i];sum+=i*a[i];}
    int casenum=0;
    while(sum)
    {
        cout<<"Collection #"<<++casenum<<":"<<endl;
        if(sum&1){cout<<"Can't be divided."<<endl;goto paris;}
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=6;i++){
            ll acu=1;
            ll pos=0;
            for(ll j=1;acu<=a[i];acu+=j){
                for(int k=sum/2;k>=i*j;k--){
                    f[k]|=f[k-i*j];
                }
                j<<=1;
                pos=j;
            }
            if(pos==0||(acu-pos)==a[i])continue;
            acu-=pos;
            for(int k=sum/2;k>=i*(a[i]-acu);k--){
                f[k]|=f[k-i*(a[i]-acu)];
            }
        }
        if(f[sum/2])cout<<"Can be divided."<<endl;
        else cout<<"Can't be divided."<<endl;
        paris:;
        cout<<endl;
        sum=0;
        for(int i=1;i<=6;i++){cin>>a[i];sum+=i*a[i];}
    }
    //system("pause");
    return 0;
}
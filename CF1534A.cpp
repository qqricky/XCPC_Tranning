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
char a[101][101]={};
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
        int n,m;
        cin>>n>>m;
        bool f1=1,f2=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n&&f1;i++){
            for(int j=1;j<=m;j++){
                if((i+j)&1){
                    if(a[i][j]=='R'){
                        f1=0;
                        break;
                    }
                }
                else{
                    if(a[i][j]=='W'){
                        f1=0;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n&&f2;i++){
            for(int j=1;j<=m;j++){
                if((i+j)&1){
                    if(a[i][j]=='W'){
                        f2=0;
                        break;
                    }
                }
                else{
                    if(a[i][j]=='R'){
                        f2=0;
                        break;
                    }
                }
            }
        }
        if(f1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if((i+j)&1){
                        a[i][j]='W';
                    }
                    else{
                        a[i][j]='R';
                    }
                }
            }
        }
        else if(f2){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if((i+j)&1){
                        a[i][j]='R';
                    }
                    else{
                        a[i][j]='W';
                    }
                }
            }
        }
        if(f1||f2){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}
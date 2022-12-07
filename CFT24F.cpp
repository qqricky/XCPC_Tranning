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
char mp[4][1070];
int w,a,b;
void init(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=w;j++){
            mp[i][j]='.';
        }
    }
    mp[2][1]='X';
    mp[1][a]='A';
    mp[3][b]='B';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>w>>a>>b;
    init();
    bool flag=0;
    int dis=abs(a-b)-1;
    if(a>b){
        if((dis&1)&&b!=1&&dis>=3){
            flag=1;
            mp[3][b-1]='*';
            for(int j=b;j<=b+dis/2-1;j++){
                mp[2][j]='*';
            }
        }
        else if(dis==1&&b!=1&&b!=2){
            flag=1;
            mp[3][b-1]='*';
            mp[2][b-1]='*';
        }
    }
    else if(a<b){
        if((dis&1)&&a!=1&&dis>=3){
            flag=1;
            mp[1][a-1]='*';
            for(int j=a;j<=a+dis/2-1;j++){
                mp[2][j]='*';
            }
        }
        else if(dis==1&&a!=1&&a!=2){
            flag=1;
            mp[1][a-1]='*';
            mp[2][a-1]='*';
        }
    }
    else{
        flag=1;
    }
    if(flag){
        cout<<"Possible\n";
        for(int i=1;i<=3;i++){
            for(int j=1;j<=w;j++){
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
    }
    else{
        cout<<"Impossible";
    }
    cout.flush();
    //system("pause");
    return 0;
}
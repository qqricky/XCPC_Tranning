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
int mp[11][11];
int mp2[11][11];
int mp3[11][11];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,m;
    cin>>n>>m;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            mp2[i][j]=mp[i][j];
            mp3[i][j]=mp[i][j];
        }
    }
    int x=1,y=1;
    if(mp[x][y]==2){
        cnt1++;
    }
    mp[x][y]=8;
    for(int i=1;i<=2;i++){
        x=1,y=1;
        for(int j=1;j<=18;j++){
            int val;
            cin>>t>>val;
            if(val==1)y++;
            else x++;
            if(mp[x][y]==2){
                cnt1++;
            }
            mp[x][y]=8;
        }
    }
    x=1,y=1;
    if(mp2[x][y]==2){
        cnt2++;
    }
    mp2[x][y]=8;
    for(int i=1;i<=2;i++){
        x=1,y=1;
        for(int j=1;j<=18;j++){
            int val;
            cin>>t>>val;
            if(val==1)y++;
            else x++;
            if(mp2[x][y]==2){
                cnt2++;
            }
            mp2[x][y]=8;
        }
    }
    cout<<cnt1<<' '<<cnt2<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mp[i][j]<<' ';
        }
        cout<<"    ";
        for(int j=1;j<=n;j++){
            cout<<mp2[i][j]<<' ';
        }
        cout<<"    ";
        for(int j=1;j<=n;j++){
            cout<<mp3[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}
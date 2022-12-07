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
int mp[1070][1070]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    ll ans=n*m;
    for(int i=1;i<=n;i++){
        ll cnt=0;
        int xx=i,yy=1;
        int num=1;
        while(xx<=n&&yy<=m){
            cnt++;
            if(num&1)xx++;
            else yy++;
            num++;
        }
        ans+=cnt*(cnt-1)/2;
    }
    for(int j=1;j<=m;j++){
        ll cnt=0;
        int xx=1,yy=j;
        int num=0;
        while(xx<=n&&yy<=m){
            cnt++;
            if(num&1)xx++;
            else yy++;
            num++;
        }
        ans+=cnt*(cnt-1)/2;
    }
    //cout<<ans<<endl;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        bool tmp=mp[x][y]^1;
        int flag;
        if(tmp)flag=-1;
        else flag=1;
        mp[x][y]=0;
        ll cnt0=0,cnt1=0;
        int xx=x,yy=y;
        int num=0;
        while(xx>=1&&yy>=1){
            if(mp[xx][yy])break;
            cnt0++;
            if(num&1)xx--;
            else yy--;
            num++;
        }
        xx=x,yy=y;
        num=1;
        while(xx<=n&&yy<=m){
            if(mp[xx][yy])break;
            cnt1++;
            if(num&1)xx++;
            else yy++;
            num++;
        }
        ans+=flag*cnt0*cnt1;
        //cout<<'Q'<<cnt0<<' '<<cnt1<<endl;
        xx=x,yy=y;
        num=1;
        cnt0=0,cnt1=0;
        while(xx>=1&&yy>=1){
            if(mp[xx][yy])break;
            cnt0++;
            if(num&1)xx--;
            else yy--;
            num++;
        }
        xx=x,yy=y;
        num=0;
        while(xx<=n&&yy<=m){
            if(mp[xx][yy])break;
            cnt1++;
            if(num&1)xx++;
            else yy++;
            num++;
        }
        ans+=flag*cnt0*cnt1;
        ans-=flag;
        cout<<ans<<'\n';
        mp[x][y]^=tmp;
    }
    cout.flush();
    //system("pause");
    return 0;
}
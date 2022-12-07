#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node
{
    int x,y;
}nd[N];
int dx,dy;
int n;
bool ck(int x,int y){
    for(int i=1;i<=n;i++){
        int a=nd[i].x-x;
        int b=nd[i].y-y;
        bool can=0;
        if(nd[i].x==x&&nd[i].y>=y){
            can=1;
        }
        if(nd[i].x>x){
            if(nd[i].y==y)can=1;
            if(abs(b)==abs(a))can=1;
        }
        if(!can)return 0;
    }
    return 1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    srand(time(0));
    srand(rand());
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        srand(rand());
        cin>>n;
        dx=INF,dy=INF;
        if(n<=2){
            cout<<"YES\n";
            continue;
        }
        int mix=INF;
        int toy=INF;
        for(int i=1;i<=n;i++){
            cin>>nd[i].x>>nd[i].y;
            if(nd[i].x<mix){
                mix=nd[i].x;
                toy=nd[i].y;
            }else if(nd[i].x==mix){
                toy=min(toy,nd[i].y);
            }
            // if(nd[i].x<mix){
            //     mix=nd[i].x;
            //     toy=nd[i].y;
            // }else if(nd[i].x==mix){
            //     toy=max(toy,nd[i].y);
            // }
            // if(nd[i].y<miy){
            //     miy=nd[i].y;
            //     tox=nd[i].x;
            // }else if(nd[i].y==miy){
            //     tox=max(tox,nd[i].x);
            // }
            // // mix=min(mix,nd[i].x);
            // // miy=min(miy,nd[i].y);
            // if(nd[i].y<dy){
            //     dy=nd[i].y;
            //     dx=nd[i].x;
            // }else if(nd[i].y==dy){
            //     dx=max(dx,nd[i].x);
            // }
        }
        bool flag=0;
        int xx=mix,yy=toy;
        for(int i=1;i<=100;i++){
            int pos=rand()%n+1;
            int x=nd[pos].x,y=nd[pos].y;
            if(!ck(min(xx,x),min(yy,y))){
                flag=0;
                break;
            }
            int mix,miy;
            int tox,toxy,toy,toyx;
            if(x<xx){
                mix=x;
                tox=xx;
                toxy=yy;
            }else{
                mix=xx;
                tox=x;
                toxy=y;
            }
            if(y<yy){
                miy=y;
                toy=yy;
                toyx=xx;
            }else{
                miy=yy;
                toy=y;
                toyx=x;
            }
            int tmpx,tmpy;
            tmpx=mix;
            tmpy=toxy-(tox-mix);
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
            tmpx=mix;
            tmpy=toxy+(tox-mix);
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
            tmpx=toyx-(toy-miy);
            tmpy=miy;
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
            if(y<yy){
                tmpy=yy;
                tmpx=x-(yy-y);
            }else{
                tmpy=y;
                tmpx=xx-(y-yy);
            }
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
            tmpx=(x+xx+y-yy)/2;
            tmpy=y+x-tmpx;
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
            tmpx=(x+xx+yy-y)/2;
            tmpy=yy+xx-tmpx;
            if(ck(tmpx,tmpy)){
                flag=1;
                break;
            }
        }// if(ck(mix,miy)){
        //     cout<<"YES\n";
        //     continue;
        // }
        // if(ck(mix,miy-(tox-mix))){
        //     cout<<"YES\n";
        //     continue;
        // }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    system("pause");
    return 0;
}
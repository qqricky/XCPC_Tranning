#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
struct num{
    int x;
    int r;
}a[N];
bool cmp(num a,num b)
{
    if(a.x==b.x){
        return a.r<b.r;
    }
    return a.x<b.x;
}
struct pr{
    int x;
    int y;
};
map <int,pr>dis;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].r=i;
    }
    int x1,x2,y1,y2;
    sort(a+1,a+n+1,cmp);
    int flag=0;
    int ans=0;
    for(int j=1;j<=n;j++){
        for(int i=j+1;i<=n;i++){
            if(dis.count(a[i].x+a[j].x)==1){
                if(a[j].r!=dis[a[i].x+a[j].x].y&&a[j].r!=dis[a[i].x+a[j].x].x&&a[i].r!=dis[a[i].x+a[j].x].x&&a[i].r!=dis[a[i].x+a[j].x].y){
                    x1=dis[a[i].x+a[j].x].x;
                    y1=dis[a[i].x+a[j].x].y;
                    x2=a[j].r;
                    y2=a[i].r;
                    flag=1; 
                    //cout<<a[i].x+a[j].x<<endl;
                    break;
                }
            }
            else{
                dis[a[i].x+a[j].x].x=a[j].r;
                dis[a[i].x+a[j].x].y=a[i].r;
            }
        }
        if(flag)break;
    }
    if(!flag)cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
struct person
{
    int x,y;
    int num;
     friend bool operator >(person a,person b)
     {
         return a.y<b.y;
     }
}a[N];
int f[N];
int b[N];
bool cmp1(person a1,person a2)
{
    if(a1.x==a2.x)return a1.y<a2.y;
    else return a1.x<a2.x;
}
// bool cmp2(person a1,person a2)
// {
//     return a1.y>a2.y;
// }
int main()
{
    //  freopen("TestCase.in","r",stdin);
    //  freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int xx,yy;
    while(t--)
    {
        memset(f,0,sizeof(f));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>xx>>yy;
            if(xx<yy)swap(xx,yy);
            a[i].num=i;
            a[i].x=xx;
            a[i].y=yy;
        }
        sort(a+1,a+n+1,cmp1);
        // for(int i=1;i<=n;i++){
        //     b[i]=a[i].y;
        //     //cout<<b[i]<<' ';
        // }
        // cout<<endl;
        // a[n+1].num=-1;
        // a[n+1].x=-1;
        int minn=2147483646;
        int pos=-1;
        int j=1;
        for(int i=1;i<=n;i++){
            while(a[j].x<a[i].x){
                if(a[j].y<minn){
                    minn=a[j].y;
                    pos=a[j].num;
                }
                j++;
            }
            f[a[i].num]= a[i].y>minn ? pos : -1;
        }
        // for(int i=1;i<=n;i++){
        //     int k=i+1;
        //     while(a[k].x==a[i].x)k++;
        //     //cout<<a[i].num<<endl;
        //     int pos=upper_bound(b+k,b+n+1,a[i].y,greater<int>())-b;
        //     //cout<<a[i].y<<'Q'<<b[pos]<<endl;
        //     //cout<<a[i].num<<'Q'<<pos<<endl;
        //     //cout<<i<<' '<<k<<endl;
        //     f[a[i].num]=a[pos].num;
        //     //cout<<i<<'Q'<<pos<<endl;
        // }
        for(int i=1;i<=n;i++)cout<<f[i]<<' ';
        cout<<"\n";
        //cout<<0x3f3f3f;
    }
    //system("pause");
}
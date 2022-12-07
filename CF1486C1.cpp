#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
map<pair<int,int>,int>a;
int ask(int l,int r)
{
    if(a[make_pair(l,r)]!=0)return a[make_pair(l,r)];
    cout<<"? "<<l<<' '<<r<<"\n";
    cout.flush();
    int tmp;
    cin>>tmp;
    a[make_pair(l,r)]=tmp;
    return tmp;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    int l=1,r=n;
    while(l+1<r)
    {
        int mid=(l+r)>>1;
        int x=ask(l,mid);
        int y=ask(mid,r);
        int k=ask(l,r);
        if(k==x||k==y)
        {
            if(k==x)r=mid;
            else l=mid;
        }
        else
        {
            if(k>=mid)r=mid;
            else l=mid;
        }
    }
    if(ask(l,r)==l)cout<<"! "<<r;
    else cout<<"! "<<l;
    //system("pause");
    return 0;
}
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
    int mid=(l+r)>>1;
    int k=ask(l,r);
    int pos=r;
    while(ask(l,k)==k)
    {
        r/=2;
        k=ask(l,r);
    }
    
    if(ask(l,r)==l)cout<<"! "<<r;
    else cout<<"! "<<l;
    //system("pause");
    return 0;
}
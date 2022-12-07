#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int ck(int x)
{
    cout<<'Q'<<' '<<x<<"\n";
    cout.flush();
    char ch;
    cin>>ch;
    if(ch=='>')return 1;
    else if(ch=='<')return 0;
    else return 2;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r=1000000001;
    int l=0;
    int mid;
    int k;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        k=ck(mid);
        if(k==2){
            break;
        }
        if(k)l=mid;
        else r=mid;
    }
    //system("pause");
    return 0;
}
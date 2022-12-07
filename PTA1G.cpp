#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

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
        int h,w;
        cin>>h>>w;
        double d=(double)(h-100)*1.8;
        if(fabs((double)w-d)<0.1*d)cout<<"You are wan mei!"<<endl;
        else if(w>d)cout<<"You are tai pang le!"<<endl;
        else cout<<"You are tai shou le!"<<endl;

    }
    //system("pause");
    return 0;
}
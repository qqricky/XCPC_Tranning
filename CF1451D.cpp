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
        ll d,k;
        cin>>d>>k;
        ll x=1;
        while(k*k*(2*x*x)<=d*d){
            x++;
        }
        x--;
        if(k*k*(2*x*x+2*x+1)<=d*d){
            cout<<"Ashish"<<endl;
        }
        else{
            cout<<"Utkarsh"<<endl;
        }
    }
    //system("pause");
    return 0;
}
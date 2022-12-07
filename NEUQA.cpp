#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;

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
        ll n;
        cin>>n;
        int flag=0;
        for(int i=2;i<=15;i++){
            if(n%((1<<i)-1)==0){
                flag=1;
                break;
            }
        }
        if(flag)cout<<"YE5"<<endl;
        else cout<<"N0"<<endl;
    }
    //system("pause");
}
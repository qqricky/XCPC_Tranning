#include <bits/stdc++.h>
#define ll long long
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
        int n,k;
        cin>>n>>k;
        if(n%2==0){
            if(k%n==0)cout<<n<<endl;
            else cout<<k%n<<endl;
        }
        else{
            if(k<(n+1)/2){
                cout<<k<<endl;
                continue;
            }
            int t=n/2;
            k+=(k-1)/t;
            if(k%n==0)cout<<n<<endl;
            else cout<<k%n<<endl;
        }
    }
    //system("pause");
    return 0;
}
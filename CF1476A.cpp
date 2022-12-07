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
        if(n<=k){
            if(k%n==0)cout<<k/n<<endl;
            else cout<<k/n+1<<endl;
        }
        else{
            k=n/k*k+(n%k>0)*k;
            if(k%n==0)cout<<k/n<<endl;
            else cout<<k/n+1<<endl;
        }
    }
    //system("pause");
    return 0;
}
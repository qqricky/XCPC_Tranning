#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int flag=1;
int solve(int n)
{
    if(n%2==0)return n/2;
    else{
        int f=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int k=n/i;
                f=0;
                return k*solve(i);
            }
        }
        if(f)return 1;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int op=solve(n);
    cout<<op<<' '<<n-op;
    //system("pause");
    return 0;
}
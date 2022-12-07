#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll sum=0;
        ll ans=0;
        ll tmp;
        int minn=21487123;
        ll last_sum=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            int tmp2=tmp;
            int num=0;
            while(!(tmp%x)){
                tmp/=x;
                num++;
            }
            if(num<minn){
                minn=num;
                last_sum=sum;
            }
            sum+=tmp2;
        }
        cout<<sum*(minn+1)+last_sum<<endl;
    }
    //system("pause");
    return 0;
}